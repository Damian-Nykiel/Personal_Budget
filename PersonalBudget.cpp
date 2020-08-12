#include "PersonalBudget.h"

void PersonalBudget::userRegistration() {
    userManager.userRegistration();
}

void PersonalBudget::userLogging() {
    userManager.userLogging();
    if (userManager.isUserLoggedIn()) {
        incomesAndExpensesManager = new IncomesAndExpensesManager(FILE_NAME_OF_INCOMES,FILE_NAME_OF_EXPENSES, userManager.getLoggedUserId());
    }
}

void PersonalBudget::changePasswordLoggedUser() {
    userManager.changePasswordLoggedUser();
}

void PersonalBudget::userLogout() {
    userManager.userLogout();
    delete incomesAndExpensesManager;
    incomesAndExpensesManager = NULL;
}

void PersonalBudget::addIncome() {
    if (userManager.isUserLoggedIn()) {
        incomesAndExpensesManager->addIncome();
    } else {
        cout << "Aby dodac przychod, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::addExpense() {
    if (userManager.isUserLoggedIn()) {
        incomesAndExpensesManager->addExpense();
    } else {
        cout << "Aby dodac wydatek, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::viewCurrentMonthBalance() {
    if (userManager.isUserLoggedIn()) {
        incomesAndExpensesManager->viewCurrentMonthBalance();
    }
}

void PersonalBudget::viewPreviousMonthBalance() {
    if (userManager.isUserLoggedIn()) {
        incomesAndExpensesManager->viewPreviousMonthBalance();
    }
}

void PersonalBudget::viewSelectedPeriodBalance() {
    if (userManager.isUserLoggedIn()) {
        incomesAndExpensesManager->viewSelectedPeriodBalance();
    }
}

bool PersonalBudget::isUserLoggedIn() {
    if (userManager.isUserLoggedIn())
        return true;
    else
        return false;
}

char PersonalBudget::selectOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

char PersonalBudget::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca " << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}
