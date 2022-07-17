//
// Created by Bernini on 17/07/2022.
//

#include "gtest/gtest.h"
#include"../Hour.h"

TEST(HourTest,validHour){
    Hour rightHour(15,30);
    Hour wrongHour1(30,10);
    Hour wrongHour2(20,90);
    Hour wrongHour3(50,80);

    ASSERT_EQ(rightHour.isValid(),true);
    ASSERT_EQ(wrongHour1.isValid(),false);
    ASSERT_EQ(wrongHour2.isValid(),false);
    ASSERT_EQ(wrongHour3.isValid(),false);
}
