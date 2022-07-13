//
// Created by Bernini on 12/07/2022.
//

#ifndef MAIN_CPP_LISTOFACTIVITY_H
#define MAIN_CPP_LISTOFACTIVITY_H
#include <iostream>
#include <list>
#include "Activity.h"

class ListOfActivity {
private:
    std::list<Activity*> listOfActivity;
public:
    void addActivity();
    void removeActivity();
    void addCheck();
    void removeCheck();

};


#endif //MAIN_CPP_LISTOFACTIVITY_H
