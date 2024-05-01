#include <string>
#include <stdint.h>

struct Room {
    int hotelUid;
    int uid = -1; // unsigned int was here (it's so stupid...)
    int roomNumber;
    int peopleCapacity;
    // rentStartDate
    // rentEndDate
    std::string renterName;
};
