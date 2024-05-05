#include "RoomMgr.hpp"
#include <stdexcept>

bool RoomManager::addRoom(Room& room) {
    if (getUID(room.roomNumber) != -1)
        return false;
    room.uid = m_roomStorage.empty() ? 1 : m_roomStorage.back().uid + 1;
    m_roomStorage.emplace_back(room);
    m_roomIndexByUID[room.uid] = m_roomStorage.size() - 1;
    m_UIDByRoomNumber[room.roomNumber] = room.uid; 
    return true;
}

// TODO: bad implementation, db fix it
bool RoomManager::removeRoom(int uid) {
    int roomIndex = getRoomIndexByUID(uid);
    if (roomIndex == -1)
        return false;
    int roomNumber = m_roomStorage[roomIndex].roomNumber;
    m_UIDByRoomNumber.erase(roomNumber);
    m_roomIndexByUID.erase(uid);
    return true;
}

bool RoomManager::editRoom(int uid, Room& newRoomData) {
    if (getUID(newRoomData.roomNumber) != -1)
        return false;
    int roomIndex = getRoomIndexByUID(uid);
    if (roomIndex == -1)
        return false;
    newRoomData.uid = m_roomStorage[roomIndex].uid;
    int oldRoomNumber = m_roomStorage[roomIndex].roomNumber;
    m_UIDByRoomNumber.erase(oldRoomNumber);
    m_roomStorage[roomIndex] = newRoomData;
    m_UIDByRoomNumber[newRoomData.roomNumber] = newRoomData.uid;
    return true;
}

bool RoomManager::existsRoom(int uid) const {
    return m_roomIndexByUID.find(uid) != m_roomIndexByUID.end();
}

bool RoomManager::isOccupied(int uid) const {
    int roomIndex = getRoomIndexByUID(uid);
    if (roomIndex == -1)
        throw std::exception(); // TODO: custom exception
    return !m_roomStorage[roomIndex].renterName.empty();
}

int RoomManager::getUID(int roomNumber) const {
    auto it = m_UIDByRoomNumber.find(roomNumber);
    if (it == m_UIDByRoomNumber.end())
        return -1;
    return (*it).second;
}

int RoomManager::getRoomIndexByUID(int uid) const {
    auto it = m_roomIndexByUID.find(uid);
    if (it == m_roomIndexByUID.end())
        return -1;
    return (*it).second;
}
