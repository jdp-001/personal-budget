#include "UserFile.h"
#include "Markup.h"

#include <iostream>

UserFile::UserFile(const std::string& fileName):
    fileName(fileName)
{

}

std::vector<User> UserFile::loadUsersFromFile()
{
    CMarkup xml;
    bool fileExists = xml.Load(fileName);
    std::vector<User> users;

    if (!fileExists)
    {
        return {};
    }

    xml.FindElem("Users");
    xml.IntoElem();

    while (xml.FindElem("User"))
    {
        xml.IntoElem();

        // Read data of individual user from XML
        User user;

        xml.FindElem("UserId");
        user.id = std::stoi(xml.GetData());

        xml.FindElem("FirstName");
        user.firstName = xml.GetData();

        xml.FindElem("LastName");
        user.lastName = xml.GetData();

        xml.FindElem("Login");
        user.login = xml.GetData();

        xml.FindElem("Password");
        user.password = xml.GetData();

        users.push_back(user);

        xml.OutOfElem();
    }
    return users;
}

void UserFile::appendUserToFile(const User& user)
{
    CMarkup xml;
    bool fileExists = xml.Load(fileName);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<Users></Users>");
    }

    xml.FindElem("Users");
    xml.IntoElem();

    xml.AddElem("User");
    xml.IntoElem();

    xml.AddElem("UserId", user.id);
    xml.AddElem("FirstName", user.firstName);
    xml.AddElem("LastName", user.lastName);
    xml.AddElem("Login", user.login);
    xml.AddElem("Password", user.password);

    xml.OutOfElem(); // out of User
    xml.OutOfElem(); // out of Users

    xml.Save(fileName);
}

void UserFile::saveAllUsersToFile(const std::vector<User>& users)
{
    CMarkup xml;

    xml.AddElem("Users");
    xml.IntoElem();

    for (const User& user : users)
    {
        xml.AddElem("User");
        xml.IntoElem();

        xml.AddElem("UserId", user.id);
        xml.AddElem("FirstName", user.firstName);
        xml.AddElem("LastName", user.lastName);
        xml.AddElem("Login", user.login);
        xml.AddElem("Password", user.password);

        xml.OutOfElem(); // out of User
    }

    xml.OutOfElem(); // out of Users

    xml.Save(fileName);
}
