// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from listeners.djinni

#pragma once

#include <memory>

namespace interaxon { namespace bridge {

class Muse;
struct MuseConnectionPacket;

/**
 * Implement this interface to listen for changes to the current connection
 * status (like connect/disconnect).
 *
 * <B>Important:</B> DO NOT CALL
 * \inlinelink{Muse.connect(),::IXNMuse::connect(),Muse::connect()}  /
 * \inlinelink{Muse.disconnect(),::IXNMuse::disconnect:,Muse::disconnect()}
 *  directly from a connection listener handler. Either create a new thread and run it from there
 * or use \inlinelink{Muse.runAsynchronously(),::IXNMuse::runAsynchronously(),Muse::run_asynchronously()}
 *  which creates a new thread implicitly.
 */
class MuseConnectionListener {
public:
    virtual ~MuseConnectionListener() {}

    /**
     * Called from the Muse connection thread whenever there is a change in
     * the current connection status of the \classlink{Muse}
     *
     * \warning It is important that you do not perform any computation
     * intensive tasks in this callback. This would result in significant
     * delays in all the listener callbacks from being called. You should
     * delegate any intensive tasks to another thread or schedule it to run
     * with a delay through handler/scheduler for the platform.
     *
     * However, you can register/unregister listeners in this callback.
     * All previously registered listeners would still receive callbacks
     * for this current event. On subsequent events, the newly registered
     * listeners will be called. For example, if you had 2 listeners 'A' and 'B'
     * for this event. If, on the callback for listener A, listener A unregisters
     * all listeners and registers a new listener 'C' and then in the callback for
     * listener 'B', you unregister all listeners again and register a new listener
     * 'D'. Then on the subsequent event callback, only listener D's callback
     * will be invoked.
     *
     * \param packet The connection packet
     * \param muse   The \classlink{Muse} that sent the connection packet.
     */
    virtual void receive_muse_connection_packet(const MuseConnectionPacket & packet, const std::shared_ptr<Muse> & muse) = 0;
};

} }  // namespace interaxon::bridge
