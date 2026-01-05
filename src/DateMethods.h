#pragma once
#include <string>

class DateMethods
{
private:
    int getDaysInMonth(int year, int month);
    bool isYearLeap(int year);

public:
    bool validateDate(const std::string& date);
    bool isDateFrom2000ToEndOfCurrentMonth(int date);
    int getCurrentDate();
    int getFirstDayOfCurrentMonth();
};
