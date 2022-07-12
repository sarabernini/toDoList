//
// Created by sarab on 11/07/2022.
//

#ifndef MAIN_CPP_ACTIVITY_H
#define MAIN_CPP_ACTIVITY_H
#include <iostream>
#include "Hour.h"
#include "Date.h"

class Activity {
private:
    std::string description;
    Hour hour;
    Date date;
    bool checked;
};


#endif //MAIN_CPP_ACTIVITY_H
