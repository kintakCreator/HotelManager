#include <vector>
#include <unordered_map>
#include "base/RoomStructure.hpp"

class RoomManager 
{
public:
    RoomManager() = default;
    RoomManager(const RoomManager& rm) = delete;
    RoomManager& operator=(const RoomManager& rm) = delete;
    RoomManager& operator=(const RoomManager rm) = delete;
    bool addRoom(Room& room);
    bool removeRoom(int uid);
    bool editRoom(int uid, Room& newRoomData);
    bool occupyRoom(int uid, std::string renter_name/*,  std::vector<Users> */);
    bool existsRoom(int uid) const;
    bool isOccupied(int uid) const;  
    int getUID(int roomNumber) const;
    int getRoomIndexByUID(int uid) const;
private:
    std::vector<Room> m_roomStorage;
    std::unordered_map<int, int> m_roomIndexByUID;
    std::unordered_map<int, int> m_UIDByRoomNumber;
};
