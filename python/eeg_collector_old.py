import asyncio
import sys
import logging
import platform
import os
import hashlib
from typing import List
from bleak.backends.client import BaseBleakClient
from enterble import FlowtimeCollector
from affectivecloud import ACClient
from affectivecloud.algorithm import BaseServices
from affectivecloud.protocols import Services

if sys.version_info < (3, 7):
    asyncio.get_running_loop = asyncio._get_running_loop

logging.basicConfig(
    level=logging.INFO,
    format="%(levelname)s - %(asctime)s - %(name)s - %(message)s",
)
logger = logging.getLogger(__name__)

class EEGCollector:
    def __init__(self, device_identify=None):
        """Initialize the EEG Collector with Affective Cloud integration."""
        self.model_nbr_uuid = "0000ff10-1212-abcd-1523-785feabcd123"
        self.device_identify = device_identify or self.get_default_device_id()
        self.collector = None
        self.client = None
        self.session_id = None
        self.latest_data = [0]  # Store the latest EEG data

    def get_default_device_id(self):
        """Returns a default device identifier based on the OS."""
        return (
            "C2:25:36:AB:10:D8"
            if platform.system() != "Darwin"
            else "1F59B8E7-2657-BAA2-D07F-D2C42F0914AF"
        )

    async def authenticate(self):
        """Authenticate and create a session with Affective Cloud."""
        self.client = ACClient(
            url="wss://server.affectivecloud.cn/ws/algorithm/v2/",
            app_key=os.environ.get("APP_KEY"),
            secret=os.environ.get("APP_SECRET"),
            client_id=os.environ.get("CLIENT_ID"),
            recv_callbacks={
                Services.Type.SESSION: {
                    Services.Operation.Session.CREATE: self.session_create,
                    Services.Operation.Session.RESTORE: self.session_restore,
                    Services.Operation.Session.CLOSE: self.session_close,
                },
                Services.Type.BASE_SERVICE: {
                    Services.Operation.BaseService.INIT: self.base_service_init,
                    Services.Operation.BaseService.REPORT: self.base_service_report,
                },
            },
        )
        await self.client.connect()
        await self.client.create_session()
    
    async def session_create(self, data):
        """Handle session creation."""
        self.session_id = data.get("session_id", None)
        logger.info(f"Session created: {self.session_id}")
        await self.client.init_base_services(services=[BaseServices.EEG])
    
    async def session_restore(self, data):
        logger.info(f"Session restored: {data}")
    
    async def session_close(self, data):
        logger.info("Session closed.")
    
    async def base_service_init(self, data):
        logger.info("Base service initialized.")
    
    async def base_service_report(self, data):
        logger.info(f"Base service report: {data}")

    async def eeg_data_collector(self, data: List[int]):
        """Handles EEG data collection and uploads it to Affective Cloud."""
        if data and isinstance(data, (list, tuple)):
            self.latest_data = list(data)
            if self.client and self.client.ws and not self.client.ws.closed:
                await self.client.upload_raw_data_from_device({BaseServices.EEG: self.latest_data})
        else:
            logger.warning("Invalid EEG data received!")

    async def start(self):
        """Starts EEG data collection and Affective Cloud session."""
        await self.authenticate()
        
        self.collector = FlowtimeCollector(
            name="Flowtime Headband",
            model_nbr_uuid=self.model_nbr_uuid,
            device_identify=self.device_identify,
            device_disconnected_callback=self.device_disconnected,
            eeg_data_callback=self.eeg_data_collector,
        )
        
        logger.info("Starting EEG Collector...")
        await self.collector.start()
        logger.info("EEG Collector started successfully!")

    async def stop(self):
        """Stops EEG data collection and closes session."""
        if self.collector:
            await self.collector.stop()
            logger.info("EEG Collection stopped.")
        if self.client:
            await self.client.close_session()
            logger.info("Affective Cloud session closed.")

    async def device_disconnected(self, device: BaseBleakClient):
        """Handles device disconnection."""
        logger.info(f"Device disconnected: {device}")

if __name__ == "__main__":
    collector = EEGCollector()
    loop = asyncio.new_event_loop()
    asyncio.set_event_loop(loop)
    try:
        loop.run_until_complete(collector.start())
    except KeyboardInterrupt:
        loop.run_until_complete(collector.stop())
