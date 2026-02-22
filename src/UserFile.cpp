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

    /// TEST ///
    std::cout << "Users loaded: " << users.size() << std::endl;
    system("pause");
    /// END OF TEST ///

    return users;
}
