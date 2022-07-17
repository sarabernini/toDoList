//
// Created by Bernini on 11/07/2022.
//

#include "Activity.h"

const std::string &Activity::getDescription() const {
    return description;
}

void Activity::setDescription(const std::string &description) {
    Activity::description = description;
}

const Hour &Activity::getHour() const {
    return hour;
}

void Activity::setHour(const Hour &hour) {
    Activity::hour = hour;
}

const Date &Activity::getDate() const {
    return date;
}

void Activity::setDate(const Date &date) {
    Activity::date = date;
}

bool Activity::isChecked() const {
    return checked;
}

void Activity::setChecked(bool checked) {
    Activity::checked = checked;
}

bool Activity::operator==(const Activity&right){
    return description == right.description;
}


