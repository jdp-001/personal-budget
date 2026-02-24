#pragma once
#include <vector>
#include "User.h"
#include "UserFile.h"

class UserManager
{
private:
    int loggedUserId = 0; // Initially no user logged in
    std::vector<User> users;
    UserFile userFile;

public:
    UserManager(const std::string& fileName);
    bool isUserLoggedIn();
    int getLoggedUserId() const;
    void loginUser();
    void logoutUser();
    void changeUserPassword();
    void registerUser();
    bool ifLoginExists(const std::string& login) const;
};
