#include "ConnectingState.hpp"
#include "ConnectedState.hpp"
#include "NotConnectedState.hpp"

namespace ue
{

ConnectingState::ConnectingState(Context &context, common::BtsId btsId)
    : BaseState(context, "ConnectingState")
{
    using namespace std::chrono_literals;

    context.logger.logInfo("Connecting to: ", btsId);
    context.user.showConnecting();
    context.bts.sendAttachRequest(btsId);
    context.timer.startTimer(500ms);
}

void ConnectingState::handleAttachAccept()
{
    context.logger.logDebug("Attach accepted");
    context.timer.stopTimer();
    context.setState<ConnectedState>();
}

void ConnectingState::handleTimeout()
{
    context.logger.logError("Attach timeout");
    context.setState<NotConnectedState>();
}

void ConnectingState::handleAttachReject()
{
    context.logger.logError("Attach rejected");
    context.timer.stopTimer();
    context.setState<NotConnectedState>();
}

void ConnectingState::handleDisconnected()
{
    context.logger.logError("Bts Disconnected");
    context.timer.stopTimer();
    context.setState<NotConnectedState>();
}

}


