#include "core/handlers/AddRoomHandler.hpp"

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
    }
};

int main() 
{
    auto ApplicationPtr = std::make_unique<Application>();
    RoomManager* RoomMgrPtr = new RoomManager();
    while (true) {
        ApplicationPtr->ShowMenu();
        int variant;
        std::cin >> variant;
        if (variant == 1) {
            auto AddRoomHandlerPtr = std::make_unique<AddRoomHandler>(); 
            AddRoomHandlerPtr->printMessage();
            AddRoomHandlerPtr->handleAction(RoomMgrPtr);
        }
    }
}
