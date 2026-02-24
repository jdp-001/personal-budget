#pragma once
#include <vector>
#include <string>
#include "User.h"

class UserFile
{
private:
    std::string fileName;

public:
    UserFile(const std::string& fileName);
    std::vector<User> loadUsersFromFile();
    void appendUserToFile(const User& user);
};
