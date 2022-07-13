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

public:

    //setter
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void setDate(int y, int m,int d);
    void setDisabled(bool disabled);

    //getter
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    bool isDisabled() const;

    //constructor
    Date(){disabled=true;}
    Date(int y, int m, int d): disabled(false){ setDate(y,m,d);};

private:
    bool isLeapYear(int y);
    bool isValidatedDate(int y, int m, int d);
};


#endif //MAIN_CPP_DATE_H
