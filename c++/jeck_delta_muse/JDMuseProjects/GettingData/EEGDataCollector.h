#pragma once

#include "muse.h"
#include <memory>
#include <mutex>
#include <chrono>

struct EEGState {
    double eeg_channels[6] = { 0 };      // EEG1, EEG2, EEG3, EEG4, AUX_LEFT, AUX_RIGHT
    double alpha[4] = { 0 };             // ALPHA_ABSOLUTE (EEG1-4)
    double beta[4] = { 0 };
    double theta[4] = { 0 };
    double delta[4] = { 0 };
    double gamma[4] = { 0 };
    double optics[4] = { 0 };            // OPTICS1-4
    bool headband_on = false;
    bool blink = false;
    bool jaw_clench = false;
    uint64_t timestamp = 0;
};

class EEGDataCollector : public interaxon::bridge::MuseDataListener
{
public:
    EEGDataCollector();
    ~EEGDataCollector();

    // Called from MuseDataListener callback
    void receive_muse_data_packet(const std::shared_ptr<interaxon::bridge::MuseDataPacket>& packet,
        const std::shared_ptr<interaxon::bridge::Muse>& muse);

    // Called from Artifact callback
    void receive_muse_artifact_packet(const interaxon::bridge::MuseArtifactPacket& packet,
        const std::shared_ptr<interaxon::bridge::Muse>& muse);

    // Thread-safe getter
    EEGState get_current_state();

    double* EEGDataCollector::get_band_array(interaxon::bridge::MuseDataPacketType type);

private:
    EEGState eeg_state_;
    std::mutex state_mutex_;
};
