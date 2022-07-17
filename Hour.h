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
    bool valid=true;
public:
    bool isValid() const;

    void setValid(bool valid);

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
    Hour(int hour, int minute):disabled(false){
        setHour(hour);
        setMinute(minute);
    };
    Hour(){
        disabled=true;
        hour=0;
        minute=0;}
};


#endif //MAIN_CPP_HOUR_H
