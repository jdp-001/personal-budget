#include "BudgetMainApp.h"

#include <iostream>

using namespace std;

bool BudgetMainApp::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

void BudgetMainApp::registerUser()
{
    userManager.registerUser();
}

void BudgetMainApp::loginUser()
{
    userManager.loginUser(); // Call UserManager method

    if (userManager.isUserLoggedIn())
    {
        if (budgetManager != nullptr)
        {
            delete budgetManager;
            budgetManager = nullptr;
        }
        budgetManager = new BudgetManager("incomes.xml", "expenses.xml", userManager.getLoggedUserId());
    }
}

void BudgetMainApp::logoutUser()
{
    userManager.logoutUser();
    delete budgetManager;
    budgetManager = nullptr;
}

void BudgetMainApp::addIncome()
{
    if (budgetManager != nullptr)
    {
        //budgetManager->addIncomeTest();
        budgetManager->addIncome();
        system("pause");
    }
}

void BudgetMainApp::addExpense()
{
    cout << "TODO" << endl;
}

void BudgetMainApp::showCurrentMonthBalance()
{
    //cout << "TODO" << endl;
    budgetManager->showCurrentMonthBalance();
    system("pause");
}

void BudgetMainApp::showPreviousMonthBalance()
{
    //cout << "TODO" << endl;
    budgetManager->showPreviousMonthBalance();
    system("pause");
}

void BudgetMainApp::showCustomPeriodBalance()
{
    cout << "TODO" << endl;
}

void BudgetMainApp::changeUserPassword()
{
    userManager.changeUserPassword();
}
