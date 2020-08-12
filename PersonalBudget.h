#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserManager.h"
#include "IncomesAndExpensesManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;
    IncomesAndExpensesManager *incomesAndExpensesManager;
    const string FILE_NAME_OF_INCOMES;
    const string FILE_NAME_OF_EXPENSES;

public:
    PersonalBudget(string fileNameOfUsers, string fileNameOfIncomes, string fileNameOfExpenses)
        : userManager(fileNameOfUsers),
          FILE_NAME_OF_INCOMES(fileNameOfIncomes),
          FILE_NAME_OF_EXPENSES(fileNameOfExpenses) {
        incomesAndExpensesManager = NULL;
    };
    ~PersonalBudget() {
        delete incomesAndExpensesManager;
        incomesAndExpensesManager = NULL;
    }
    void userRegistration();
    void userLogging();
    void changePasswordLoggedUser();
    void userLogout();
    void addIncome();
    void addExpense();
    void viewCurrentMonthBalance();
    void viewPreviousMonthBalance();
    void viewSelectedPeriodBalance();
    bool isUserLoggedIn();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
};

#endif
