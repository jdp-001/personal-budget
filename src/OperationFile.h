#pragma once
#include <string>
#include <vector>

#include "Operation.h"
#include "File.h"

class OperationFile : public File
{
public:
    OperationFile(const std::string& fileName);
    std::vector<Operation> loadOperationsFromFile(int loggedUserId);
    bool addOperationToFile(const Operation& operation);
    int getLastOperationId() const;
};
