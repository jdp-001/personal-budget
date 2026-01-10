#pragma once
#include <string>

class DateMethods
{
private:
    int getDaysInMonth(int year, int month);
    int isYearLeap(int year);

public:
    bool validateDate(const std::string& date);
    bool isDateFrom2000ToEndOfCurrentMonth(int date);
    int getCurrentDate();
    int getCurrentMonthFirstDayDate();
    int getPreviousMonthFirstDayDate();
    int getPreviousMonthLastDayDate();
    int convertStringDateToInt(const std::string &dateAsString);
    std::string convertIntDateToStringWithDashes(int dateAsInt);
};
