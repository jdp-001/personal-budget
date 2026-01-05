#include "DateMethods.h"
#include <cctype>  // std::isdigit
#include <cstddef> // size_t
#include <string>  // std::stoi
#include <ctime>   // time

bool DateMethods::validateDate(const std::string& date)
{
    // Format
    if (date.length() != 10) return false;
    if (date[4] != '-') return false;
    if (date[7] != '-') return false;

    for (size_t i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i])) return false;
    }

    // Calendar
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    int daysInMonth = getDaysInMonth(year, month);
    if (day > daysInMonth) return false;

    // Limit (2000.01.01 - end of current month)
    int dateToValidate = year * 10000 + month * 100 + day;
    return isDateFrom2000ToEndOfCurrentMonth(dateToValidate);
}

int DateMethods::getDaysInMonth(int year, int month)
{
    switch (month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isYearLeap(year) ? 29 : 28;
        default:
            return 0;
    }
}

bool DateMethods::isDateFrom2000ToEndOfCurrentMonth(int date)
{
    const int MIN_DATE = 20000101;

    int today = getCurrentDate();

    int year  = today / 10000;
    int month = (today / 100) % 100;

    int maxDate = year * 10000 + month * 100 + getDaysInMonth(year, month);

    return date >= MIN_DATE && date <= maxDate;
}

int DateMethods::getCurrentDate()
{
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    if (now == nullptr) return 0;

    int year  = now->tm_year + 1900;
    int month = now->tm_mon + 1;
    int day = now->tm_mday;

    return year * 10000 + month * 100 + day;
}

int DateMethods::isYearLeap(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 1 : 0;
}

int DateMethods::getCurrentMonthFirstDayDate()
{
    return getCurrentDate() / 100 * 100 + 1;
}

int DateMethods::getPreviousMonthFirstDayDate()
{
    int today = getCurrentDate();
    int year  = today / 10000;
    int month = (today / 100) % 100;

    month--;
    if (month == 0)
    {
        month = 12;
        year--;
    }

    return year * 10000 + month * 100 + 1;
}

int DateMethods::getPreviousMonthLastDayDate()
{
    int today = getCurrentDate();
    int year  = today / 10000;
    int month = (today / 100) % 100;

    month--;
    if (month == 0)
    {
        month = 12;
        year--;
    }

    return (year * 10000 + month * 100 + getDaysInMonth(year, month));
}
