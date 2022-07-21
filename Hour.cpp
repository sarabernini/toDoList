//
// Created by Bernini on 12/07/2022.
//

#include <iostream>
#include "Hour.h"

bool Hour::setHour(const int h) {
    bool i;
    if (h>=0 && h<24) {
        hour = h;
        disabled=false;
        i=true;
    } else {
        valid = false;
        disabled=true;
        i=false;
    }
    return i;
}

bool Hour::setMinute(const int m) {
    bool i;
    if (m>=0 && m<60) {
        minute = m;
        disabled=false;
        i=true;
    }else {
        valid = false;
        disabled=true;
        i=false;
    }
    return i;
}

void Hour::setDisabled(const bool d) {
    Hour::disabled = d;
}

void Hour::setValid(const bool v) {
    Hour::valid = v;
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

bool Hour::isValid() const {
    return valid;
}




