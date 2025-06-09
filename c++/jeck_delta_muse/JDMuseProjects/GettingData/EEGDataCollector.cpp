#include "pch.h"
#include "EEGDataCollector.h"

using namespace interaxon::bridge;

EEGDataCollector::EEGDataCollector() {}

EEGDataCollector::~EEGDataCollector() {}

void update_eeg(double* target_array, const std::shared_ptr<MuseDataPacket>& packet) {
    target_array[0] = packet->get_eeg_channel_value(Eeg::EEG1);
    target_array[1] = packet->get_eeg_channel_value(Eeg::EEG2);
    target_array[2] = packet->get_eeg_channel_value(Eeg::EEG3);
    target_array[3] = packet->get_eeg_channel_value(Eeg::EEG4);
    target_array[4] = packet->get_eeg_channel_value(Eeg::AUX_LEFT);
    target_array[5] = packet->get_eeg_channel_value(Eeg::AUX_RIGHT);
}

void update_band(double* target_array, const std::shared_ptr<MuseDataPacket>& packet)
{
    target_array[0] = packet->get_eeg_channel_value(Eeg::EEG1);
    target_array[1] = packet->get_eeg_channel_value(Eeg::EEG2);
    target_array[2] = packet->get_eeg_channel_value(Eeg::EEG3);
    target_array[3] = packet->get_eeg_channel_value(Eeg::EEG4);
}

void update_optics(double* target_array, const std::shared_ptr<MuseDataPacket>& packet)
{
    target_array[0] = packet->get_optics_channel_value(Optics::OPTICS1);
    target_array[1] = packet->get_optics_channel_value(Optics::OPTICS2);
    target_array[2] = packet->get_optics_channel_value(Optics::OPTICS3);
    target_array[3] = packet->get_optics_channel_value(Optics::OPTICS4);
}

void EEGDataCollector::receive_muse_data_packet(const std::shared_ptr<MuseDataPacket>& packet,
    const std::shared_ptr<Muse>& muse)
{
    std::lock_guard<std::mutex> lock(state_mutex_);

    auto type = packet->packet_type();

    if (type == MuseDataPacketType::EEG) {
        update_eeg(eeg_state_.eeg_channels, packet);
    }
    else if (type == MuseDataPacketType::OPTICS) {
        update_optics(eeg_state_.optics, packet);
    }
    else if (auto* target_array = get_band_array(type)) {
        update_band(target_array, packet);
    }
    // Update timestamp
    eeg_state_.timestamp = static_cast<uint64_t>(
        std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count());
}


double* EEGDataCollector::get_band_array(interaxon::bridge::MuseDataPacketType type)
{
    switch (type) {
    case MuseDataPacketType::ALPHA_ABSOLUTE: return eeg_state_.alpha;
    case MuseDataPacketType::BETA_ABSOLUTE:  return eeg_state_.beta;
    case MuseDataPacketType::THETA_ABSOLUTE: return eeg_state_.theta;
    case MuseDataPacketType::DELTA_ABSOLUTE: return eeg_state_.delta;
    case MuseDataPacketType::GAMMA_ABSOLUTE: return eeg_state_.gamma;
    default: return nullptr;
    }
}

void EEGDataCollector::receive_muse_artifact_packet(const MuseArtifactPacket& packet,
    const std::shared_ptr<Muse>& muse)
{
    std::lock_guard<std::mutex> lock(state_mutex_);

    eeg_state_.headband_on = packet.headband_on;
    eeg_state_.blink = packet.blink;
    eeg_state_.jaw_clench = packet.jaw_clench;

    OutputDebugString(L"Artifact packet received: headband_on=");
    OutputDebugString(packet.headband_on ? L"true\n" : L"false\n");

    eeg_state_.timestamp = static_cast<uint64_t>(
        std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count());
}

EEGState EEGDataCollector::get_current_state()
{
    std::lock_guard<std::mutex> lock(state_mutex_);
    return eeg_state_;
}
