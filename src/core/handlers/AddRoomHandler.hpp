#include "base/IRoomHandler.hpp"
#include "spdlog/spdlog.h"
#include "exceptions/RoomHandlersException.hpp"

#include <iostream>

class AddRoomHandler: IRoomHandler {
public:
    void printMessage() final {
        std::cout << "Let's create a new room for your hotel" << '\n';
    }

    void handleAction(RoomManager* roomMgr) final {
        int roomNumber = 0;
        do {
            std::cout << "Enter number of room: " << '\n';
            std::cin >> roomNumber;
            if (roomMgr->getUID(roomNumber) != -1) { 
                spdlog::debug("Creating attempt has been failed. Room Number: {}", roomNumber); 
                std::cout << "Room with this number exists. Please enter another number of room.\n";
            }
        }
        while (roomMgr->getUID(roomNumber) != -1);
        
        int roomCapacity = 0;
        do {
            std::cout << "Enter room capacity: ";
            std::cin >> roomCapacity;
            if (roomCapacity <= 0) {
                spdlog::debug("Creating attempt has been failed. Room Capacity: {} <= 0", roomCapacity);
                std::cout << "Room capacity sholud be > 0\n";
            }
        }
        while (roomCapacity <= 0);

        // TODO: work with hotelUID and logs output
        
        Room newRoom{1, 1, roomNumber, roomCapacity, ""}; 
        if (!roomMgr->addRoom(newRoom))
            throw RoomHandlersException(1, roomNumber);
        
        spdlog::info("The room created...");
        std::cout << "The room has been created!\n";  
    }
};
