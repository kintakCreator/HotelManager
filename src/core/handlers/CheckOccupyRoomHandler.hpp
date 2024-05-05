#include "base/IRoomHandler.hpp"

#include <iostream>

class CheckOccupyRoomHandler: IRoomHandler {
public:
    void printMessage() final {
        std::cout << "Let's check occupied is room\n";
    }

    void handleAction(RoomManager* roomMgr) final {
        std::cout << "Enter room number(enter -1 to leave this menu): ";
        int roomNumber;
        std::cin >> roomNumber;
        if (roomNumber == -1)
            return;
        int uid = roomMgr->getUID(roomNumber);
        while (uid == -1) {
            std::cout << "You entered the room number that not exist. Please enter a valid room number: ";
            std::cin >> roomNumber;
            if (roomNumber == -1)
                return;
            uid = roomMgr->getUID(roomNumber);
        }    
        if (roomMgr->isOccupied(uid))
            std::cout << "Room with number " << roomNumber << " is occupied\n";
        else
            std::cout << "Room with number " << roomNumber << " is not occupied\n";
    }  
};
