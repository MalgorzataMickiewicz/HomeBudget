#include <iomanip>

#include "BudgetManager.h"

using namespace std;

void BudgetManager::addIncome() {
    Incomes income = getDateOfNewIncome();
    incomes.push_back(income);
    //incomesFileManager.addIncomesrToFile(income);
    cout << "Przychod dodany" << endl;
    Sleep(1000);
}

Incomes BudgetManager::getDateOfNewIncome() {
    Incomes income;

    string dateOfIncomeInString = "";
    int dateOfIncome = 0;
    int choice = 0;

    cout << "----------"<< "DODANIE PRZYCHODU" << "----------" << endl;
    cout << "Czy przychod jest z dzisiaj?" << endl;
    cout << "1. TAK" << endl;
    cout << "2. NIE" << endl;
    cin >> choice;
    if (choice == 1){
        dateOfIncome = AuxiliaryMethods::checkActualDate();
        income.setIncomeDate(dateOfIncome);
    }
    else{
        cout << "Podaj date przychodu w formacie: YYYY-MM-DD: ";
        cin >> dateOfIncomeInString;
        dateOfIncome = AuxiliaryMethods::conversionStringToInt(dateOfIncomeInString);
        income.setIncomeDate(dateOfIncome);
    }

    float valueOfIncome = 0;
    int goodValue = 1;

     do{
        goodValue = 1;
        cout << "Podaj wartosc przychodu, np. 100.22: ";
        cin >> valueOfIncome;
         if( !cin ){
                cout << "Wprowadzona wartosc nie jest liczba!" << endl;
                cin.clear();
                cin.sync();
                system("Pause");
                system("cls");
                goodValue = 0;
                }
     }while(goodValue == 0);

    income.setIncomeValue(valueOfIncome);

    string nameOfIncome = "";
    cout << "Podaj nazwe przychodu: ";
    cin.sync();
    getline(cin,nameOfIncome);
    income.setIncomeName(nameOfIncome);

    return income;
}

void BudgetManager::printAllIncome(){
    system("cls");
    cout << "Zapisane przychody:" << endl;
    for(int i = 0; i< incomes.size(); i++) {
        cout << incomes[i].getIncomeDate() << endl;
        cout << incomes[i].getIncomeValue() << endl;
        cout << incomes[i].getIncomeName() << endl;

        system("Pause");
    }
}
