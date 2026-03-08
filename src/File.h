#pragma once
#include <string>

class File
{
protected:
    const std::string FILE_NAME;
    int lastId;

public:
    File(const std::string& fileName)
        : FILE_NAME(fileName), lastId(0) {}
};

