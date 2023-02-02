#include "..\Header File\class_date.hpp"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

void Date::setDate() {
    while (true) {
        WIDTH(25);
        CL << "\n\tEnter day: ";
        cin >> day;
        CL << "\n\tEnter month: ";
        cin >> month;
        CL << "\n\tEnter year: ";
        cin >> year;
        if (isValidDate()) {
            break;
        } else {
            CL << "\n\tInvalid date, try again" << endl;
        }
    }
}

bool Date::isLeapYear() {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

bool Date::isValidDate() {
    if (month < 1 || month > 12) {
        return false;
    }
    if (month == 2) {
        if (isLeapYear()) {
            if (day < 1 || day > 29) {
                return false;
            }
        } else {
            if (day < 1 || day > 28) {
                return false;
            }
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day < 1 || day > 30) {
            return false;
        }
    } else {
        if (day < 1 || day > 31) {
            return false;
        }
    }
    return true;
}

void Date::displayDate() {
    cout << day << "/" << month << "/" << year << endl;
}

