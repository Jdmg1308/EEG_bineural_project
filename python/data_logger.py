import csv
import os
import asyncio
from datetime import datetime

class DataLogger:
    def __init__(self, log_file="data/eeg_audio_log.csv"):
        """Initializes the data logger with a given log file."""
        self.log_file = log_file
        self.data_queue = asyncio.Queue()

        log_dir = os.path.dirname(self.log_file)
        if log_dir and not os.path.exists(log_dir):
            os.makedirs(log_dir)

        if not os.path.exists(self.log_file):
            with open(self.log_file, mode="w", newline="") as file:
                writer = csv.writer(file)
                writer.writerow(["Timestamp", "Delta_Power", "Phase_Shift", "Frequency"])

    def log_data(self, delta_power, phase_shift, frequency):
        """Logs data to the CSV file."""
        timestamp = datetime.now().strftime("%H:%M:%S") 
        with open(self.log_file, mode="a", newline="") as file:
            writer = csv.writer(file)
            writer.writerow([timestamp, str(delta_power), phase_shift, frequency])
        print(f" Logged: {timestamp}, Δ: {delta_power}, Phase: {phase_shift:.2f}°, Freq: {frequency:.2f} Hz")

    async def start(self):
        """Continuously processes data from the queue for logging."""
        while True:
            delta_power, phase_shift, frequency = await self.data_queue.get()
            self.log_data(delta_power, phase_shift, frequency)  # Process immediately

    async def log_async(self, delta_power, phase_shift, frequency):
        """Adds data to the queue for logging asynchronously."""
        await self.data_queue.put((delta_power, phase_shift, frequency))