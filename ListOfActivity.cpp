//
// Created by Bernini on 12/07/2022.
//

#include "ListOfActivity.h"
#include <iostream>
#include <ctime>
#include <chrono>
typedef std::chrono::system_clock Clock;

//add all the activities from list to the file, for each activity i have 7 line in the file
void ListOfActivity::writeActivityToFile() {
    std::fstream tmp;
    tmp.open("tmp.txt",std::ios::out);
    for(auto & it : listOfActivity) {
        tmp << it->getDescription() <<" ";
        if (it->getDate().isDisabled()) {
            tmp << 0<<" " ;
            tmp << 0<<" " ;
            tmp << 0<<" " ;
        } else {
            tmp << it->getDate().getYear()<<" ";
            tmp << it->getDate().getMonth()<<" ";
            tmp << it->getDate().getDay()<<" ";
        }
        if (it->getHour().isDisabled()) {
            tmp << 0 <<" ";
            tmp << 0 <<" ";
        } else {
            tmp << it->getHour().getHour() <<" ";
            tmp << it->getHour().getMinute() <<" ";
        }
        tmp << it->isChecked() << std::endl;
    }
    file.close();
    tmp.close();
    remove("list_of_activity.txt");
    rename("tmp.txt","list_of_activity.txt");

}

//read activities from file and add activities to the list
void ListOfActivity::readActivityToFile() {
    listOfActivity.clear();
    std::string description, activity;
    int day, month, year, hour,minute;
    bool check;
    std::ifstream line;
    line.open("list_of_activity.txt");
    while (line>>description>>year>>month>>day>>hour>>minute>>check){
        //line>>description>>year>>month>>day>>hour>>minute>>check;
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
        listOfActivity.push_back(a);
    }
}


void ListOfActivity::removeActivity(const std::string& description) {

    std::list<Activity*>::iterator it;
    it=listOfActivity.begin();
    bool find=false;
    do{
        if ((*it)->getDescription() == description) {
            listOfActivity.erase(it);
            std::cout<<(*it)->getDescription()<<" is deleted"<<std::endl;
            find = true;
        }
        ++it;
    } while (!find && it!=listOfActivity.end());
}

void ListOfActivity::addCheck( const std::string& description) {
    auto activity= findActivity(description);
    if(activity!= nullptr) {
        if (!activity->isChecked()) {
            activity->setChecked(true);
        }
    }else
        std::cout<<"this element is not found"<<std::endl;
}

void ListOfActivity::removeCheck(const std::string& description) {
    auto activity= findActivity(description);
    if(activity!= nullptr) {
        if (activity->isChecked())
            activity->setChecked(false);
    }else
        std::cout<<"this element is not found"<<std::endl;
}

void ListOfActivity::printAllActivities() {
    std::cout<<"TO DO LIST:"<<std::endl;
    for (auto it = listOfActivity.begin(); it !=listOfActivity.end() ; ++it) {
        printActivity(*it);
    }
}

Activity* ListOfActivity::findActivity(const std::string& description) {
    Activity* a= nullptr;
    for(auto it:listOfActivity)
        if((*it).getDescription()==description){
            a=it;
        }
    return a;
}

void ListOfActivity::addActivity(Activity &a) {
    listOfActivity.push_back(&a);
}

void ListOfActivity::printTodayActivities() {
    auto now = Clock::now();
    std::time_t now_c = Clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);

    int actualYear=1900+parts->tm_year;
    int actualMonth=1+ parts->tm_mon;
    int actualDay=parts->tm_mday;

    std::cout<<"TO DO LIST:"<<std::endl;
    for (auto it = listOfActivity.begin(); it !=listOfActivity.end() ; ++it) {
        if((*it)->getDate().getDay()==actualDay && (*it)->getDate().getMonth()==actualMonth && (*it)->getDate().getYear()==actualYear)
            printActivity(*it);
    }
}

void ListOfActivity::printActivity(const Activity* a) {
    if (a->isChecked())
        std::cout<<"[X] "<<a->getDescription()<<std::endl;
    else
        std::cout<<"[ ] "<<a->getDescription()<<std::endl;
    if(!a->getDate().isDisabled())
        std::cout<<"     "<<a->getDate().getDay()<<"/"<<a->getDate().getMonth()<<"/"<<a->getDate().getYear()<<std::endl;
    if(!a->getHour().isDisabled())
        std::cout<<"     "<<a->getHour().getHour()<<":"<<a->getHour().getMinute()<<std::endl;
    std::cout<<"_______________"<<std::endl;
}








