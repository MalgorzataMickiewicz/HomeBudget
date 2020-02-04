#include "Markup.h"
#include "IncomesFileManager.h"

using namespace std;

void IncomesFileManager::addIncomeToFile(Incomes income){

    CMarkup xml;
    bool fileExists = xml.Load( "Incomes.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();//set on Incomes
    xml.IntoElem();//into Incomes
    xml.AddElem("Income");//add Income element
    xml.IntoElem();//into Income
    xml.AddElem("Date", income.getIncomeDate());//Add elemets lke Id, Login, Password, etc.
    xml.AddElem("Value", income.getIncomeValue());
    xml.AddElem("Name", income.getIncomeName());
    xml.Save("Incomes.xml");
}

vector <Incomes> IncomesFileManager::loadIncomesFromFile(){

    Incomes income;
    vector <Incomes> incomes;
    CMarkup xml;
    int dateInInt = 0;
    float valueInFloat = 0;

    bool fileExists = xml.Load( "Incomes.xml" );
    if (fileExists){
            MCD_STR Date;
            MCD_STR Value;
            MCD_STR Name;
            while (xml.FindChildElem("Income")){
            xml.FindElem();
            xml.IntoElem();
            xml.IntoElem();
            xml.FindElem("Date");
            Date = xml.GetData();
            xml.FindElem("Value");
            Value = xml.GetData();
            xml.FindElem("Name");
            Name = xml.GetData();
            xml.OutOfElem();
            xml.OutOfElem();
            dateInInt = AuxiliaryMethods::conversionStringToInt(Date);
            income.setIncomeDate(dateInInt);
            valueInFloat = AuxiliaryMethods::conversionStringToFloat(Value);
            income.setIncomeValue(valueInFloat);
            income.setIncomeName(Name);
            incomes.push_back(income);
            }
    }
  return incomes;
}

