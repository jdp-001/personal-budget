#pragma once
#include "UserManager.h"
#include "BudgetManager.h"

#include <string>

class BudgetMainApp
{
private:
    UserManager userManager;
    BudgetManager* budgetManager;

public:
    BudgetMainApp(std::string usersFileName, std::string incomesFileName, std::string expensesFileName)
    {
        budgetManager = nullptr;

    }

    bool isUserLoggedIn();
    void registerUser();
    void loginUser();
    void logoutUser();
    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();
    void changeUserPassword();
};
