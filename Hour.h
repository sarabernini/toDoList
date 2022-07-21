//
// Created by Bernini on 12/07/2022.
//

#ifndef MAIN_CPP_HOUR_H
#define MAIN_CPP_HOUR_H


class Hour {
private:
    int hour{};
    int minute{};
    bool disabled;
    bool valid=true;

public:
    //setter
    bool setHour(int h);
    bool setMinute(int m);
    void setDisabled(bool d);
    void setValid(bool v);
    //getter
    int getHour() const;
    int getMinute() const;
    bool isDisabled() const;
    bool isValid() const;
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
