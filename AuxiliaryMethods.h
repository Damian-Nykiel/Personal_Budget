#ifndef AUXILIATYMETHODS_H
#define AUXILIATYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods {
public:
    static char loadCharacter();
    static int loadIntegerNumber();
    static int conversionStringToInt(string liczba);
    static string loadLine();
    static string conversionIntToString(int liczba);
    static string loadNumber(string tekst, int pozycjaZnaku);
    static string changeFirstLetterToUpperOtherToLower(string tekst);
    static float conversionStringToFloat (string tekst);
};

#endif
