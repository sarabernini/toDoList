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
    std::list<Activity*> listOfActivity;
public:
    const std::list<Activity *> &getListOfActivity() const;

private:
    std::fstream file;

    void printActivity(const Activity* a);
public:

    void writeActivityToFile();
    void readActivityToFile();
    void removeActivity(const std::string& description);
    void addCheck(const std::string& description);
    void removeCheck( const std::string& description);
    void printAllActivities();
    void printTodayActivities();
    void addActivity(Activity& a);

    Activity* findActivity(const std::string& description);


    //constructor
    ListOfActivity(){
        file.open("list_of_activity.txt",std::ios::in | std::ios::app);
        readActivityToFile();
    };

    //destructor
    virtual ~ListOfActivity() {
        for(auto it : listOfActivity)
            delete it;
        file.close();
    }

};


#endif //MAIN_CPP_LISTOFACTIVITY_H
