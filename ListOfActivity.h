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
    std::fstream file;
public:
    void addActivity( const Activity& activity);

    void removeActivity(const Activity& activity);

    void addCheck();

    void removeCheck();



    ListOfActivity(){
        file.open("list_of_activity.txt",std::ios::in | std::ios::app);
    };

    virtual ~ListOfActivity() {
        file.close();
        for(auto it : listOfActivity){
            delete it;
        };
    }

};


#endif //MAIN_CPP_LISTOFACTIVITY_H
