#include "HotelMgr.hpp"

bool HotelManager::addHotel(Hotel& hotel) {
    hotel.uid = m_hotelStorage.empty() ? 1 : m_hotelStorage.back().uid + 1;
    m_hotelStorage.emplace_back(hotel);    
    m_hotelAccess[hotel.uid] = m_hotelStorage.size() - 1;
    return true;
}

bool HotelManager::removeHotel(int uid) {
    if (!hotelExist(uid))
        return false;
    m_hotelAccess.erase(uid);
    return true;
}
 

bool HotelManager::editHotel(int uid, Hotel& newHotelData) {
    if (!hotelExist(uid))
        return false;
    size_t storageIndex = m_hotelAccess[uid];
    newHotelData.uid = m_hotelStorage[storageIndex].uid;
    return true;
}
    

bool HotelManager::hotelExist(int uid) const {
    return m_hotelAccess.find(uid) != m_hotelAccess.end();
}

    
//std::vector<Hotel> m_hotelStorage;
//std::unordered_map<uint32_t, size_t> m_hotelAccess;
