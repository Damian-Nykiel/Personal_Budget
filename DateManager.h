#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <ctime>
#include "AuxiliaryMethods.h"

using namespace std;

class DateManager {
    bool isYearLeap(int year);

public:
    DateManager() {};

    bool checkDateIsCorrect(string date);
    int getTodaysDate();
    int getCurrentMonth();
    int getCurrentYear();
    int getMonthFromDate(string date);
    int getYearFromDate(string date);
    int stringToIntDate(string date);
    string intToStringDate(int date);
};

#endif
