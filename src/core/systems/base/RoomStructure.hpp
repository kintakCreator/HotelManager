#include <string>
#include <stdint.h>

struct Room {
    uint32_t hotelUid;
    uint32_t uid = -1;
    uint8_t roomNumber;
    uint8_t peopleCapacity;
    // rentStartDate
    // rentEndDate
    std::string renterName;
};
