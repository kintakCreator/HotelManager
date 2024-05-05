#include "core/systems/RoomMgr.hpp"
#include <memory>

TEST(RoomManager, addRoom_with_getUID) {
    auto roomMgrPtr = std::make_unique<RoomManager>();
    Room myRoom{1, 1, 235, 5, ""};
    ASSERT_TRUE(roomMgrPtr->addRoom(myRoom));
    ASSERT_TRUE(roomMgrPtr->getUID(235) == 1);
    ASSERT_TRUE(roomMgrPtr->getUID(236) == -1);
    ASSERT_FALSE(roomMgrPtr->addRoom(myRoom));
    

    Room myRoom2{1, 1, 236, 3, ""};
    ASSERT_TRUE(roomMgrPtr->addRoom(myRoom2));
    ASSERT_TRUE(roomMgrPtr->getUID(235) == 1);
    ASSERT_TRUE(roomMgrPtr->getUID(236) == 2);
    ASSERT_TRUE(roomMgrPtr->getUID(250) == -1);
    ASSERT_FALSE(roomMgrPtr->addRoom(myRoom));
    ASSERT_FALSE(roomMgrPtr->addRoom(myRoom2));
}

TEST(RoomManager, existsRoom) {
    auto roomMgrPtr = std::make_unique<RoomManager>();
    Room myRoom{1, 1, 100, 3, ""};
    ASSERT_TRUE(roomMgrPtr->addRoom(myRoom));
    EXPECT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(100)));
    EXPECT_FALSE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(101)));
    Room myRoom2{1, 5, 105, 5, ""};
    ASSERT_TRUE(roomMgrPtr->addRoom(myRoom2));
    EXPECT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(100)));
    EXPECT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(105)));
    EXPECT_FALSE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(101)));
}

TEST(RoomManager, removeRoom) {
    auto roomMgrPtr = std::make_unique<RoomManager>();
    Room myRoom{1, 1, 100, 2, ""};
    ASSERT_TRUE(roomMgrPtr->addRoom(myRoom));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(100)));
    
    Room myRoom2{1, 5, 105, 5, ""};
    ASSERT_TRUE(roomMgrPtr->addRoom(myRoom2));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(100)));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(105)));
    EXPECT_FALSE(roomMgrPtr->removeRoom(roomMgrPtr->getUID(150)));
    EXPECT_TRUE(roomMgrPtr->removeRoom(roomMgrPtr->getUID(100)));
    ASSERT_FALSE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(100)));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(105)));
    EXPECT_FALSE(roomMgrPtr->removeRoom(roomMgrPtr->getUID(100)));
    EXPECT_TRUE(roomMgrPtr->removeRoom(roomMgrPtr->getUID(105)));
    ASSERT_FALSE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(100)));
    ASSERT_FALSE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(105)));
}

TEST(RoomManager, editRoom) {
    auto roomMgrPtr = std::make_unique<RoomManager>();

    Room myRoom{1, 1, 100, 2, ""};
    EXPECT_FALSE(roomMgrPtr->editRoom(roomMgrPtr->getUID(125), myRoom));
    ASSERT_TRUE(roomMgrPtr->addRoom(myRoom));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(100)));  
   
    Room myRoom2{1, 5, 105, 5, ""};
    ASSERT_TRUE(roomMgrPtr->addRoom(myRoom2));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(100)));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(105)));
    


    Room myChangedRoom{1, 1, 107, 2, ""};
    EXPECT_TRUE(roomMgrPtr->editRoom(roomMgrPtr->getUID(100), myChangedRoom));
    ASSERT_FALSE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(100)));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(105)));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(107)));
    ASSERT_TRUE(roomMgrPtr->addRoom(myRoom));

    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(100)));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(105)));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(107)));
    
    Room myChangedRoom2{1, 1, 105, 2, ""};
    EXPECT_FALSE(roomMgrPtr->editRoom(roomMgrPtr->getUID(107), myChangedRoom2));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(100)));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(105)));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(107)));
    
    Room myChangedRoom3{1, 1, 109, 2, ""};
    EXPECT_TRUE(roomMgrPtr->editRoom(roomMgrPtr->getUID(107), myChangedRoom3));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(100)));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(105)));
    ASSERT_FALSE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(107)));
    ASSERT_TRUE(roomMgrPtr->existsRoom(roomMgrPtr->getUID(109)));
}

TEST(RoomManager, isOccupied) {
    auto roomMgrPtr = std::make_unique<RoomManager>();
    // TODO: implement it when I create occupyRoom method
}
