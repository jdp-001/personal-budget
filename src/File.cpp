#include "File.h"

void File::checkRootNode()
{
    if (!xmlDoc.Load(FILE_NAME))
    {
        xmlDoc.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
    }
}
