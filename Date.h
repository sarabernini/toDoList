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
public:
    //setter
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    //getter
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setData(int y, int m,int d);
private:
    bool isLeapYear(int y);

};


#endif //MAIN_CPP_DATE_H
