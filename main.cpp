#include <iostream>
#include "Activity.h"
#include "ListOfActivity.h"


int main() {

ListOfActivity list;
int n;
bool exit=false;


do {
    std::cout << "   REMINDER" << std::endl;
    std::cout << "n. activity: ";
    std::cout << list.numberOfActivity() << std::endl;
    std::cout << "n. activity to do: ";
    std::cout << list.numberOfActivityToDo()<< std::endl;
    std::cout << "  " << std::endl;
    std::cout << "select an action:" << std::endl;
    std::cout << "1.print all activities" << std::endl;
    std::cout << "2.print today activities" << std::endl;
    std::cout << "3.add activity" << std::endl;
    std::cout << "4.remove activity" << std::endl;
    std::cout << "5.check activity" << std::endl;
    std::cout << "6.Uncheck activity" << std::endl;
    std::cout << "7.Save" << std::endl;
    std::cout << "8.Save & exit" << std::endl;
    std::cin >> n;

    switch (n) {
        case 1:
            list.printAllActivities();
            break;
        case 2:
            list.printTodayActivities();
            break;
        case 3:
        {
            std::string description;
            int day, month, year, h, m;
            int c,b;
            std::cout<<"insert description of the activity"<<std::endl;
           std::getline(std::cin >> std::ws,description);
            auto a= new Activity(description);
            do {
                std::cout << "press 1 if you want insert a date else, press 0 " << std::endl;
                std::cin >> c;
            }while(c!=0 && c!=1);
            auto date=new Date();
            if (c) {
                bool x =false;
                do {
                    std::cout << "press 1 if is a today activity, else press 0 " << std::endl;
                    std::cin >> b;
                }while(b!=0 && b!=1);
                if(b){
                    day=Date::currentDay();
                    month=Date::currentMonth();
                    year=Date::currentYear();
                    x=true;
                    date->setDate(year,month,day);
                }else {
                    while (!x) {
                        std::cout << "insert day of activity" << std::endl;
                        std::cin >> day;
                        std::cout << "insert month of activity" << std::endl;
                        std::cin >> month;
                        std::cout << "insert year of activity" << std::endl;
                        std::cin >> year;
                        x = date->setDate(year, month, day);
                        if(!x)
                            std::cout<<"inserted date is not valid"<<std::endl;
                    };
                    date->setDisabled(false);
                }
            }else
                date->setDisabled(true);
            do {
                std::cout << "press 1 if you want insert a hour else, press 0 " << std::endl;
                std::cin >> c;
            }while(c!=0 && c!=1);
            Hour* hour=new Hour();
            if (c) {
                bool x;
                do {
                    std::cout << "insert hour of activity" << std::endl;
                    std::cin >> h;
                    std::cout << "insert minute of activity" << std::endl;
                    std::cin >> m;
                    hour->setValid(true);
                    if(!hour->setHour(h))
                        std::cout<<"hour has to be between 0 and 23"<<std::endl;
                    if(!hour->setMinute(m))
                        std::cout<<"minute has to be between 0 and 59"<<std::endl;
                    x = hour->isValid();
                } while (!x);
                hour->setDisabled(false);
            }else
                hour->setDisabled(true);
            a->setHour(*hour);
            a->setDate(*date);
            list.addActivity(*a);
        }
            break;
        case 4: {
            list.printAllActivities();
            std::string d;
            std::cout<<"write name of activity to remove"<<std::endl;
            std::getline(std::cin >> std::ws,d);
            if(list.removeActivity(d))
                std::cout<<d<<" is deleted"<<std::endl;
            else
                std::cout<<"there was a problem"<<std::endl;
        }
           break;
        case 5:
        {
            list.printAllActivities();
            std::string d;
            std::cout<<"write name of activity to check"<<std::endl;
            std::getline(std::cin >> std::ws,d);
            if(list.addCheck(d))
                std::cout<<d<<" is check"<<std::endl;
            else
                std::cout<<d<<" is not find"<<std::endl;

        }
            break;
        case 6:
        {
            list.printAllActivities();
            std::string d;
            std::cout<<"write name of activity to uncheck"<<std::endl;
            std::getline(std::cin >> std::ws,d);
            if(list.removeCheck(d))
                std::cout<<d<<" is uncheck"<<std::endl;
            else
                std::cout<<d<<" is not find"<<std::endl;
        }
            break;
        case 7:
        {
            list.writeActivityToFile();
            list.readActivityFromFile();
        }
            break;
        case 8:
            exit=true;
            break;
        default:
            std::cout<<"try again"<<std::endl;
            break;
    }
}while (!exit);
list.writeActivityToFile();
return 0;

}





