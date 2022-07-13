//
// Created by Bernini on 12/07/2022.
//

#include "ListOfActivity.h"

void ListOfActivity::addActivity(const Activity &activity) {
    file<<"[ ] "<<activity.getDescription()<<std::endl;
    if (!activity.getDate().isDisabled())
        file<<activity.getDate().getDay()<<"/"<<activity.getDate().getMonth()<<"/"<<activity.getDate().getYear()<<std::endl;
    if(!activity.getHour().isDisabled())
        file<<activity.getHour().getHour()<<":"<<activity.getHour().getMinute()<<std::endl;

}

void ListOfActivity::removeActivity(const Activity &activity) {
    std::string line;
    std::string deleteLine;
    std::string deleteDate;
    std::string deleteHour;
    bool isHour= false;
    bool isDate= false;
    if (activity.isChecked())
        deleteLine = "[X] " + activity.getDescription();
    else
        deleteLine = "[ ] " + activity.getDescription();
    if (!activity.getDate().isDisabled()) {
        isDate = true;
        deleteDate =
                std::to_string(activity.getDate().getDay()) + "/" + std::to_string(activity.getDate().getMonth()) +
                "/" + std::to_string(activity.getDate().getYear());
    }

    if (!activity.getHour().isDisabled()) {
        isHour = true;
        deleteHour =
                std::to_string(activity.getHour().getHour()) + ":" + std::to_string(activity.getHour().getMinute());
    }

    while (getline(file, line)) {
        line.replace(line.find(deleteLine), deleteLine.length(), "");
        if(isDate)
            line.replace(line.find(deleteDate), deleteDate.length(), "");
        if(isHour)
            line.replace(line.find(deleteHour), deleteHour.length(), "");
    }


}

void ListOfActivity::addCheck() {

}

void ListOfActivity::removeCheck() {

}
