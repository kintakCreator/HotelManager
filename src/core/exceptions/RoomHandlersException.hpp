#include "base/BaseException.hpp"

struct RoomHandlersException: BaseException { 
    int uid;
    int roomNumber;

    RoomHandlersException(int errorCode, int roomNumber): BaseException(errorCode), roomNumber(roomNumber) { }
    
    std::string what() final {
        return "Caught exception #" + std::to_string(errorCode) + "\n"
            + "Room Number: " + std::to_string(roomNumber); 
    }
};
