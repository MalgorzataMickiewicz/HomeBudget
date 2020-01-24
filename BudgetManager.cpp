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
    cout << "----------"<< "DODANIE PRZYCHODU" << "----------" << endl << "Podaj date przychodu w formacie: YYYY-MM-DD: ";
    cin >> dateOfIncomeInString;
    dateOfIncome = AuxiliaryMethods::conversionStringToInt(dateOfIncomeInString);
    income.setIncomeDate(dateOfIncome);

    float valueOfIncome = 0;
    cout << "Podaj wartosc przychodu: ";
    cin >> valueOfIncome;
    income.setIncomeValue(valueOfIncome);

    string nameOfIncome = "";
    cout << "Podaj nazawe przychodu: ";
    cin >> nameOfIncome;
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
