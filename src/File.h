#pragma once
#include <string>

#include "Markup.h"

class File
{
protected:
    const std::string FILE_NAME;
    int lastId;
    CMarkup xmlDoc;

    void checkRootNode();

public:
    File(const std::string& fileName)
        : FILE_NAME(fileName), lastId(0) {}

};

