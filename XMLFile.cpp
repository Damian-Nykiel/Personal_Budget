#include "XMLFile.h"

string XMLFile::getFileName() {
    return FILE_NAME;
}

bool XMLFile::isFileEmpty() {
    bool fileExists = xml.Load(FILE_NAME);
    return fileExists;
}
