#include "BudgetManager.h"
#include "Utils.h"
#include <iostream>
//#include <limits>
#include <sstream>

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

void BudgetManager::addIncomeTest()
{
    Operation op;

    op.id = 1;
    op.userId = 1;
    op.date = 20250101;
    op.item = "Test income";
    op.amount = 100.0;

    incomes.push_back(op);

    std::cout << "Income added. Current count: " << incomes.size() << std::endl;
}

void BudgetManager::addIncome()
{
    Operation op;

    std::string item;

    while (true)
    {
        std::cout << "Enter item: ";
        item = Utils::getLine();
        item = Utils::trim(item);

        if (!item.empty())
            break;

        std::cout << "Item can not be empty. Enter again." << std::endl;
    }

    double amount = 0.0;

    while (true)
    {
        std::cout << "Enter amount: ";
        std::string amountStr = Utils::getLine();

        for (char &c : amountStr)
            if (c == ',') c = '.';

        std::stringstream ss(amountStr);

        if ((ss >> amount) && (ss >> std::ws).eof() && amount > 0)
            break;

        std::cout << "Invalid amount. Enter again." << std::endl;
    }
    op.amount = amount;

    op.id = incomes.size() + 1;
    op.userId = LOGGED_USER_ID;
    op.date = 20250101;
    op.item = item;

    incomes.push_back(op);
    std::cout << "DEBUG: " << item << amount << std::endl;
    std::cout << "Income added. Count: " << incomes.size() << std::endl;

}
