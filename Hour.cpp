//
// Created by Bernini on 12/07/2022.
//

#include <iostream>
#include "Hour.h"

void Hour::setHour(int h) {
    if (h>=0 && h<24)
        hour=h;
    else
        std::cout<<"hour need to be between 0-23"<<std::endl;
}

void Hour::setMinute(int m) {
    if (m>=0 && m<60)
        minute=m;
    else
        std::cout<<"minute need to be between 0-59"<<std::endl;
}

int Hour::getHour() {
    return hour;
}

int Hour::getMinute() {
    return minute;
}
