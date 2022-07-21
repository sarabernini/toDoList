//
// Created by Bernini on 11/07/2022.
//

#include "Activity.h"

const std::string &Activity::getDescription() const {
    return description;
}


const Hour &Activity::getHour() const {
    return hour;
}

void Activity::setHour(const Hour &h) {
    Activity::hour = h;
}

const Date &Activity::getDate() const {
    return date;
}

void Activity::setDate(const Date &d) {
    Activity::date = d;
}

bool Activity::isChecked() const {
    return checked;
}

void Activity::setChecked(const bool c)  {
    Activity::checked = c;
}

bool Activity::operator==(const Activity&right){
    return description == right.description;
}


