#include "Income.h"

using namespace std;

void Income::setIncomeId(int newIncomeId) {
    if (newIncomeId >= 0)
        incomeId = newIncomeId;
}

int Income::getIncomeId() {
    return incomeId;
}
