#include "RoomMgr.hpp"
#include <exception>

void RoomManager::addRoom(Room& room) {
    room.uid = m_roomStorage.empty() ? 1 : m_roomStorage.back().uid + 1;
    m_roomStorage.emplace_back(room);
    m_roomAccess[room.uid] = m_roomStorage.size() - 1;
}

// TODO: bad implementation, protobuf fix it
void RoomManager::removeRoom(uint32_t uid) {
    m_roomAccess.erase(uid);
}

void RoomManager::editRoom(uint32_t uid, Room& newRoomData) {
    if (!existsRoom(uid)) {
        // TODO: create my own exception for this case
        throw std::exception();
    }
    uint32_t storageIndex = m_roomAccess[uid];
    newRoomData.uid = m_roomStorage[storageIndex].uid;
    m_roomStorage[storageIndex] = newRoomData;
}

bool RoomManager::existsRoom(uint32_t uid) const {
    return m_roomAccess.find(uid) != m_roomAccess.end();
}

int RoomManager::getUID(uint8_t roomNumber) const {
    // TODO: implement this method
}
