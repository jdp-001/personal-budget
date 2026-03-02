#include "BudgetManager.h"
#include "Utils.h"
#include <iostream>
//#include <limits>
#include <sstream>
#include <algorithm>

void BudgetManager::showCurrentMonthBalance()
{
    int endDate = dateMethods.getCurrentDate();
    int startDate = dateMethods.getCurrentMonthFirstDayDate();

    std::cout << "\n=== CURRENT MONTH BALANCE ===\n";

    std::sort(incomes.begin(), incomes.end(),
    [](const Operation& a, const Operation& b) {
        return a.date < b.date;
    });

    double incomesSum = 0.0;
    std::cout << "\nINCOMES:\n";
    for (const auto& op : incomes)
        if (op.date >= startDate && op.date <= endDate)
        {
            incomesSum += op.amount;
            std::cout << op.date << "  " << op.item << "  " << op.amount << "\n";
        }

    std::cout << "Incomes sum: " << incomesSum << "\n";

    std::sort(expenses.begin(), expenses.end(),
    [](const Operation& a, const Operation& b) {
        return a.date < b.date;
    });

    double expensesSum = 0.0;
    std::cout << "\nEXPENSES:\n";
    for (const auto& op : expenses)
        if (op.date >= startDate && op.date <= endDate)
        {
            expensesSum += op.amount;
            std::cout << op.date << "  " << op.item << "  " << op.amount << "\n";
        }

    std::cout << "Expenses sum: " << expensesSum << "\n";

    std::cout << "\nBALANCE: " << (incomesSum - expensesSum) << "\n";
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
        item = Utils::readLine();
        item = Utils::trim(item);

        if (!item.empty())
            break;

        std::cout << "Item can not be empty. Enter again." << std::endl;
    }

    double amount = 0.0;

    while (true)
    {
        std::cout << "Enter amount: ";
        std::string amountStr = Utils::readLine();

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
