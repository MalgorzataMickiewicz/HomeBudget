#include <iomanip>

#include "BudgetManager.h"

using namespace std;

void BudgetManager::addIncome() {
    Incomes income = getDateOfNewIncome();
    incomes.push_back(income);
    //incomesFileManager.addIncomesToFile(income);
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
        do{
        cout << "Podaj date przychodu w formacie: YYYY-MM-DD: ";
        cin >> dateOfIncomeInString;
        dateOfIncome = AuxiliaryMethods::conversionStringToInt(dateOfIncomeInString);
        if(dateOfIncome == 0){
                system("Pause");
                system("cls");
                cin.clear();
                }
     }while(dateOfIncome == 0);
     income.setIncomeDate(dateOfIncome);
    }

    float valueOfIncome = 0;
    int goodValue = 1;

     do{
        goodValue = 1;
        cout << "Podaj wartosc przychodu, np. 100.22: ";
        //JAK SIE WPROWADZI NP. 200.c to przechodzi!
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

void BudgetManager::printAllIncomes(){
    system("cls");
    cout << "Zapisane przychody:" << endl;
    for(int i = 0; i< incomes.size(); i++) {
        cout << incomes[i].getIncomeDate() << endl;
        cout << incomes[i].getIncomeValue() << endl;
        cout << incomes[i].getIncomeName() << endl;

        system("Pause");
    }
}

void BudgetManager::addExpense() {
    Expenses expense = getDateOfNewExpense();
    expenses.push_back(expense);
    //expnesesFileManager.addExpenseToFile(expense);
    cout << "Wydatek dodany" << endl;
    Sleep(1000);
}

Expenses BudgetManager::getDateOfNewExpense() {
    Expenses expense;

    string dateOfExpenseInString = "";
    int dateOfExpense = 0;
    int choice = 0;

    cout << "----------"<< "DODANIE WYDATKU" << "----------" << endl;
    cout << "Czy wydatek jest z dzisiaj?" << endl;
    cout << "1. TAK" << endl;
    cout << "2. NIE" << endl;
    cin >> choice;
    if (choice == 1){
        dateOfExpense = AuxiliaryMethods::checkActualDate();
        expense.setExpenseDate(dateOfExpense);
    }
    else{
        do{
        cout << "Podaj date wydatku w formacie: YYYY-MM-DD: ";
        cin >> dateOfExpenseInString;
        dateOfExpense = AuxiliaryMethods::conversionStringToInt(dateOfExpenseInString);
        if(dateOfExpense == 0){
                system("Pause");
                system("cls");
                cin.clear();
                }
     }while(dateOfExpense == 0);
     expense.setExpenseDate(dateOfExpense);
    }

    float valueOfExpense = 0;
    int goodValue = 1;

     do{
        goodValue = 1;
        cout << "Podaj wartosc wydatku, np. 100.22: ";
        cin >> valueOfExpense;
        //JAK SIE WPROWADZI NP. 200.c to przechodzi!
         if( !cin ){
                cout << "Wprowadzona wartosc nie jest liczba!" << endl;
                cin.clear();
                cin.sync();
                system("Pause");
                system("cls");
                goodValue = 0;
                }
     }while(goodValue == 0);

    expense.setExpenseValue(valueOfExpense);

    string nameOfExpense = "";
    cout << "Podaj nazwe wydatku: ";
    cin.sync();
    getline(cin,nameOfExpense);
    expense.setExpenseName(nameOfExpense);

    return expense;
}

void BudgetManager::printAllExpenses(){
    system("cls");
    cout << "Zapisane wydatki:" << endl;
    for(int i = 0; i< expenses.size(); i++) {
        cout << expenses[i].getExpenseDate() << endl;
        cout << expenses[i].getExpenseValue() << endl;
        cout << expenses[i].getExpenseName() << endl;

        system("Pause");
    }
}
