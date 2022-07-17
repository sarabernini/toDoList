#include <iostream>
#include "Activity.h"
#include "ListOfActivity.h"

int main() {

ListOfActivity list;
int n;
bool exit=false;

do {
    std::cout << "select an action:" << std::endl;
    std::cout << "1.print all activities" << std::endl;
    std::cout << "2.print today activities" << std::endl;
    std::cout << "3.add activity" << std::endl;
    std::cout << "4.remove activity" << std::endl;
    std::cout << "5.check activity" << std::endl;
    std::cout << "6.Uncheck activity" << std::endl;
    std::cout << "7.Save" << std::endl;
    std::cout << "8.exit" << std::endl;
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
            int c;
            std::cout<<"insert description of the activity"<<std::endl;
            std::cin>>description;
            auto* a= new Activity(description);
            do {
                std::cout << "press 0 if you want insert a date else, press 1 " << std::endl;
                std::cin >> c;
            }while(c!=0 && c!=1);
            Date* date=new Date();
            if (c==0) {
                bool x;
                do {
                    std::cout << "insert day of activity" << std::endl;
                    std::cin >> day;
                    std::cout << "insert month of activity" << std::endl;
                    std::cin >> month;
                    std::cout << "insert year of activity" << std::endl;
                    std::cin >> year;
                    x=date->setDate(year,month,day);
                }while (!x);
                date->setDisabled(false);
            }else
                date->setDisabled(true);
            do {
                std::cout << "press 0 if you want insert a hour else, press 1 " << std::endl;
                std::cin >> c;
            }while(c!=0 && c!=1);
            Hour* hour=new Hour();
            if (c==0) {
                bool x;
                do {
                    std::cout << "insert hour of activity" << std::endl;
                    std::cin >> h;
                    std::cout << "insert minute of activity" << std::endl;
                    std::cin >> m;
                    hour->setValid(true);
                    hour->setHour(h);
                    hour->setMinute(m);
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
            std::cin>>d;
            list.removeActivity(d);
        }
           break;
        case 5:
        {
            list.printAllActivities();
            std::string d;
            std::cout<<"write name of activity to check"<<std::endl;
            std::cin>>d;
            list.addCheck(d);
        }
            break;
        case 6:
        {
            list.printAllActivities();
            std::string d;
            std::cout<<"write name of activity to uncheck"<<std::endl;
            std::cin>>d;
            list.removeCheck(d);
        }
            break;
        case 7:
        {
            list.writeActivityToFile();
            list.readActivityToFile();
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





