//
// Created by Bernini on 17/07/2022.
//


#include "gtest/gtest.h"
#include"../ListOfActivity.h"


TEST(ListTest,check){
ListOfActivity list;
Activity a("testList");
list.addActivity(a);
    ASSERT_EQ(list.numberOfActivityToDo(),1);
list.addCheck(a.getDescription());
    ASSERT_EQ(list.numberOfActivityToDo(),0);
}

TEST(ListTest,uncheck){
    ListOfActivity list;
    Activity a("testList",true);
    list.addActivity(a);
    ASSERT_EQ(list.numberOfActivityToDo(),0);
    list.removeCheck(a.getDescription());
    ASSERT_EQ(list.numberOfActivityToDo(),1);
}

TEST(ListTest,add){
    auto* a= new Activity("testList",20,10,2026,8,20,true);
    ListOfActivity list;
    bool c=false;
    list.addActivity(*a);

    ASSERT_EQ(list.numberOfActivity(),1);
}

TEST(ListTest,remove){
    auto* a= new Activity("testList",20,10,2026,8,20,true);
    ListOfActivity list;
    list.addActivity(*a);
    list.removeActivity(a->getDescription());

    ASSERT_EQ(list.numberOfActivity(),0);


}