//
// Created by Bernini on 11/07/2022.
//

#ifndef MAIN_CPP_ACTIVITY_H
#define MAIN_CPP_ACTIVITY_H
#include <iostream>
#include <utility>
#include "Hour.h"
#include "Date.h"

class Activity {
private:

    std::string description;
    Hour hour;
    Date date;
    bool checked;

public:

    //getter
    const std::string &getDescription() const;
    const Hour &getHour() const;
    const Date &getDate() const;
    bool isChecked() const;

    //setter
    void setChecked(bool checked);
    void setDescription(const std::string &description);
    void setHour(const Hour &hour);
    void setDate(const Date &date);

    //constructor
    explicit Activity(std::string description,bool checked=false):description(std::move(description)),checked(checked),hour(),date(){};
    Activity(std::string description, int h, int min, int y, int m, int d,bool checked=false):
            description(std::move(description)),checked(checked),hour(h, min),date(y,m,d){};

    bool operator==(const Activity&right);

};


#endif //MAIN_CPP_ACTIVITY_H
