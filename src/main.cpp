#include <iostream>

#include "BudgetMainApp.h"
#include "Utils.h"

using namespace std;

char selectOptionsFromMainMenu();
char selectOptionsFromUserMenu();

int main()
{
    char choice;

    BudgetMainApp budgetMainApp("users.xml", "incomes.xml", "expenses.xml");

    while (true)
    {
        if (!budgetMainApp.isUserLoggedIn())
        {
            choice = selectOptionsFromMainMenu();

            switch (choice)
            {
            case '1':
                budgetMainApp.registerUser();
                break;
            case '2':
                budgetMainApp.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = selectOptionsFromUserMenu();

            switch (choice)
            {
            case '1':
                budgetMainApp.addIncome();
                break;
            case '2':
                budgetMainApp.addExpense();
                break;
            case '3':
                budgetMainApp.showCurrentMonthBalance();
                break;
            case '4':
                budgetMainApp.showPreviousMonthBalance();
                break;
            case '5':
                budgetMainApp.showCustomPeriodBalance();
                break;
            case '6':
                budgetMainApp.changeUserPassword();
                break;
            case '7':
                budgetMainApp.logoutUser();
                break;
            }
        }
    }
    return 0;
}

char selectOptionsFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Sign up" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Quit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = Utils::getCharacter();

    return choice;
}

char selectOptionsFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Show current month's balance" << endl;
    cout << "4. Show previous month's balance" << endl;
    cout << "5. Show customer period's balance" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = Utils::getCharacter();

    return choice;
}
