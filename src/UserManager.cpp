#include "UserManager.h" // class declaration
#include "Utils.h"

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
    //loggedUserId = 1; // Temporary for testing purposes
    std::cout << "Enter login: ";
    std::string login = Utils::readLine();

    for (const User& user : users)
    {
        if (user.login == login)
        {
            std::cout << "User found." << std::endl;

            std::string password = "";
            for (int attempt = 1; attempt <=3; ++attempt)
            {
                std::cout << "Enter password: ";
                password = Utils::readLine();

                if (user.password == password)
                {
                    loggedUserId = user.id;
                    std::cout << "You are logged in." << std::endl;
                    system("pause");
                    return;
                }
                else
                {
                    if (attempt < 3)
                    {
                        std::cout << "Incorrect password. Attempts remaining: " << 3 - attempt << std::endl;
                    }
                    else
                    {
                        std::cout << "3 times invalid password..." << std::endl;
                        system("pause");
                        return;
                    }
                }
            }
        }
    }

    std::cout << "User does not exist." << std::endl;
    system("pause");
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

UserManager::UserManager(const std::string& fileName)
    : userFile(fileName)
{
    users = userFile.loadUsersFromFile();
}

void UserManager::registerUser()
{
    std::cout << "Enter login: ";
    std::string login = Utils::readLine();

    if (login.empty())
    {
        std::cout << "Login cannot be empty." << std::endl;
        system("pause");
        return;
    }

    if (ifLoginExists(login))
    {
        std::cout << "Login already exists." << std::endl;
        system("pause");
        return;
    }

    std::cout << "Enter password: ";
    std::string password = Utils::readLine();

    if (password.empty())
    {
        std::cout << "Password cannot be empty." << std::endl;
        system("pause");
        return;
    }

    std::cout << "Enter first name: ";
    std::string firstName = Utils::readLine();

    std::cout << "Enter last name: ";
    std::string lastName = Utils::readLine();

    int newUserId = 1;

    if (!users.empty())
    newUserId = users.back().id + 1;

    User newUser;

    newUser.id = newUserId;
    newUser.login = login;
    newUser.password = password;
    newUser.firstName = firstName;
    newUser.lastName = lastName;

    users.push_back(newUser);
    userFile.appendUserToFile(newUser);

    std::cout << "Registration successful." << std::endl;
    system("pause");
}

bool UserManager::ifLoginExists(const std::string& login) const
{
    for (const User& user : users)
    {
        if (user.login == login)
            return true;
    }
    return false;
}

