#include "core/handlers/AddRoomHandler.hpp"
#include "core/handlers/RemoveRoomHandler.hpp"
#include "core/handlers/CheckOccupyRoomHandler.hpp"

#include "spdlog/spdlog.h"

#include <iostream>
#include <memory>

class Application
{
public:
    void ShowMenu()
    {
        std::cout << "Welcome to hotel management system!\n";
        std::cout << "Please choice option to execute:\n";
        std::cout << "1. Add a new room\n";
        std::cout << "2. Remove a room\n";
        std::cout << "3. Check room is occupied or not\n";
        std::cout << "4. Occupy the room\n";
        std::cout << "5. Check-out (for room)\n";
        std::cout << "6. Exit\n";
    }
};

int main() 
{    
    spdlog::info("Starting...");
    auto ApplicationPtr = std::make_unique<Application>();
    RoomManager* RoomMgrPtr = new RoomManager();
    while (true) {
        ApplicationPtr->ShowMenu();
        int variant;
        std::cin >> variant;
        // TODO: change it to switch/case operator
        if (variant == 1) {
            auto AddRoomHandlerPtr = std::make_unique<AddRoomHandler>(); 
            AddRoomHandlerPtr->printMessage();
            try {
                AddRoomHandlerPtr->handleAction(RoomMgrPtr);
            } catch (BaseException& ex) {
                spdlog::error(ex.what());
                return 1;
            } catch (...) {
                spdlog::error("Unknown exception has been thrown\n");
                return 1;
            }
        } else if (variant == 2) {
            auto RemoveRoomHandlerPtr = std::make_unique<RemoveRoomHandler>();
            RemoveRoomHandlerPtr->printMessage();
            try {
                RemoveRoomHandlerPtr->handleAction(RoomMgrPtr);
            } catch (BaseException& ex) {
                spdlog::error(ex.what());
                return 1;
            } catch (...) {
                spdlog::error("Unknown exception has been thrown\n");
                return 1;
            }
        } else if (variant == 3) {
            auto CheckOccupyRoomHandlerPtr = std::make_unique<CheckOccupyRoomHandler>();
            CheckOccupyRoomHandlerPtr->printMessage();
            CheckOccupyRoomHandlerPtr->handleAction(RoomMgrPtr); // noexcept
        } else if (variant == 6) {
            exit(0);
        }
    }
}
