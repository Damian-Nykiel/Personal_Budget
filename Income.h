#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "Sales.h"

using namespace std;

class Income :public Sales {
    int incomeId;

public:
    Income(int incomeId = 0) : Sales{} {
        this->incomeId = incomeId;
    }

    void setIncomeId(int newIncomeId);
    int getIncomeId();
};

#endif
