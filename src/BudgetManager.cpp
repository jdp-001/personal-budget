#include "BudgetManager.h"
#include "Utils.h"
#include <iostream>
//#include <limits>
#include <sstream>
#include <algorithm>

void BudgetManager::sortOperations(std::vector<Operation>& operations)
{
    std::sort(operations.begin(), operations.end(),
    [](const Operation& a, const Operation& b)
    {
        return a.date < b.date;
    });
}

double BudgetManager::calculateBalance(int startDate, int endDate, const Type &type)
{
    double sum = 0.0;

    const std::vector<Operation>& operations =
        (type == INCOME) ? incomes : expenses;

    for (const auto& op : operations)
    {
        if (op.date >= startDate && op.date <= endDate)
            sum += op.amount;
    }

    return sum;
}

void BudgetManager::showBalance(int startDate, int endDate) {

    std::cout << "\nINCOMES:\n";
    for (const auto& op : incomes) {
        if (op.date >= startDate && op.date <= endDate)
            std::cout << op.date << "  " << op.item << "  " << op.amount << "\n";
    }

    double incomesSum = calculateBalance(startDate, endDate, INCOME);
    std::cout << "Incomes sum: " << incomesSum << "\n";

    std::cout << "\nEXPENSES:\n";
    for (const auto& op : expenses) {
        if (op.date >= startDate && op.date <= endDate)
            std::cout << op.date << "  " << op.item << "  " << op.amount << "\n";
    }

    double expensesSum = calculateBalance(startDate, endDate, EXPENSE);
    std::cout << "Expenses sum: " << expensesSum << "\n";

    std::cout << "\nBALANCE: " << (incomesSum - expensesSum) << "\n";
}

void BudgetManager::showCurrentMonthBalance()
{
    int endDate = dateMethods.getCurrentDate();
    int startDate = dateMethods.getCurrentMonthFirstDayDate();

    std::cout << "\n=== CURRENT MONTH BALANCE ===\n";
    showBalance(startDate, endDate);
}

void BudgetManager::showPreviousMonthBalance()
{
    int endDate   = dateMethods.getPreviousMonthLastDayDate();
    int startDate = dateMethods.getPreviousMonthFirstDayDate();

    std::cout << "\n=== PREVIOUS MONTH BALANCE ===\n";
    showBalance(startDate, endDate);
}

void BudgetManager::showCustomPeriodBalance()
{
    std::string startDateStr;
    std::string endDateStr;
    int startDate;
    int endDate;

    while (true)
    {
        std::cout << "Enter start date (yyyy-mm-dd): ";
        startDateStr = Utils::readLine();

        if (dateMethods.validateDate(startDateStr))
        {
            startDate = dateMethods.convertStringDateToInt(startDateStr);
            break;
        }

        std::cout << "Invalid date. Try again.\n";
    }

    while (true)
    {
        std::cout << "Enter end date (yyyy-mm-dd): ";
        endDateStr = Utils::readLine();

        if (dateMethods.validateDate(endDateStr))
        {
            endDate = dateMethods.convertStringDateToInt(endDateStr);

            if (startDate <= endDate)
                break;

            std::cout << "End date must be after start date.\n";
        }
        else
        {
            std::cout << "Invalid date. Try again.\n";
        }
    }

    std::cout << "\n=== CUSTOM PERIOD BALANCE ===\n";
    showBalance(startDate, endDate);
}

void BudgetManager::addIncome()
{
    Operation income = addOperationDetails(Type::INCOME);

    incomeFile.addOperationToFile(income);
    incomes.push_back(income);

    sortOperations(incomes);
}

void BudgetManager::addExpense()
{
    Operation expense = addOperationDetails(Type::EXPENSE);

    expenseFile.addOperationToFile(expense);
    expenses.push_back(expense);

    sortOperations(expenses);
}

Operation BudgetManager::addOperationDetails(const Type &type)
{
    Operation op;

    // int id;
    if (type == INCOME) op.id = incomeFile.getLastOperationId() + 1;
    if (type == EXPENSE) op.id = expenseFile.getLastOperationId() + 1;

    // int userId;
    op.userId = LOGGED_USER_ID;

    // int date
    int date;
    char ch;
    std::cout << "Is it today's operation? [y/n]" << std::endl;
    ch = Utils::getCharacter();
    if (ch == 'y' || ch == 'Y')
    {
        date = dateMethods.getCurrentDate();
    }
    else
    {
        // TO DO
        while (true)
        {
            std::cout << "Enter date (yyyy-mm-dd):" << std::endl;
            std::string dateString = Utils::readLine();
            if (dateMethods.validateDate(dateString))
            {
                date = dateMethods.convertStringDateToInt(dateString);
                break;
            }
            else
            {
                std::cout << "Incorrect date format or range." << std::endl;
            }
        }
    }

    op.date = date;

    // std::string item;
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

    op.item = item;

    // double amount;
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
    return op;
}
