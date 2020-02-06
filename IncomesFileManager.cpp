#include "Markup.h"
#include "IncomesFileManager.h"

using namespace std;

void IncomesFileManager::addIncomeToFile(Incomes income){

    CMarkup xml;
    bool fileExists = xml.Load( "incomes.xml" );
    string dateSeparatedDash;

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("income");
    xml.IntoElem();
    dateSeparatedDash = AuxiliaryMethods::conversionIntToStringSeparatedDash(income.getIncomeDate());
    xml.AddElem("userId", AuxiliaryMethods::conversionIntToString(income.getUserID()));
    xml.AddElem("date", dateSeparatedDash);
    xml.AddElem("value", income.getIncomeValue());
    xml.AddElem("name", income.getIncomeName());
    xml.Save("incomes.xml");
}

vector <Incomes> IncomesFileManager::loadIncomesFromFile(int loggedUserID){

    Incomes income;
    vector <Incomes> incomes;
    CMarkup xml;
    int dateInInt = 0;
    float valueInFloat = 0;
    int userIdInInt = 0;

    bool fileExists = xml.Load( "incomes.xml" );
    if (fileExists){
            MCD_STR userId;
            MCD_STR incomeId;
            MCD_STR date;
            MCD_STR value;
            MCD_STR name;
            while (xml.FindChildElem("income")){
            xml.FindElem();
            xml.IntoElem();
            xml.IntoElem();
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
            userIdInInt = AuxiliaryMethods::conversionStringToInt(userId);
            income.setLoggedUserID(userIdInInt);
            dateInInt = AuxiliaryMethods::conversionStringToIntDate(date);
            income.setIncomeDate(dateInInt);
            valueInFloat = AuxiliaryMethods::conversionStringToFloat(value);
            income.setIncomeValue(valueInFloat);
            income.setIncomeName(name);
            if(loggedUserID == userIdInInt) {
                incomes.push_back(income);
            }
            }
    }
  return incomes;
}

