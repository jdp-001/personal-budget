#pragma once
#include <string>
#include <vector>

#include "Operation.h"

class OperationFile
{
private:
    const std::string FILE_NAME;


public:
    OperationFile(const std::string& fileName) : FILE_NAME(fileName) {}

    std::vector<Operation> loadOperationsFromFile(int loggedUserId);
    bool addOperationToFile(const Operation& operation);
    int getLastOperationId() const;
};
