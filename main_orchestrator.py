import asyncio
import threading
from eeg_collector import EEGCollector
from audio_processor import AudioProcessor
from data_logger import DataLogger
from rl_agent import BrainwaveRLAgent

class MainOrchestrator:
    def __init__(self):
        self.eeg_collector = EEGCollector()
        self.data_logger = DataLogger()  
        self.rl_agent = BrainwaveRLAgent()
        self.running = True
        self.loop = asyncio.new_event_loop()

    async def get_brainwave_data(self):
        data = await self.eeg_collector.get_latest_metrics()
        return data

    async def run(self):
        """Starts EEG collection and logs data without modifying audio."""
        print("🚀 EEG Logger started!")
        asyncio.create_task(self.eeg_collector.start())
        asyncio.create_task(self.data_logger.start())

        try:
            while self.running:
                data = await self.get_brainwave_data()
                if data:
                    await self.data_logger.log_async(data, 0, 0)  # Log only EEG delta
                await asyncio.sleep(1)  
        except asyncio.CancelledError:
            print("🛑 EEG Logger stopped.")
        finally:
            await self.eeg_collector.stop()
    
    async def og_run(self):
        """Starts EEG collection and continuous audio playback."""
        print("🚀 MainOrchestrator started!")
        asyncio.create_task(self.eeg_collector.start())

        # Start data logging task
        print("✅ Starting EEG and Audio Processing...")
        asyncio.create_task(self.data_logger.start())

        print("🔄 Scheduling continuous_audio_loop...")
        # Start continuous audio processing
        asyncio.create_task(self.audio_processor.continuous_audio_loop(self.get_brainwave_data, self.rl_agent))

        try:
            while self.running:
                await asyncio.sleep(1)  # Keep event loop alive
        except asyncio.CancelledError:
            print("🛑 Main orchestrator stopped.")
        finally:
            await self.eeg_collector.stop()

    def stop(self):
        """Gracefully stops all tasks and exits the event loop."""
        print("⚠️ Stopping orchestrator...")
        self.running = False

        # ✅ Ensure all async tasks are stopped properly
        self.loop.call_soon_threadsafe(self.loop.stop)
        self.audio_processor.stream.stop()  # ✅ Stop audio playback
        self.audio_processor.stream.close()
        print("✅ Orchestrator stopped.")

def start_event_loop(loop):
    """Runs the asyncio event loop in a separate thread."""
    asyncio.set_event_loop(loop)
    loop.run_forever()

if __name__ == "__main__":
    orchestrator = MainOrchestrator()

    # Start the event loop in a **dedicated thread**
    loop_thread = threading.Thread(target=start_event_loop, args=(orchestrator.loop,), daemon=True)
    loop_thread.start()

    # Run the orchestrator inside the event loop
    future = asyncio.run_coroutine_threadsafe(orchestrator.run(), orchestrator.loop)

    # Handle KeyboardInterrupt properly
    try:
        future.result()  # Blocks until orchestrator.run() completes
    except KeyboardInterrupt:
        print("\n🛑 KeyboardInterrupt received! Shutting down...")
        orchestrator.stop()
        loop_thread.join()  # Ensure the loop stops properly
        print("✅ System shut down successfully.")
