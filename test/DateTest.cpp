//
// Created by Bernini on 14/07/2022.
//
#include "gtest/gtest.h"
#include"../Date.h"

TEST(DateTest,setDataTest){
    Date wrongDate1(2022,2,2); //testing old date
    Date rightDate(2022,9,17); //testing right date
    Date wrongDate2(2023,2,29);//testing in a not leap year to check isLeapYear() function

    ASSERT_EQ(wrongDate1.setDate(2022,2,2),false);
    ASSERT_EQ(rightDate.setDate(2022,9,17),true);
    ASSERT_EQ(wrongDate2.setDate(2023,2,29),false);
}
