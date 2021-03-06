#include "Sales.h"

using namespace std;

void Sales::setUserId(int newUserId) {
    if (newUserId >= 0)
        userId = newUserId;
}

void Sales::setDate(int newDate) {
    date = newDate;
}

void Sales::setItem(string newItem) {
    item = newItem;
}

void Sales::setAmount(float newAmount) {
    amount = newAmount;
}

int Sales::getUserId() {
    return userId;
}

int Sales::getDate() {
    return date;
}

string Sales::getItem() {
    return item;
}

float Sales::getAmount() {
    return amount;
}
