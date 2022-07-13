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
public:
    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    const Hour &getHour() const;

    void setHour(const Hour &hour);

    const Date &getDate() const;

    void setDate(const Date &date);

    bool isChecked() const;

    void setChecked(bool checked);

private:
    bool checked;
public:
    explicit Activity(std::string description,bool checked=false):description(std::move(description)),checked(checked),hour(),date(){};
    Activity(std::string description, int h, int min, int y, int m, int d,bool checked=false):
    description(std::move(description)),checked(checked),hour(h, min),date(y,m,d){};

};


#endif //MAIN_CPP_ACTIVITY_H
