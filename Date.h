//
// Created by Bernini on 12/07/2022.
//

#ifndef MAIN_CPP_DATE_H
#define MAIN_CPP_DATE_H


class Date {
private:
    int day;
    int month;
    int year;
    bool disabled;
    bool valid=false;
public:
    bool isValid() const;

    void setIsValid(bool isValid);

public:

    //setter
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    bool setDate(int y, int m,int d);
    void setDisabled(bool disabled);

    //getter
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    bool isDisabled() const;

    //constructor
    Date(){
        disabled=true;
        year=0;
        month=0;
        day=0;
    }
    Date(int y, int m, int d): disabled(false){ setDate(y,m,d);};

    bool isLeapYear(int y);
    bool isValidatedDate(int y, int m, int d);
};


#endif //MAIN_CPP_DATE_H
