#include <vector>
#include <unordered_map>
#include "base/HotelStructure.hpp"

class HotelManager {
public:
    bool addHotel(Hotel& hotel);
    bool removeHotel(int uid);
    bool editHotel(int uid, Hotel& newHotelData);
    bool hotelExist(int uid) const;
private:
    std::vector<Hotel> m_hotelStorage;
    std::unordered_map<int, size_t> m_hotelAccess;
};
