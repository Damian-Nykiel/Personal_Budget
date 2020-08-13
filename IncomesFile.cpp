#include "IncomesFile.h"

bool IncomesFile::writeIncomeToFile(Income income) {
    string date = dateManager.intToStringDate(income.getDate());
    string stringAmount = AuxiliaryMethods::conversionFloatToString(income.getAmount());

    bool fileExsits = xml.Load(getFileName());
    if(!fileExsits) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("incomeId", income.getIncomeId());
    xml.AddElem("userId", income.getUserId());
    xml.AddElem("date", date);
    xml.AddElem("item", income.getItem());
    xml.AddElem("amount", stringAmount);
    xml.Save(getFileName());

    lastIncomeId++;
}

vector <Income> IncomesFile::loadIncomesFromFile(int loggedUserId) {
    vector <Income> incomes;
    Income income;
    int currentIncomeId = 0;
    int date = 0;
    float amount = 0;

    xml.Load(getFileName());

    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Income") ) {
        xml.IntoElem();
        xml.FindElem( "incomeId" );
        currentIncomeId = atoi(xml.GetData().c_str());
        xml.FindElem( "userId" );
        if (atoi(xml.GetData().c_str()) == loggedUserId) {
            xml.FindElem( "userId" );
            income.setUserId(atoi(xml.GetData().c_str()));
            xml.FindElem( "incomeId" );
            income.setIncomeId(currentIncomeId);
            xml.FindElem( "date" );
            date = dateManager.stringToIntDate(xml.GetData());
            income.setDate(date);
            xml.FindElem( "item" );
            income.setItem(xml.GetData());
            xml.FindElem( "amount" );
            amount = AuxiliaryMethods::conversionStringToFloat(xml.GetData());
            income.setAmount(amount);
            xml.OutOfElem();
            incomes.push_back(income);
        } else
            xml.OutOfElem();
    }
    lastIncomeId = currentIncomeId;

    return incomes;
}

int IncomesFile::getLastIncomeId() {
    return lastIncomeId;
}
