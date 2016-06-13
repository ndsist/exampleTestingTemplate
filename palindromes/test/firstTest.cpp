#include <gtest/gtest.h>

int getNumber(){
    return -3;
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}

TEST(firstTest, sillyTest){
    EXPECT_EQ(-3, getNumber());
}

TEST(firstTest, sillyTest2){
    EXPECT_EQ(-1, getNumber());
}
