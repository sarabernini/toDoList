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

void Date::setDay(int day) {
    Date::day = day;
}

void Date::setMonth(int month) {
    Date::month = month;
}

void Date::setYear(int year) {
    Date::year = year;
}

//this method checks if a date is legal then insert the date
void Date::setDate(int y, int m, int d) {

    if(isValidatedDate(y,m,d)){
        year = y;
        month = m;
        day = d;
    }else{
        std::cout<<"inserted date is not valid"<<std::endl;
    }
}

//check if a year is leap
bool Date::isLeapYear(int y) {
    auto now = Clock::now();
    std::time_t now_c = Clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);
    if(y%4==0 && y%100!=0 || y%400==0)
        return true;
    else
        return false;
}

bool Date::isValidatedDate(int y, int m, int d) {
    auto now = Clock::now();
    std::time_t now_c = Clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);

    if((y>(1900+ parts->tm_year && y<2100)&& m<13 && m>0 && d>0) ||
       (y==(1900 + parts->tm_year) && m>(1+ parts->tm_mon)) && m<13 ||
       (y==(1900 + parts->tm_year) && m==(1+ parts->tm_mon) && d>=parts->tm_mday)){
        if(m==2){
            if((isLeapYear(y)&&d<=29) || !isLeapYear(y)&&d<=28) {
                return true;
            }
        }else if (m==1 || m==3 || m==5 ||m==7 || m==8 || m==10 || m==12) {
            if (d <= 31) {
                return true;
            }
        }else if (d<=30){
            return true;
        }else
            return false;
    }
}

bool Date::isDisabled() const {
    return disabled;
}

void Date::setDisabled(bool disabled) {
    Date::disabled = disabled;
}


