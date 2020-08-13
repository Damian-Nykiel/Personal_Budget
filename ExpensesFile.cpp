#include "ExpensesFile.h"

bool ExpensesFile::writeExpenseToFile(Expense expense) {
    string date = dateManager.intToStringDate(expense.getDate());
    string stringAmount = AuxiliaryMethods::conversionFloatToString(expense.getAmount());

    bool fileExsits = xml.Load(getFileName());
    if(!fileExsits) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("expenseId", expense.getExpenseId());
    xml.AddElem("userId", expense.getUserId());
    xml.AddElem("date", date);
    xml.AddElem("item", expense.getItem());
    xml.AddElem("amount", stringAmount);
    xml.Save(getFileName());

    lastExpenseId++;
}

vector <Expense> ExpensesFile::loadExpensesFromFile(int loggedUserId) {
    vector <Expense> expenses;
    Expense expense;
    int currentExpenseId = 0;
    int date = 0;
    float amount = 0;

    xml.Load(getFileName());

    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Expense") ) {
        xml.IntoElem();
        xml.FindElem( "expenseId" );
        currentExpenseId = atoi(xml.GetData().c_str());
        xml.FindElem( "userId" );
        if (atoi(xml.GetData().c_str()) == loggedUserId) {
            xml.FindElem( "userId" );
            expense.setUserId(atoi(xml.GetData().c_str()));
            xml.FindElem( "expenseId" );
            expense.setExpenseId(atoi(xml.GetData().c_str()));
            xml.FindElem( "date" );
            date = dateManager.stringToIntDate(xml.GetData());
            expense.setDate(date);
            xml.FindElem( "item" );
            expense.setItem(xml.GetData());
            xml.FindElem( "amount" );
            amount = AuxiliaryMethods::conversionStringToFloat(xml.GetData());
            expense.setAmount(amount);
            xml.OutOfElem();
            expenses.push_back(expense);
        } else
            xml.OutOfElem();
    }
    lastExpenseId = currentExpenseId;

    return expenses;
}

int ExpensesFile::getLastExpenseId() {
    return lastExpenseId;
}
