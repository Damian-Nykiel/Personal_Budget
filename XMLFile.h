#ifndef XMLFile_H
#define XMLFile_H

#include <iostream>
#include <fstream>

#include "Markup.h"

using namespace std;

class XMLFile {
    const string FILE_NAME;


public:
    CMarkup xml;
    XMLFile(string fileName) : FILE_NAME(fileName) {}

    string getFileName();
    bool isFileEmpty();
};

#endif
