#include "OperationFile.h" // class declaration
#include "Markup.h"

OperationFile::OperationFile(const std::string& fileName)
    : File(fileName)
{
    lastId = getLastOperationId();
}

bool OperationFile::addOperationToFile(const Operation& operation)
{
    // 1. Load(FILE_NAME)
    Operation op = operation;
    op.id = ++lastId;
    bool fileExists = xmlDoc.Load(FILE_NAME);

    // 2. If doesn't exist → SetDoc("<Operations></Operations>")
    if (!fileExists)
    {
        xmlDoc.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<Operations></Operations>");
    }

    // 3. Go into <Operations>
    xmlDoc.FindElem("Operations");
    xmlDoc.IntoElem();

    // 4. Add <Operation> + all fields
    xmlDoc.AddElem("Operation");
    xmlDoc.IntoElem();

    xmlDoc.AddElem("Id", op.id);
    xmlDoc.AddElem("UserId", op.userId);
    xmlDoc.AddElem("Date", op.date);
    xmlDoc.AddElem("Item", op.item);
    xmlDoc.AddElem("Amount", op.amount);

    xmlDoc.OutOfElem();

    // 5. Save(FILE_NAME) and return result
    return xmlDoc.Save(FILE_NAME);
}

int OperationFile::getLastOperationId()
{
    // Open file, if doesn't exist return 0;
    if (!xmlDoc.Load(FILE_NAME)) return 0;

    // Find Operations and Go into it, if doesn't exist return 0;
    if (!xmlDoc.FindElem("Operations")) return 0;
    xmlDoc.IntoElem();

    int lastId = 0;

    // In a loop find Operation in Operations
    // and find Id (and remember the last one)
    while (xmlDoc.FindElem("Operation"))
    {
        xmlDoc.IntoElem();
        xmlDoc.FindElem("Id");
        lastId = std::stoi(xmlDoc.GetData());
        xmlDoc.OutOfElem();
    }

    // Return Id (the last one)
    return lastId;

}

std::vector<Operation> OperationFile::loadOperationsFromFile(int loggedUserId)
{
    std::vector<Operation> operations;

    if (!xmlDoc.Load(FILE_NAME)) return operations;

    if (!xmlDoc.FindElem("Operations")) return operations;
    xmlDoc.IntoElem();

    while (xmlDoc.FindElem("Operation"))
    {
        Operation op;
        xmlDoc.IntoElem();

        xmlDoc.FindElem("Id");
        op.id = std::stoi(xmlDoc.GetData());

        xmlDoc.FindElem("UserId");
        op.userId = std::stoi(xmlDoc.GetData());

        xmlDoc.FindElem("Date");
        op.date = std::stoi(xmlDoc.GetData());

        xmlDoc.FindElem("Item");
        op.item = xmlDoc.GetData();

        xmlDoc.FindElem("Amount");
        op.amount = std::stod(xmlDoc.GetData());

        if (op.userId == loggedUserId)
            operations.push_back(op);

        xmlDoc.OutOfElem();

    }

    return operations;
}
