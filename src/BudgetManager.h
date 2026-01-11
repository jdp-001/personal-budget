#pragma once

#include "DateMethods.h"

class BudgetManager
{
    DateMethods dateMethods;

public:
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();

};
