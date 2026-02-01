#pragma once

#include "DateMethods.h"
#include "Operation.h"

#include <vector>

class BudgetManager
{
    DateMethods dateMethods;
    std::vector<Operation> incomes;
    std::vector<Operation> expenses;

public:
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();

};
