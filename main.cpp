#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main() {

    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");

    char choice;

    while (true) {
        if (!personalBudget.isUserLoggedIn()) {
            choice = personalBudget.selectOptionFromMainMenu();

            switch (choice) {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogging();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = personalBudget.selectOptionFromUserMenu();

            switch (choice) {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.viewCurrentMonthBalance();
                break;
            case '4':
                personalBudget.viewPreviousMonthBalance();
                break;
            case '5':
                personalBudget.viewSelectedPeriodBalance();
                break;
            case '6':
                personalBudget.changePasswordLoggedUser();
                break;
            case '7':
                personalBudget.userLogout();
                break;
            }
        }
    }
    return 0;
}
