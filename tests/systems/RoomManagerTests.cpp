#include "gtest/gtest.h"
#include "core/systems/RoomMgr.hpp"
#include <memory>

TEST(RoomManager_addRoom_with_getUID, Subtest_1) {
    auto roomMgrPtr = std::make_unique<RoomManager>();
    Room myRoom{1, 1, 235, 5, ""};
    ASSERT_TRUE(roomMgrPtr->addRoom(myRoom));
    ASSERT_TRUE(roomMgrPtr->getUID(235) == 1);
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(235)));
    ASSERT_FALSE(roomMgrPtr->addRoom(myRoom));
    

    Room myRoom2{1, 1, 236, 3, ""};
    ASSERT_TRUE(roomMgrPtr->addRoom(myRoom2));
    ASSERT_TRUE(roomMgrPtr->getUID(235) == 1);
    ASSERT_TRUE(roomMgrPtr->getUID(236) == 2);
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(235)));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(236)));
    ASSERT_FALSE(roomMgrPtr->addRoom(myRoom));
    ASSERT_FALSE(roomMgrPtr->addRoom(myRoom2));
} 

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
