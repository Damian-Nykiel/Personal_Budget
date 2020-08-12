#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "Income.h"
#include "XMLFile.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"

using namespace std;

class IncomesFile :public XMLFile {
    int lastIncomeId;
    DateManager dateManager;

public:
    IncomesFile(string fileNameOfIncomes) : XMLFile(fileNameOfIncomes) {
        lastIncomeId = 0;
    };
    bool writeIncomeToFile(Income income);
    vector <Income> loadIncomesFromFile(int loggedUserId);
    int getLastIncomeId();
};

#endif
