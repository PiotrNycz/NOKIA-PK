#include "ConnectingState.hpp"
#include "ConnectedState.hpp"

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

void ConnectingState::handleTimeout()
{
    context.logger.logError("Attach timeout");

}

void ConnectingState::handleAttachAccept()
{
    context.logger.logDebug("Attach accepted");
    context.setState<ConnectedState>();
}

void ConnectingState::handleAttachReject()
{
    context.logger.logError("Attach rejected");
}

}
