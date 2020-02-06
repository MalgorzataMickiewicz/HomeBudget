#include "Markup.h"
#include "ExpensesFileManager.h"

using namespace std;

void ExpensesFileManager::addExpenseToFile(Expenses expense) {

    CMarkup xml;
    bool fileExists = xml.Load( "expenses.xml" );
    string dateSeparatedDash;

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("expense");
    xml.IntoElem();
    dateSeparatedDash = AuxiliaryMethods::conversionIntToStringSeparatedDash(expense.getExpenseDate());
    xml.AddElem("expenseId", AuxiliaryMethods::conversionIntToString(expense.getExpenseID()));
    xml.AddElem("userId", AuxiliaryMethods::conversionIntToString(expense.getUserID()));
    xml.AddElem("date", dateSeparatedDash);
    xml.AddElem("value", expense.getExpenseValue());
    xml.AddElem("name", expense.getExpenseName());
    xml.Save("expenses.xml");
}

vector <Expenses> ExpensesFileManager::loadExpensesFromFile(int loggedUserID) {

    Expenses expense;
    vector <Expenses> expenses;
    CMarkup xml;
    int dateInInt = 0;
    float valueInFloat = 0;
    int userIdInInt = 0;
    int expenseIdInInt = 0;

    bool fileExists = xml.Load( "expenses.xml" );
    if (fileExists) {
        MCD_STR userId;
        MCD_STR expenseId;
        MCD_STR date;
        MCD_STR value;
        MCD_STR name;
        while (xml.FindChildElem("expense")) {
            xml.FindElem();
            xml.IntoElem();
            xml.IntoElem();
            xml.FindElem("expenseId");
            expenseId = xml.GetData();
            xml.FindElem("userId");
            userId = xml.GetData();
            xml.FindElem("date");
            date = xml.GetData();
            xml.FindElem("value");
            value = xml.GetData();
            xml.FindElem("name");
            name = xml.GetData();
            xml.OutOfElem();
            xml.OutOfElem();
            expenseIdInInt = AuxiliaryMethods::conversionStringToInt(expenseId);
            expense.setExpenseID(expenseIdInInt);
            userIdInInt = AuxiliaryMethods::conversionStringToInt(userId);
            expense.setLoggedUserID(userIdInInt);
            dateInInt = AuxiliaryMethods::conversionStringToIntDate(date);
            expense.setExpenseDate(dateInInt);
            valueInFloat = AuxiliaryMethods::conversionStringToFloat(value);
            expense.setExpenseValue(valueInFloat);
            expense.setExpenseName(name);
            if(loggedUserID == userIdInInt) {
                expenses.push_back(expense);
            }
            idLastExpense = expenseIdInInt;
        }
    }
    return expenses;
}

int ExpensesFileManager::getIdOfLastExpense() {
    return idLastExpense;
}
