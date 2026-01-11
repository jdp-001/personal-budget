#pragma once

#include "DateMethods.h"
#include "Operation.h"

#include <vector>

class BudgetManager
{
    DateMethods dateMethods;
    std::vector<Operation> operations;

public:
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();

};
