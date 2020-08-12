#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "Sales.h"

using namespace std;

class Expense :public Sales {
    int expenseId;

public:
    Expense(int expenseId = 0) : Sales{} {
        this->expenseId = expenseId;
    }

    void setExpenseId(int newExpenseId);
    int getExpenseId();

};

#endif
