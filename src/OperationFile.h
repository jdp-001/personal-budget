#pragma once
#include <string>

class OperationFile
{
private:
    const std::string FILE_NAME;
    int getLastOperationId() const;

public:
    OperationFile(const std::string& fileName) : FILE_NAME(fileName) {}
};
