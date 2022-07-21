//
// Created by Bernini on 12/07/2022.
//

#include "ListOfActivity.h"
#include <iostream>
#include <memory>


//add all the activities from list to the file, for each activity i have 7 line in the file
void ListOfActivity::writeActivityToFile() {
    std::fstream tmp;
    tmp.open("tmp.txt",std::ios::out);
    for(auto & it : listOfActivity) {
        tmp << it.getDescription() <<" ";
        if (it.getDate().isDisabled()) {
            tmp << 0<<" ";
            tmp << 0<<" ";
            tmp << 0<<" ";
        } else {
            tmp << it.getDate().getYear()<<" ";
            tmp << it.getDate().getMonth()<<" ";
            tmp << it.getDate().getDay()<<" ";
        }
        if (it.getHour().isDisabled()) {
            tmp << 0 <<" ";
            tmp << 0 <<" ";
        } else {
            tmp << it.getHour().getHour() <<" ";
            tmp << it.getHour().getMinute() <<" ";
        }
        tmp << it.isChecked() << std::endl;
    }
    file.close();
    tmp.close();
    remove("list_of_activity.txt");
    rename("tmp.txt","list_of_activity.txt");

}

//read activities from file and add activities to the list
void ListOfActivity::readActivityFromFile() {
    listOfActivity.clear();
    std::string description, activity;
    int day, month, year, hour,minute;
    bool check;
    std::ifstream line;
    line.open("list_of_activity.txt");
    while (line>>description>>year>>month>>day>>hour>>minute>>check){
        auto a=new Activity(description,check);
        auto h=new Hour();
        auto d=new Date();
        if(hour!=0 || minute!=0) {
            h->setHour(hour);
            h->setMinute(minute);
            h->setDisabled(false);
        }
        a->setHour(*h);
        if(year!=0 || month!=0 || day!=0){
            d->setDate(year,month,day);
            d->setDisabled(false);
        }
        a->setDate(*d);
        listOfActivity.push_back(*a);
    }
}


bool ListOfActivity::removeActivity(const std::string& description) {

    std::list<Activity>::iterator it;
    it=listOfActivity.begin();
    bool find=false;
    do{
        if ((*it).getDescription() == description) {
            listOfActivity.erase(it);
            find = true;
        }
        ++it;
    } while (!find && it!=listOfActivity.end());
    return find;
}

bool ListOfActivity::addCheck( const std::string& description) {
    auto it= findActivity(description);
    if(it!=listOfActivity.end()){
        (*it).setChecked(true);
        return true;
    }else
        return false;
}

bool ListOfActivity::removeCheck(const std::string& description) {
    auto it= findActivity(description);
    if(it!=listOfActivity.end()){
        (*it).setChecked(false);
        return true;
    }else
        return false;
}

void ListOfActivity::printAllActivities() const{
    std::cout<<"TO DO LIST:"<<std::endl;
    for (auto it = listOfActivity.begin(); it !=listOfActivity.end() ; ++it) {
        printActivity(*it);
    }
}

std::list<Activity>::iterator ListOfActivity::findActivity(const std::string& description)  {
    auto it= listOfActivity.begin();
    bool find=false;
    while (!find && it!=listOfActivity.end()){
        if ((*it).getDescription() == description) {
            find = true;
        } else
         ++it;
    }
   return it;

}

void ListOfActivity::addActivity(const Activity &a) {
    listOfActivity.push_back(a);
}

void ListOfActivity::printTodayActivities() const{

    std::cout<<"TO DO LIST:"<<std::endl;
    for (auto it = listOfActivity.begin(); it !=listOfActivity.end() ; ++it) {
        if(
                (*it).getDate().getDay()==Date::currentDay() &&
                (*it).getDate().getMonth()==Date::currentMonth() &&
                (*it).getDate().getYear()==Date::currentYear()
                )
            printActivity(*it);
    }
}

void ListOfActivity::printActivity(const Activity& a) const {
    if (a.isChecked())
        std::cout<<"[X] "<<a.getDescription()<<std::endl;
    else
        std::cout<<"[ ] "<<a.getDescription()<<std::endl;
    if(!a.getDate().isDisabled())
        std::cout<<"     "<<a.getDate().getDay()<<"/"<<a.getDate().getMonth()<<"/"<<a.getDate().getYear()<<std::endl;
    if(!a.getHour().isDisabled()) {
        if (a.getHour().getMinute() < 10)
            std::cout << "     " << a.getHour().getHour() << ":0" << a.getHour().getMinute() << std::endl;
        else
            std::cout << "     " << a.getHour().getHour() << ":" << a.getHour().getMinute() << std::endl;
    }
    std::cout<<"_______________"<<std::endl;
}

int ListOfActivity::numberOfActivity() const {
    int c=0;
    for(auto it:listOfActivity)
        ++c;
    return c;
}

int ListOfActivity::numberOfActivityToDo() const {
    int c=0;
    for(const auto& it:listOfActivity)
        if(!it.isChecked())
            ++c;
    return c;
}









