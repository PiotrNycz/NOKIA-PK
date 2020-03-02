#include "ConnectingState.hpp"

namespace ue
{

ConnectingState::ConnectingState(Context &context, common::BtsId btsId)
    : BaseState(context, "ConnectingState")
{
    context.logger.logInfo("Connecting to: ", btsId);
    context.user.showConnecting();
    context.bts.sendAttachRequest(btsId);
}

}
