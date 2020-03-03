#pragma once

#include "BaseState.hpp"

namespace ue
{

class ConnectingState : public BaseState
{
public:
    ConnectingState(Context& context, common::BtsId btsId);

    void handleTimeout() final;
    void handleAttachAccept() final;
    void handleAttachReject() final;
};

}
