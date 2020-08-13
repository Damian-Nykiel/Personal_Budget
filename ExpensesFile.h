#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "Expense.h"
#include "XMLFile.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"

using namespace std;

class ExpensesFile :public XMLFile {
    int lastExpenseId;
    DateManager dateManager;

public:
    ExpensesFile(string fileNameOfExpenses) : XMLFile(fileNameOfExpenses) {
        lastExpenseId = 0;
    };
    void writeExpenseToFile(Expense expense);
    vector <Expense> loadExpensesFromFile(int loggedUserId);
    int getLastExpenseId();
};

#endif
