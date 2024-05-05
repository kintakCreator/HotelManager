#pragma once

#include "base/IRoomHandler.hpp"
#include "exceptions/RoomHandlersException.hpp"
#include "spdlog/spdlog.h"

#include <iostream>

class RemoveRoomHandler: IRoomHandler {
public:
    void printMessage() final {
        std::cout << "Let's delete a room of your hotel\n";
    }
    void handleAction(RoomManager* roomMgr) final {
       std::cout << "Enter room number(enter -1 to leave this menu): ";
       int roomNumber;
       std::cin >> roomNumber;
       if (roomNumber == -1)
           return;
       int uid = roomMgr->getUID(roomNumber);
       while (uid == -1) {
           std::cout << "Room with this room number does not exist. Please enter again: ";
           std::cin >> roomNumber;
           if (roomNumber == -1)
               return;
           uid = roomMgr->getUID(roomNumber);
       }
       if (!roomMgr->removeRoom(uid))
           throw RoomHandlersException(2, roomNumber);
       spdlog::info("Room has been removed.");
    }
};
