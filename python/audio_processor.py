import numpy as np
import sounddevice as sd
import soundfile as sf
from scipy.signal import resample
import asyncio
from data_logger import DataLogger

class AudioProcessor:
    def __init__(self, data_logger, audio_path="audio_files\modified_audio.wav", base_frequency=440.0, sample_rate=44100, buffer_size=44100):
        """Handles real-time audio processing with optional file modification."""
        self.data_logger = data_logger
        self.sample_rate = sample_rate
        self.buffer_size = buffer_size
        self.audio_path = audio_path
        self.base_frequency = base_frequency  # Default frequency if generating new audio
        self.next_audio_ready = False
        self.current_frequency = base_frequency  # Track the actual frequency being played

        # Load or generate audio buffer
        if self.audio_path:
            self.load_audio_file(audio_path)
        else:
            self.audio_buffer = np.zeros((buffer_size, 2))

        # Open continuous playback stream
        self.stream = sd.OutputStream(
            samplerate=self.sample_rate,
            channels=2,
            callback=self.audio_callback,
            blocksize=self.buffer_size
        )
        self.stream.start()

    def load_audio_file(self, audio_path):
        """Loads an audio file for modification."""
        y, sr = sf.read(audio_path)
        self.sample_rate = sr
        self.left_channel = y[:, 0]
        self.right_channel = y[:, 1]

        # Estimate the original dominant frequency
        self.base_frequency = self.estimate_frequency(self.right_channel, sr)
        self.current_frequency = self.base_frequency

        # Use the first buffer segment for playback
        self.audio_buffer = np.column_stack((self.left_channel[:self.buffer_size],
                                             self.right_channel[:self.buffer_size]))

    def estimate_frequency(self, signal, sample_rate):
        """Estimates the dominant frequency of the signal."""
        spectrum = np.fft.fft(signal)
        frequencies = np.fft.fftfreq(len(signal), d=1/sample_rate)
        magnitude = np.abs(spectrum)
        peak_index = np.argmax(magnitude[:len(magnitude)//2])  # Ignore negative freqs
        return frequencies[peak_index]

    def audio_callback(self, outdata, frames, time, status):
        """Streams continuous audio, replacing the buffer when ready."""
        if status:
            print(f"Audio callback status: {status}")

        outdata[:] = self.audio_buffer[:frames]  # Play current buffer

        if self.next_audio_ready:
            self.next_audio_ready = False

    def generate_audio(self, phase_shift, frequency_change):
        """Modifies existing audio or generates new audio."""
        #print(f" Generating audio | Phase Shift: {np.degrees(phase_shift):.2f}° | Freq Change: {frequency_change:.2f}")

        # Compute actual frequency being played
        self.current_frequency = self.base_frequency * frequency_change  

        if self.audio_path:
            # Modify existing audio
            left_freq_shifted = self.change_frequency(self.left_channel, frequency_change)
            right_freq_shifted = self.change_frequency(self.right_channel, frequency_change)
            right_phase_shifted = self.phase_shift_signal(right_freq_shifted, phase_shift)

            min_length = min(len(left_freq_shifted), len(right_phase_shifted))
            self.audio_buffer = np.column_stack((left_freq_shifted[:min_length], right_phase_shifted[:min_length]))
        else:
            # Generate new synthetic audio at current_frequency
            left_channel = np.sin(2 * np.pi * np.linspace(0, 1, self.buffer_size) * self.current_frequency)
            right_channel = np.sin(2 * np.pi * np.linspace(0, 1, self.buffer_size) * self.current_frequency + phase_shift)
            self.audio_buffer = np.column_stack((left_channel, right_channel))

        self.next_audio_ready = True

    def change_frequency(self, signal, factor):
        """Changes the frequency of a signal without causing errors."""
        new_length = max(1, int(len(signal) / factor))
        resampled_signal = resample(signal, new_length)

        pad_length = max(0, self.buffer_size - len(resampled_signal))
        return np.pad(resampled_signal, (0, pad_length))[:self.buffer_size]

    def phase_shift_signal(self, signal, shift_amount):
        """Applies a phase shift to a signal."""
        spectrum = np.fft.fft(signal)
        phase = np.angle(spectrum) + shift_amount
        magnitude = np.abs(spectrum)
        shifted_spectrum = magnitude * np.exp(1j * phase)
        return np.real(np.fft.ifft(shifted_spectrum))

    async def continuous_audio_loop(self, brainwave_data_fetcher, rl_agent):
        print("🎵 Starting continuous audio loop...")

        prev_delta_wave = None

        try:
            while True:
                try:
                    delta_wave_change = await asyncio.wait_for(brainwave_data_fetcher(), timeout=5)
                except asyncio.TimeoutError:
                    print("❌ Timeout! EEG data not responding.")
                    continue

                print(f"🧠 Received brainwave data: {delta_wave_change}")

                if not delta_wave_change:
                    print("⚠️ Received empty brainwave data! Sleeping for 1s...")
                    await asyncio.sleep(1)
                    continue

                delta_wave = delta_wave_change[3]

                if delta_wave in [0, 255]:
                    print(f"⚠️ Ignoring invalid brainwave value: {delta_wave}")
                    await asyncio.sleep(1)
                    continue

                reward = rl_agent.calculate_reward(prev_delta_wave, delta_wave)
                rl_agent.update_q_table(prev_delta_wave, delta_wave, phase_shift, frequency_change, reward)
                prev_delta_wave = delta_wave

                phase_shift, frequency_change = rl_agent.choose_action(delta_wave)
                
                print(f"🎵 Modifying audio: Phase Shift {phase_shift}, Freq Change {frequency_change}")
                # Log asynchronously to CSV
                await self.data_logger.log_async(delta_wave, phase_shift, frequency_change)

                self.generate_audio(phase_shift, frequency_change)

                print("⏳ Sleeping for 10s while buffer plays...")
                await asyncio.sleep(10)

        except Exception as e:
            print(f"❌ Error in continuous_audio_loop: {e}")

        except asyncio.CancelledError:
            print("Audio loop stopped.")
        finally:
            self.stream.stop()
            self.stream.close()