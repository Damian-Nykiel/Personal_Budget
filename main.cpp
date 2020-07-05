#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main() {

    //PersonalBudget personalBudget;

    char wybor;

    while (true) {
        if (!personalBudget.czyUzytkownikJestZalogowany()) {
            wybor = personalBudget.wybierzOpcjeZMenuGlownego();

            switch (wybor) {
            case '1':
                personalBudget.rejestracjaUzytkownika();
                break;
            case '2':
                personalBudget.logowanieUzytkownika();
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
            wybor = personalBudget.wybierzOpcjeZMenuUzytkownika();

            switch (wybor) {
            case '1':
                //personalBudget.dodajAdresata();
                break;
            case '2':
                //personalBudget.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                //personalBudget.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                //personalBudget.wyswietlWszystkichAdresatow();
                break;
            case '5':
                //personalBudget.usunAdresata();
                break;
            case '6':
                //personalBudget.edytujAdresata();
                break;
            case '7':
                //personalBudget.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                //personalBudget.wylogowanieUzytkownika();
                break;
            }
        }
    }
    return 0;
}
