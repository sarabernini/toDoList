//
// Created by Bernini on 17/07/2022.
//


#include "gtest/gtest.h"
#include"../ListOfActivity.h"

TEST(ListTest,check){
auto a=new Activity("testList",20,10,2026,8,20,false);
auto b=new Activity("testList2",10,15,2027,9,21,true);
ListOfActivity list;
list.addActivity(*a);
list.addActivity(*b);

list.addCheck(a->getDescription());
    ASSERT_EQ(a->isChecked(),true);
list.removeCheck(b->getDescription());
    ASSERT_EQ(b->isChecked(),false);


}

TEST(ListTest,add){
    auto* a= new Activity("testList",20,10,2026,8,20,true);
    ListOfActivity list;
    bool c=false;
    list.addActivity(*a);
    if(list.findActivity(a->getDescription())!= nullptr)
        c=true;

    ASSERT_TRUE(c);

}

TEST(ListTest,remove){
    auto* a= new Activity("testList",20,10,2026,8,20,true);
    ListOfActivity list;
    bool c=false;
    list.addActivity(*a);
    list.removeActivity(a->getDescription());
    if(list.findActivity(a->getDescription())==nullptr)
         c=true;

    ASSERT_TRUE(c);



}