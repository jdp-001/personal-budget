#pragma once

#include <string>

class BudgetMainApp
{
public:
    BudgetMainApp(std::string usersFileName, std::string incomesFileName, std::string expensesFileName)
    {

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
