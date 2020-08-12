#include "IncomesAndExpensesManager.h"

void IncomesAndExpensesManager::addIncome() {
    Income income;

    system("cls");
    cout << "          >> DODAWANIE PRZYCHODU << " << endl << endl;
    income = getNewIncomeDetails();

    incomes.push_back(income);
    if (incomesFile.writeIncomeToFile(income))
        cout << "Nowy przychod zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego przychodu do pliku." << endl;
    system("pause");
}

Income IncomesAndExpensesManager::getNewIncomeDetails() {
    Income income;
    char choice;

    int intDate = 0;
    string date = "";
    string item = "";
    string amount = "";

    cout << "Czy przychod dotyczy dnia dzisiejszego?" << endl << "jezeli tak wybierz: 't', jezeli nie wybierz: 'n'" << endl;
    cin >> choice;

    if(choice == 't') {
        intDate = dateManager.getTodaysDate();
    } else if (choice == 'n') {
        do {
            cout << "Podaj date przychodu w formacie: RRRR-MM-DD" << endl;
            date = AuxiliaryMethods::loadLine();
            if(dateManager.checkDateIsCorrect(date)) {
                intDate = dateManager.stringToIntDate(date);
            } else {
                cout << "Niepoprawny format daty. Zapisz date w formacie: RRRR-MM-DD" << endl;
                system("Pause");
            }
        } while(!dateManager.checkDateIsCorrect(date));
    }
    cout << "Czego dotyczy przychod?" << endl;
    item = AuxiliaryMethods::loadLine();

    cout << "Podaj wartosc przychodu: " << endl;
    amount = AuxiliaryMethods::loadLine();
    amount = checkAmount(amount);

    income.setIncomeId(incomesFile.getLastIncomeId()+1);
    income.setUserId(LOGGED_USER_ID);
    income.setDate(intDate);
    income.setItem(item);
    income.setAmount(amount);

    return income;
}

void IncomesAndExpensesManager::addExpense() {
    Expense expense;

    system("cls");
    cout << "          >> DODAWANIE WYDATKU << " << endl << endl;
    expense = getNewExpenseDetails();

    expenses.push_back(expense);
    if (expensesFile.writeExpenseToFile(expense))
        cout << "Nowy wydatek zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego wydatku do pliku." << endl;
    system("pause");
}

Expense IncomesAndExpensesManager::getNewExpenseDetails() {
    Expense expense;

    char choice;
    int intDate = 0;
    string date = "";
    string item = "";
    string amount = "";

    cout << "Czy wydatek dotyczy dnia dzisiejszego?" << endl << "jezeli tak wybierz: 't', jezeli nie wybierz: 'n'" << endl;
    cin >> choice;

    if(choice == 't') {
        intDate = dateManager.getTodaysDate();
    } else if (choice == 'n') {
        do {
            cout << "Podaj date wydatku w formacie: RRRR-MM-DD" << endl;
            date = AuxiliaryMethods::loadLine();
            if(dateManager.checkDateIsCorrect(date)) {
                intDate = dateManager.stringToIntDate(date);
            } else {
                cout << "Niepoprawny format daty. Zapisz date w formacie: RRRR-MM-DD" << endl;
                system("Pause");
            }
        } while(!dateManager.checkDateIsCorrect(date));
    }

    cout << "Czego dotyczy wydatek?" << endl;
    item = AuxiliaryMethods::loadLine();

    cout << "Podaj wartosc wydatku: " << endl;
    amount = AuxiliaryMethods::loadLine();
    amount = checkAmount(amount);

    expense.setExpenseId(expensesFile.getLastExpenseId()+1);
    expense.setUserId(LOGGED_USER_ID);
    expense.setDate(intDate);
    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
}

string IncomesAndExpensesManager::checkAmount(string amount) {
    for (int i = 0; i < amount.length(); i++) {
        if (amount[i] == ',')
            amount[i] = '.';
    }
    return amount;
}

void IncomesAndExpensesManager::viewCurrentMonthBalance() {
    float balance = 0;
    system("cls");

    cout << "        >> PRZYCHODY ZA BIEZACY MIESIAC << " << endl << endl;
    cout << "--------------------------------------" << endl;
    balance += selectedMonthIncomes(dateManager.getCurrentMonth());
    cout << endl << "        >> WYDATKI ZA BIEZACY MIESIAC << " << endl << endl;
    cout << "--------------------------------------" << endl;
    balance -= selectedMonthExpenses(dateManager.getCurrentMonth());
    cout << "--------------------------------------" << endl;
    cout << "Bilans biezacego miesiaca wynosi: " << balance << " PLN" << endl;
    cout << "--------------------------------------" << endl << endl;
    system("pause");
}

float IncomesAndExpensesManager::selectedMonthIncomes(int month) {
    string date = "";
    float amountSum = 0;

    if (!incomes.empty()) {
        sort(incomes.begin(),incomes.end());
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            date = dateManager.intToStringDate(itr -> getDate());
            if (dateManager.getYearFromDate(date) == dateManager.getCurrentYear() && dateManager.getMonthFromDate(date) == month) {
                displayIncome(*itr);
                amountSum += AuxiliaryMethods::conversionStringToFloat(itr -> getAmount());
            } else
                continue;
        }
        cout << endl << "Przychody razem: " << amountSum << " PLN" << endl << endl;
        return amountSum;
    } else {
        cout << endl << "Brak przychodow." << endl << endl;
        return 0;
    }
}

