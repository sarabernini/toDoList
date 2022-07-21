//
// Created by Bernini on 12/07/2022.
//

#ifndef MAIN_CPP_LISTOFACTIVITY_H
#define MAIN_CPP_LISTOFACTIVITY_H
#include <iostream>
#include <list>
#include <fstream>
#include "Activity.h"

class ListOfActivity {

private:
    std::list<Activity> listOfActivity;
   std::fstream file;

    void printActivity(const Activity& a) const;
public:

    void writeActivityToFile();
    void readActivityFromFile();
    bool removeActivity(const std::string& description);
    bool addCheck(const std::string& description);
    bool removeCheck( const std::string& description);
    void printAllActivities() const;
    void printTodayActivities() const;
    void addActivity(const Activity& a);
    int numberOfActivity() const;
    int numberOfActivityToDo() const;

    std::list<Activity>::iterator findActivity(const std::string& description) ;


    //constructor
    ListOfActivity(){
        file.open("list_of_activity.txt",std::ios::in | std::ios::app);
        readActivityFromFile();
    };

    //destructor
    virtual ~ListOfActivity() {
        file.close();
    }

};


#endif //MAIN_CPP_LISTOFACTIVITY_H
