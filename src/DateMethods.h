#pragma once
#include <string>

class DateMethods
{
private:
    int getDaysInMonth(int year, int month);

public:
    bool validateDate(const std::string& date);
    bool isStartDateBeforeOrEqualEndDate(int startDate, int endDate);
};
