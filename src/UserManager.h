#pragma once

class UserManager
{
private:
    int loggedUserId = 0; // Initially no user logged in
public:
    bool isUserLoggedIn();
    int getLoggedUserId() const;
    void loginUser();
    void logoutUser();
    void changeUserPassword();
};
