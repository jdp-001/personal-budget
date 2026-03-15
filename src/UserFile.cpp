#include "UserFile.h"
#include "Markup.h"

#include <iostream>

UserFile::UserFile(const std::string& fileName):
    File(fileName)
{

}

std::vector<User> UserFile::loadUsersFromFile()
{
    bool fileExists = xmlDoc.Load(FILE_NAME);
    std::vector<User> users;

    if (!fileExists)
    {
        return {};
    }

    xmlDoc.FindElem("Users");
    xmlDoc.IntoElem();

    while (xmlDoc.FindElem("User"))
    {
        xmlDoc.IntoElem();

        // Read data of individual user from xmlDoc
        User user;

        xmlDoc.FindElem("UserId");
        user.id = std::stoi(xmlDoc.GetData());

        xmlDoc.FindElem("FirstName");
        user.firstName = xmlDoc.GetData();

        xmlDoc.FindElem("LastName");
        user.lastName = xmlDoc.GetData();

        xmlDoc.FindElem("Login");
        user.login = xmlDoc.GetData();

        xmlDoc.FindElem("Password");
        user.password = xmlDoc.GetData();

        users.push_back(user);

        xmlDoc.OutOfElem();
    }
    return users;
}

void UserFile::appendUserToFile(const User& user)
{
    bool fileExists = xmlDoc.Load(FILE_NAME);

    if (!fileExists)
    {
        xmlDoc.SetDoc("<?xmlDoc version=\"1.0\" encoding=\"UTF-8\"?>\n<Users></Users>");
    }

    xmlDoc.FindElem("Users");
    xmlDoc.IntoElem();

    xmlDoc.AddElem("User");
    xmlDoc.IntoElem();

    xmlDoc.AddElem("UserId", user.id);
    xmlDoc.AddElem("FirstName", user.firstName);
    xmlDoc.AddElem("LastName", user.lastName);
    xmlDoc.AddElem("Login", user.login);
    xmlDoc.AddElem("Password", user.password);

    xmlDoc.OutOfElem(); // out of User
    xmlDoc.OutOfElem(); // out of Users

    xmlDoc.Save(FILE_NAME);
}

void UserFile::saveAllUsersToFile(const std::vector<User>& users)
{
    xmlDoc.AddElem("Users");
    xmlDoc.IntoElem();

    for (const User& user : users)
    {
        xmlDoc.AddElem("User");
        xmlDoc.IntoElem();

        xmlDoc.AddElem("UserId", user.id);
        xmlDoc.AddElem("FirstName", user.firstName);
        xmlDoc.AddElem("LastName", user.lastName);
        xmlDoc.AddElem("Login", user.login);
        xmlDoc.AddElem("Password", user.password);

        xmlDoc.OutOfElem(); // out of User
    }

    xmlDoc.OutOfElem(); // out of Users

    xmlDoc.Save(FILE_NAME);
}
