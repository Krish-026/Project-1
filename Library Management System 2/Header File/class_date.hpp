#ifndef CLASS_DATE_HPP
#define CLASS_DATE_HPP
#include <iostream>
#define WIDTH(a) cout.width(a)
#define CL cout << left
using namespace std;
class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int day = 0, int month = 0, int year = 0);
    void setDate();
    bool isLeapYear();
    bool isValidDate();
    void displayDate();
};
#endif