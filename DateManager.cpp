#include "DateManager.h"

int DateManager::getTodaysDate() {

    time_t now = time(0);
    tm *ltm = localtime(&now);

    int date = 0;
    string dateString = "";
    string temporary = "";

    dateString = AuxiliaryMethods::conversionIntToString(getCurrentYear());
    temporary = AuxiliaryMethods::conversionIntToString(getCurrentMonth());
    if (temporary.length() == 1)
        temporary.insert(0, "0");
    dateString += temporary;
    temporary = AuxiliaryMethods::conversionIntToString(ltm->tm_mday);
    if (temporary.length() == 1)
        temporary.insert(0, "0");
    dateString += temporary;
    date = AuxiliaryMethods::conversionStringToInt(dateString);

    return date;
}

int DateManager::getCurrentMonth() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int month = 1 + ltm->tm_mon;
    return month;
}

int DateManager::getCurrentYear() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    return year;
}

bool DateManager::checkDateIsCorrect(string date) {
    string year = date.substr(0,4);
    string month = date.substr(5,2);
    string day = date.substr(8,2);

    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    if (isYearLeap(AuxiliaryMethods::conversionStringToInt(year)) && month == "02") {
        if (day >= "01" && day <= "29")
            return true;
        else
            return false;
    }

    else {
        if (month == "01" || month == "03" || month == "05" || month == "07" || month == "08" || month == "10" || month == "12") {
            if (day >= "01" && day <= "31")
                return true;
            else
                return false;
        } else if (month == "02") {
            if (day >= "01" && day <= "28")
                return true;
            else
                return false;
        } else if (month == "04" || month == "06" || month == "09" || month == "11") {
            if (day >= "01" && day <= "30")
                return true;
            else
                return false;
        } else
            return false;
    }
}

bool DateManager::isYearLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int DateManager::getMonthFromDate(string date) {
    int intMonth = 0;
    string month = "";
    month = date.substr(5,2);
    intMonth = AuxiliaryMethods::conversionStringToInt(month);
    return intMonth;
}
int DateManager::getYearFromDate(string date) {
    int intYear = 0;
    string year = "";
    year = date.substr(0,4);
    intYear = AuxiliaryMethods::conversionStringToInt(year);
    return intYear;
}

int DateManager::stringToIntDate(string date) {
    date.erase(4,1);
    date.erase(6,1);
    int intDate = AuxiliaryMethods::conversionStringToInt(date);
    return intDate;
}
string DateManager::intToStringDate(int date) {
    string stringDate = AuxiliaryMethods::conversionIntToString(date);
    stringDate.insert(4,"-");
    stringDate.insert(7,"-");
    return stringDate;
}