float IncomesAndExpensesManager::selectedMonthExpenses(int month) {
    string date = "";
    float amountSum = 0;

    if (!expenses.empty()) {
        sort(expenses.begin(),expenses.end());
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            date = dateManager.intToStringDate(itr -> getDate());
            if (dateManager.getYearFromDate(date) == dateManager.getCurrentYear() && dateManager.getMonthFromDate(date) == month) {
                displayExpense(*itr);
                amountSum += AuxiliaryMethods::conversionStringToFloat(itr -> getAmount());
            } else
                continue;
        }
        cout << endl << "Wydatki razem: " << amountSum << " PLN" << endl << endl;
        return amountSum;
    } else {
        cout << endl << "Brak przychodow." << endl << endl;
        return 0;
    }
}

void IncomesAndExpensesManager::viewPreviousMonthBalance() {
    float balance = 0;
    system("cls");

    cout << "        >> PRZYCHODY ZA POPRZEDNI MIESIAC << " << endl << endl;
    cout << "--------------------------------------" << endl;
    balance += selectedMonthIncomes(dateManager.getCurrentMonth()-1);
    cout << endl << "        >> WYDATKI ZA POPRZEDNI MIESIAC << " << endl << endl;
    cout << "--------------------------------------" << endl;
    balance -= selectedMonthExpenses(dateManager.getCurrentMonth()-1);
    cout << "--------------------------------------" << endl;
    cout << "Bilans poprzedniego miesiaca wynosi: " << balance << " PLN" << endl;
    cout << "--------------------------------------" << endl << endl;
    system("pause");
}

void IncomesAndExpensesManager::viewSelectedPeriodBalance() {
    string startingDate = "";
    string endDate = "";

    system("cls");
    cout << "Podaj date poczatkowa w formacie: RRRR-MM-DD" << endl;
    startingDate = AuxiliaryMethods::loadLine();
    do {
        if(dateManager.checkDateIsCorrect(startingDate)) {
            cout << "Podaj date koncowa w formacie: RRRR-MM-DD" << endl;
            endDate = AuxiliaryMethods::loadLine();
            do {
                if(dateManager.checkDateIsCorrect(endDate)) {
                    float balance = 0;
                    system("cls");
                    cout << "        >> PRZYCHODY ZA OKRES OD: " << startingDate << " DO: " << endDate << " << " << endl << endl;
                    cout << "--------------------------------------" << endl;
                    balance += selectedPeroidIncomes(dateManager.stringToIntDate(startingDate),dateManager.stringToIntDate(endDate));
                    cout << endl << "        >> WYDATKI ZA OKRES OD: " << startingDate << " DO: " << endDate << " << " << endl << endl;
                    cout << "--------------------------------------" << endl;
                    balance -= selectedPeroidExpenses(dateManager.stringToIntDate(startingDate),dateManager.stringToIntDate(endDate));
                    cout << "--------------------------------------" << endl;
                    cout << "Bilans wybranego okresu wynosi: " << balance << " PLN" << endl;
                    cout << "--------------------------------------" << endl << endl;
                    system("pause");
                } else {
                    cout << "Niepoprawny format daty. Zapisz date w formacie: RRRR-MM-DD" << endl;
                    system("Pause");
                }
            } while(!dateManager.checkDateIsCorrect(endDate));
        } else {
            cout << "Niepoprawny format daty. Zapisz date w formacie: RRRR-MM-DD" << endl;
            system("Pause");
        }
    } while(!dateManager.checkDateIsCorrect(startingDate));
}

float IncomesAndExpensesManager::selectedPeroidIncomes(int startingDate, int endDate) {
    float amountSum = 0;

    if (!incomes.empty()) {
        sort(incomes.begin(),incomes.end());
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            if (itr -> getDate() >= startingDate  && itr -> getDate() <= endDate) {
                displayIncome(*itr);
                amountSum += AuxiliaryMethods::conversionStringToFloat(itr -> getAmount());
            } else
                continue;
        }
        cout << endl << "Przychody razem: " << amountSum << " PLN" << endl << endl;
        return amountSum;
    } else {
        cout << endl << "Brak przychodow." << endl << endl;
        return 0;
    }
}

float IncomesAndExpensesManager::selectedPeroidExpenses(int startingDate, int endDate) {
    float amountSum = 0;

    if (!expenses.empty()) {
        sort(expenses.begin(),expenses.end());
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            if (itr -> getDate() >= startingDate  && itr -> getDate() <= endDate) {
                displayExpense(*itr);
                amountSum += AuxiliaryMethods::conversionStringToFloat(itr -> getAmount());
            } else
                continue;
        }
        cout << endl << "Wydatki razem: " << amountSum << " PLN" << endl << endl;
        return amountSum;
    } else {
        cout << endl << "Brak przychodow." << endl << endl;
        return 0;
    }
}

void IncomesAndExpensesManager::displayIncome(Income income) {
    cout << endl << "Id przychodu: " << income.getIncomeId() << endl;
    cout <<         "Data:         " << dateManager.intToStringDate(income.getDate()) << endl;
    cout <<         "Przedmiot:    " << income.getItem() << endl;
    cout <<         "Wartosc:      " << income.getAmount() << endl;
}

void IncomesAndExpensesManager::displayExpense(Expense expense) {
    cout << endl << "Id wydatku:   " << expense.getExpenseId() << endl;
    cout <<         "Data:         " << dateManager.intToStringDate(expense.getDate()) << endl;
    cout <<         "Przedmiot:    " << expense.getItem() << endl;
    cout <<         "Wartosc:      " << expense.getAmount() << endl;
}
