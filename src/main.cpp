#include "core/systems/RoomMgr.hpp"

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
    // Some test class here
    ApplicationPtr->ShowMenu();

    auto RoomMgrPtr = std::make_unique<RoomManager>();
    std::cout << RoomMgrPtr->existsRoom(1) << '\n';
    
    Room myRoom{1, 1, 2, 1, ""};
    RoomMgrPtr->addRoom(myRoom);

    std::cout << RoomMgrPtr->existsRoom(1) << '\n';

    RoomMgrPtr->removeRoom(1);

    std::cout << RoomMgrPtr->existsRoom(1) << '\n';

    RoomMgrPtr->removeRoom(1);
}
