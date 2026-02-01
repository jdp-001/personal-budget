#include "BudgetManager.h"
#include <iostream>

void BudgetManager::showCurrentMonthBalance()
{
    // getCurrentDate() and getCurrentMonthFirstDayDate() from DateMethod
    int currentDate = dateMethods.getCurrentDate();
    int currentMonthFirstDayDate = dateMethods.getCurrentMonthFirstDayDate();

    std::cout << currentDate << std::endl;
    std::cout << currentMonthFirstDayDate << std::endl;

    // showBalance(int startDate, int endDate)
    // - Load incomes vector to incomesTemporary vector selecting the range of the above dates
    // - Sort incomesTemporary vector
    // - Display incomesTemporary vector
    // - incomesBalance = calculateBalance()
    // - Display incomesBalance
    //
    // - Load expenses vector to expensesTemporary vector selecting only the range of the above dates
    // - Sort expensesTemporary vector
    // - Display expensesTemporary vector
    // - expensesBalance = calculateBalance()
    // - Display expensesBalance
    //
    // - Display incomesBalance + expensesBalance

}
