#ifndef INCOMESANDEXPENSESMANAGER_H
#define INCOMESANDEXPENSESMANAGER_H

#include <iostream>
#include <sstream>
#include <vector>
#include <windows.h>
#include <iomanip>

#include "Income.h"
#include "Expense.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "DateManager.h"

using namespace std;

class IncomesAndExpensesManager {
    const int LOGGED_USER_ID;

    IncomesFile incomesFile;
    vector <Income> incomes;
    ExpensesFile expensesFile;
    vector <Expense> expenses;
    DateManager dateManager;

    Income getNewIncomeDetails();
    Expense getNewExpenseDetails();
    string changeDotToComma(string text);
    bool isAmountANumber(string stringAmount);
    float selectedMonthIncomes(int month);
    float selectedMonthExpenses(int month);
    float selectedPeroidIncomes(int startingDate, int endDate);
    float selectedPeroidExpenses(int startingDate, int endDate);
    void displayIncome(Income income);
    void displayExpense(Expense expense);

public:
    IncomesAndExpensesManager(string fileNameOfIncomes, string fileNameOfExpenses, int loggedUserId)
        : LOGGED_USER_ID(loggedUserId), incomesFile(fileNameOfIncomes), expensesFile(fileNameOfExpenses) {
        incomes = incomesFile.loadIncomesFromFile(LOGGED_USER_ID);
        expenses = expensesFile.loadExpensesFromFile(LOGGED_USER_ID);
    };

    void addIncome();
    void addExpense();
    void viewCurrentMonthBalance();
    void viewPreviousMonthBalance();
    void viewSelectedPeriodBalance();
};

#endif
