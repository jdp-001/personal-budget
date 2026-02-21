#include "Utils.h"

#include <iostream>

char Utils::getCharacter()
{
    std::string input = "";
    char character = {0};

    while (true)
    {
        getline(std::cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        std::cout << "This is not a single character. Enter again." << std::endl;
    }
    return character;
}

std::string Utils::getLine()
{
    std::string input = "";
    std::getline(std::cin, input);
    return input;
}

std::string Utils::trim(const std::string& text)
{
    size_t start = text.find_first_not_of(" \t");
    size_t end = text.find_last_not_of(" \t");

    if (start == std::string::npos)
        return "";

    return text.substr(start, end - start + 1);
}
