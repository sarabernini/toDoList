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
        std::cout<<"inserted date is not valid"<<std::endl;
        return false;
    }
}

//check if a year is leap
bool Date::isLeapYear(int y) {

    if(y%4==0 && y%100!=0 || y%400==0)
        return true;
    else
        return false;
}

bool Date::isValidatedDate(int y, int m, int d) {
    //data disabled
    if(disabled && y == 0 && m == 0 && d == 0)
        return true;

    //data not disabled
    auto now = Clock::now();
    std::time_t now_c = Clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);

    int actualYear=1900+parts->tm_year;
    int actualMonth=1+ parts->tm_mon;
    int actualDay=parts->tm_mday;

    if((y>actualYear && y<2100 && m<13 && m>0 && d>0) ||
       (y==actualYear && m>actualMonth && m<13 && d>0) ||
       (y==actualYear && m==actualMonth && d>=actualDay)){

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

bool Date::isDisabled() const {
    return disabled;
}

void Date::setDisabled(bool d) {
    Date::disabled = d;
}

bool Date::isValid() const {
    return valid;
}






