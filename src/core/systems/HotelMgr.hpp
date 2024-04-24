#include <vector>
#include <unordered_map>
#include "base/HotelStructure.hpp"

class HotelManager {
public:
    void addHotel(const Hotel& hotel);
    void removeHotel(uint32_t uid);
    void editHotel(uint32_t uid, const Hotel& newHotelData);
    bool hotelExist(uint32_t uid) const;
private:
    std::vector<Hotel> m_hotelStorage;
    std::unordered_map<uint32_t, size_t> m_hotelAccess;
};
