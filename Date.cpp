//
// Created by Bernini on 12/07/2022.
//

#include "Date.h"
#include <iostream>
#include <ctime>
#include <chrono>
typedef std::chrono::system_clock Clock;

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

bool Date::isDisabled() const {
    return disabled;
}

bool Date::isValid() const {
    return valid;
}

//this method checks if a date is legal then insert the date
bool Date::setDate(int y, int m, int d) {

    if(isValidatedDate(y,m,d)){
        valid=true;
        year = y;
        month = m;
        day = d;
        disabled=false;
        return true;
    }else{
        valid=false;
        disabled=true;
        return false;
    }
}

//check if a year is leap
bool Date::isLeapYear(int y) const {

    if(y%4==0 && y%100!=0 || y%400==0)
        return true;
    else
        return false;
}

bool Date::isValidatedDate(int y, int m, int d) const{
    //data disabled
    if(disabled && y == 0 && m == 0 && d == 0)
        return true;

    //data not disabled

    if((y>currentYear() && y<2100 && m<13 && m>0 && d>0) ||
       (y==currentYear() && m>currentMonth() && m<13 && d>0) ||
       (y==currentYear() && m==currentMonth() && d>=currentDay())){

        if(m==2){
            if((isLeapYear(y)&&d<=29) || !isLeapYear(y)&&d<=28)
                return true;
        }else if (m==1 || m==3 || m==5 ||m==7 || m==8 || m==10 || m==12) {
            if (d <= 31)
                return true;
        }else if (d<=30)
            return true;
        else
            return false;
    }
    return false;
}

void Date::setDisabled( bool d) {
    Date::disabled = d;
}

int Date::currentDay() {
    auto now = Clock::now();
    std::time_t now_c = Clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);

    return parts->tm_mday;
}

int Date::currentMonth() {
    auto now = Clock::now();
    std::time_t now_c = Clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);

    return 1+ parts->tm_mon;
}

int Date::currentYear() {
    auto now = Clock::now();
    std::time_t now_c = Clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);

    return 1900+parts->tm_year;
}






