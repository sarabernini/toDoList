//
// Created by Bernini on 12/07/2022.
//

#include <iostream>
#include "Hour.h"

void Hour::setHour(int h) {
    if (h>=0 && h<24) {
        hour = h;
        disabled=false;
    } else {
        valid = false;
        disabled=true;
        std::cout << "hour need to be between 0-23" << std::endl;
    }
}

void Hour::setMinute(int m) {
    if (m>=0 && m<60) {
        minute = m;
        disabled=false;
    }else {
        valid = false;
        disabled=true;
        std::cout << "minute need to be between 0-59" << std::endl;
    }
}

int Hour::getHour() const {
    return hour;
}

int Hour::getMinute() const{
    return minute;
}

bool Hour::isDisabled() const {
    return disabled;
}

void Hour::setDisabled(bool d) {
    Hour::disabled = d;
}

bool Hour::isValid() const {
    return valid;
}

void Hour::setValid(bool v) {
    Hour::valid = v;
}


