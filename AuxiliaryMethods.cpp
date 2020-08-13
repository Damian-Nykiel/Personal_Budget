#include "AuxiliaryMethods.h"

int AuxiliaryMethods::conversionStringToInt(string number) {
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;

    return intNumber;
}

string AuxiliaryMethods::conversionIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::loadLine() {
    cin.sync();
    string input = "";
    getline(cin, input);
    return input;
}

char AuxiliaryMethods::loadCharacter() {
    cin.sync();
    string input = "";
    char character  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}


string AuxiliaryMethods::changeFirstLetterToUpperOtherToLower(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string AuxiliaryMethods::loadNumber(string text, int characterPosition) {
    string number = "";
    while(isdigit(text[characterPosition])) {
        number += text[characterPosition];
        characterPosition ++;
    }
    return number;
}

int AuxiliaryMethods::loadIntegerNumber() {
    string input = "";
    int number = 0;

    while (true) {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

float AuxiliaryMethods::conversionStringToFloat(string tekst) {
    return atof(tekst.c_str());
}

string AuxiliaryMethods::conversionFloatToString(float myFloat) {
    stringstream ss;
    ss << myFloat;
    return ss.str();
}
