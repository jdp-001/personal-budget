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
    CMarkup xml;

    Operation op = operation;
    op.id = ++lastId;
    bool fileExists = xml.Load(FILE_NAME);

    // 2. If doesn't exist → SetDoc("<Operations></Operations>")
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<Operations></Operations>");
    }

    // 3. Go into <Operations>
    xml.FindElem("Operations");
    xml.IntoElem();

    // 4. Add <Operation> + all fields
    xml.AddElem("Operation");
    xml.IntoElem();

    xml.AddElem("Id", op.id);
    xml.AddElem("UserId", op.userId);
    xml.AddElem("Date", op.date);
    xml.AddElem("Item", op.item);
    xml.AddElem("Amount", op.amount);

    xml.OutOfElem();

    // 5. Save(FILE_NAME) and return result
    return xml.Save(FILE_NAME);
}

int OperationFile::getLastOperationId() const
{
    // Open file, if doesn't exist return 0;
    CMarkup xml;
    if (!xml.Load(FILE_NAME)) return 0;

    // Find Operations and Go into it, if doesn't exist return 0;
    if (!xml.FindElem("Operations")) return 0;
    xml.IntoElem();

    int lastId = 0;

    // In a loop find Operation in Operations
    // and find Id (and remember the last one)
    while (xml.FindElem("Operation"))
    {
        xml.IntoElem();
        xml.FindElem("Id");
        lastId = std::stoi(xml.GetData());
        xml.OutOfElem();
    }

    // Return Id (the last one)
    return lastId;

}

std::vector<Operation> OperationFile::loadOperationsFromFile(int loggedUserId)
{
    std::vector<Operation> operations;

    CMarkup xml;

    if (!xml.Load(FILE_NAME)) return operations;

    if (!xml.FindElem("Operations")) return operations;
    xml.IntoElem();

    while (xml.FindElem("Operation"))
    {
        Operation op;
        xml.IntoElem();

        xml.FindElem("Id");
        op.id = std::stoi(xml.GetData());

        xml.FindElem("UserId");
        op.userId = std::stoi(xml.GetData());

        xml.FindElem("Date");
        op.date = std::stoi(xml.GetData());

        xml.FindElem("Item");
        op.item = xml.GetData();

        xml.FindElem("Amount");
        op.amount = std::stod(xml.GetData());

        if (op.userId == loggedUserId)
            operations.push_back(op);

        xml.OutOfElem();

    }

    return operations;
}
