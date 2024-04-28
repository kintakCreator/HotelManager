#include "RoomMgr.hpp"

bool RoomManager::addRoom(Room& room) {
    if (getUID(room.roomNumber) != -1)
        return false;
    room.uid = m_roomStorage.empty() ? 1 : m_roomStorage.back().uid + 1;
    m_roomStorage.emplace_back(room);
    m_roomIndexByUID[room.uid] = m_roomStorage.size() - 1;
    m_UIDByRoomNumber[room.roomNumber] = room.uid; 
    return true;
}

// TODO: bad implementation, protobuf fix it
bool RoomManager::removeRoom(uint32_t uid) {
    if (!existsRoom(uid))
        return false;
    size_t roomIndex = m_roomIndexByUID[uid];
    uint8_t roomNumber = m_roomStorage[roomIndex].roomNumber;
    m_UIDByRoomNumber.erase(roomNumber);
    m_roomIndexByUID.erase(uid);
    return true;
}

bool RoomManager::editRoom(uint32_t uid, Room& newRoomData) {
    if (!existsRoom(uid) || getUID(newRoomData.roomNumber) != -1)
        return false;
    size_t storageIndex = m_roomIndexByUID[uid];
    newRoomData.uid = m_roomStorage[storageIndex].uid;
    uint16_t oldRoomNumber = m_roomStorage[storageIndex].roomNumber;
    m_UIDByRoomNumber.erase(oldRoomNumber);
    m_roomStorage[storageIndex] = newRoomData;
    m_UIDByRoomNumber[newRoomData.roomNumber] = newRoomData.uid;
    return true;
}

bool RoomManager::existsRoom(uint32_t uid) const {
    return m_roomIndexByUID.find(uid) != m_roomIndexByUID.end();
}

int RoomManager::getUID(uint8_t roomNumber) const {
    auto it = m_UIDByRoomNumber.find(roomNumber);
    if (it == m_UIDByRoomNumber.end())
        return -1;
    return (*it).second;
}
