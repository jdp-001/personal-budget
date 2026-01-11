#pragma once

#include "DateMethods.h"

class BudgetMenager
{
    DateMethods dateMethods;

    struct DateRange
    {
        int startDate;
        int endDate;
    };

public:
    DateRange getCurrentMonthRange();
    DateRange getPreviousMonthRange();
};
