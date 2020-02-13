#include "Markup.h"
#include "IncomesFileManager.h"

using namespace std;

void IncomesFileManager::addIncomeToFile(Incomes income) {

    CMarkup xml;
    bool fileExists = xml.Load( "incomes.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("income");
    xml.IntoElem();
    xml.AddElem("incomeId", AuxiliaryMethods::conversionIntToString(income.getIncomeID()));
    xml.AddElem("userId", AuxiliaryMethods::conversionIntToString(income.getUserID()));
    xml.AddElem("date", DateOperations::conversionIntToStringSeparatedDash(income.getIncomeDate()));
    xml.AddElem("value", AuxiliaryMethods::conversionFloatToString(income.getIncomeValue()));
    xml.AddElem("name", income.getIncomeName());
    xml.Save("incomes.xml");
    idLastIncome++;
}

vector <Incomes> IncomesFileManager::loadIncomesFromFile(int loggedUserID) {

    Incomes income;
    vector <Incomes> incomes;
    CMarkup xml;

    bool fileExists = xml.Load( "incomes.xml" );
    if (fileExists) {
        MCD_STR userId;
        MCD_STR incomeId;
        MCD_STR date;
        MCD_STR value;
        MCD_STR name;
        while (xml.FindChildElem("income")) {
            xml.FindElem();
            xml.IntoElem();
            xml.IntoElem();
            xml.FindElem("incomeId");
            incomeId = xml.GetData();
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
            income.setIncomeID(AuxiliaryMethods::conversionStringToInt(incomeId));
            income.setLoggedUserID(AuxiliaryMethods::conversionStringToInt(userId));
            income.setIncomeDate(DateOperations::conversionStringToIntDate(date));
            income.setIncomeValue(AuxiliaryMethods::conversionStringToFloat(value));
            income.setIncomeName(name);
            if(loggedUserID == AuxiliaryMethods::conversionStringToInt(userId)) {
                incomes.push_back(income);
            }
            idLastIncome = AuxiliaryMethods::conversionStringToInt(incomeId);
        }
    }
    return incomes;
}

int IncomesFileManager::getIdOfLastIncome() {
    return idLastIncome;
}
