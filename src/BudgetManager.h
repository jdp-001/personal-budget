#pragma once
#include <iostream>
#include "DateMethods.h"
#include "Operation.h"
#include "OperationFile.h"
#include "Type.h"

#include <vector>
#include <string>

class BudgetManager
{
    DateMethods dateMethods;
    std::vector<Operation> incomes;
    std::vector<Operation> expenses;

    const int LOGGED_USER_ID;

    OperationFile incomeFile;
    OperationFile expenseFile;

public:
    BudgetManager(const std::string& incomeFileName, const std::string& expenseFileName, int loggedUserId)
    : LOGGED_USER_ID(loggedUserId), incomeFile(incomeFileName), expenseFile(expenseFileName)
        {
            incomes  = incomeFile.loadOperationsFromFile(LOGGED_USER_ID);
            expenses = expenseFile.loadOperationsFromFile(LOGGED_USER_ID);
        }

    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();

    void addIncomeTest();
    void addIncome();

private:
    void showBalance(int startDate, int endDate);
    double calculateBalance(int startDate, int endDate, const Type &type);

};
