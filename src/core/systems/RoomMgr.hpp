#include <vector>
#include <unordered_map>
#include "base/RoomStructure.hpp"

class RoomManager 
{
public:
    RoomManager() = default;
    RoomManager(const RoomManager& rm) = delete;
    RoomManager& operator=(const RoomManager& rm) = delete;
    bool addRoom( Room& room);
    bool removeRoom(uint32_t uid);
    bool editRoom(uint32_t uid, Room& newRoomData);
    bool existsRoom(uint32_t uid) const;
    int getUID(uint8_t roomNumber) const;
private:
    std::vector<Room> m_roomStorage;
    std::unordered_map<uint32_t, size_t> m_roomIndexByUID;
    std::unordered_map<uint8_t, uint32_t> m_UIDByRoomNumber;
};
