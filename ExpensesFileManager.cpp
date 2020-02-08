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
    xml.AddElem("value", AuxiliaryMethods::conversionFloatToString(expense.getExpenseValue()));
    xml.AddElem("name", expense.getExpenseName());
    xml.Save("expenses.xml");
    idLastExpense++;
}

vector <Expenses> ExpensesFileManager::loadExpensesFromFile(int loggedUserID) {

    Expenses expense;
    vector <Expenses> expenses;
    CMarkup xml;

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
            expense.setExpenseID(AuxiliaryMethods::conversionStringToInt(expenseId));
            expense.setLoggedUserID(AuxiliaryMethods::conversionStringToInt(userId));
            expense.setExpenseDate(AuxiliaryMethods::conversionStringToIntDate(date));
            expense.setExpenseValue(AuxiliaryMethods::conversionStringToFloat(value));
            expense.setExpenseName(name);
            if(loggedUserID == AuxiliaryMethods::conversionStringToInt(userId)) {
                expenses.push_back(expense);
            }
            idLastExpense = AuxiliaryMethods::conversionStringToInt(expenseId);
        }
    }
    return expenses;
}

int ExpensesFileManager::getIdOfLastExpense() {
    return idLastExpense;
}
