//
// Created by Bernini on 12/07/2022.
//

#ifndef MAIN_CPP_HOUR_H
#define MAIN_CPP_HOUR_H


class Hour {
private:
    int hour;
    int minute;
    bool disabled;

public:
    //setter
    void setHour(int h);
    void setMinute(int m);
    void setDisabled(bool disabled);
    //getter
    const int getHour() const;
    const int getMinute() const;
    const bool isDisabled() const;
    //constructor
    Hour(int hour, int minute): hour(hour), minute(minute), disabled(false){};
    Hour(){disabled=true;}
};


#endif //MAIN_CPP_HOUR_H
