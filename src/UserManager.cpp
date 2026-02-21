#include "UserManager.h" // class declaration
#include <iostream>

bool UserManager::isUserLoggedIn()
{
    return loggedUserId != 0;
}

int UserManager::getLoggedUserId() const
{
    return loggedUserId;
}

void UserManager::loginUser()
{
    loggedUserId = 1; // Temporary for testing purposes
}

void UserManager::logoutUser()
{
    loggedUserId = 0;
}

void UserManager::changeUserPassword()
{
    if (!isUserLoggedIn())
    {
        std::cout << "No user is logged in." << std::endl;
        return;
    }

    std::cout << "Password change function called." << std::endl;
    system("pause"); // Temporary for testing purposes
}

