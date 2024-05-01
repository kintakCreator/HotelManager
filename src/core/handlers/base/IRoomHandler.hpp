#include <memory>
#include "../../systems/RoomMgr.hpp"

class IRoomHandler {
public:
    virtual void printMessage() = 0;
    virtual void handleAction(RoomManager* roomMgr) = 0;
};
