#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>

#include "BudgetManager.h"

using namespace std;

void BudgetManager::addIncome() {
    Incomes income = getDateOfNewIncome();
    incomes.push_back(income);
    incomesFileManager.addIncomeToFile(income);
    cout << "Przychod dodany" << endl;
    system("Pause");
}

Incomes BudgetManager::getDateOfNewIncome() {
    Incomes income;

    string dateOfIncomeInString = "";
    int dateOfIncome = 0;
    int choice = 0;

    income.setLoggedUserID(LOGGED_USER_ID);
    income.setIncomeID((incomesFileManager.getIdOfLastIncome()) + 1);
    do{
    system("cls");
    cout << "----------"<< "DODANIE PRZYCHODU" << "----------" << endl;
    cout << "Czy przychod jest z dzisiaj?" << endl;
    cout << "1. TAK" << endl;
    cout << "2. NIE" << endl;
    cin >> choice;
    if (choice == 1) {
        dateOfIncome = AuxiliaryMethods::checkActualDate();
        income.setIncomeDate(dateOfIncome);
    } else if(choice == 2){
        do {
            cout << "-------------------------------------------" << endl;
            cout << "Podaj date przychodu w formacie: YYYY-MM-DD: ";
            cin >> dateOfIncomeInString;
            dateOfIncome = AuxiliaryMethods::conversionStringToIntDate(dateOfIncomeInString);
            if(dateOfIncome == 0) {
                cin.clear();
            }
        } while(dateOfIncome == 0);
        income.setIncomeDate(dateOfIncome);
    }
    else{
        cout << "Podaj cyfre 1 lub 2!" << endl;
        Sleep(2000);
        cin.clear();
        cin.sync();
        choice = 0;
    }
    }while(choice == 0);

    string valueOfIncomeInString = "";
    float valueOfIncomeInFloat = 0;
    int goodValue = 0;

    do {
        cout << "----------------------------------------" << endl;
        cout << "Podaj wartosc przychodu, np. 100.22: ";
        cin >> valueOfIncomeInString;
        if( !cin ) {
            cout << "Wprowadzona wartosc nie jest liczba!" << endl;
            Sleep(3000);
            cin.clear();
            cin.sync();
            goodValue = 0;
        }
        else{
            valueOfIncomeInFloat = AuxiliaryMethods::conversionStringToFloat(valueOfIncomeInString);
            goodValue = 1;
        }
    } while(goodValue == 0);
    income.setIncomeValue(valueOfIncomeInFloat);

    string nameOfIncome = "";
    cout << "----------------------------------------" << endl;
    cout << "Podaj nazwe przychodu: ";
    cin.sync();
    getline(cin,nameOfIncome);
    income.setIncomeName(nameOfIncome);
    return income;
}

void BudgetManager::printAllIncomes() {
    system("cls");
    cout << "----------"<< "PRZYCHODY" << "----------" << endl;
    //DODAC SORTOWANIE
    if(!incomes.empty()){
    for(int i = 0; i< incomes.size(); i++) {
        cout << "Income ID: " << incomes[i].getIncomeID() << endl;
        cout << "User ID: " << incomes[i].getUserID() << endl;
        cout << "Income Date: " << incomes[i].getIncomeDate() << endl;
        cout << "Income Value: " << incomes[i].getIncomeValue() << " zl" << endl;
        cout << "Income Name: " << incomes[i].getIncomeName() << endl;
        cout << "----------------------------------------" << endl;
        system("Pause");
    }
    }
    else{
        cout << "Nie masz jeszcze zadnych przychodow!" << endl;
        system("Pause");
    }
}


void BudgetManager::summOfIncomes(){
    system("cls");
    cout << "----------"<< "SUMA PRZYCHODOW" << "----------" << endl;
    if(!incomes.empty()){
    for(int i = 0; i< incomes.size(); i++) {
    summValueOfIncomes += incomes[i].getIncomeValue();
    }
    cout << "Suma przychodow: " << summValueOfIncomes << " zl" << endl;
    system("Pause");
    }
    else{
        cout << "Nie masz jeszcze zadnych przychodow!" << endl;
        system("Pause");
    }
}


void BudgetManager::addExpense() {
    Expenses expense = getDateOfNewExpense();
    expenses.push_back(expense);
    expensesFileManager.addExpenseToFile(expense);
    cout << "Wydatek dodany" << endl;
    system("Pause");
}

Expenses BudgetManager::getDateOfNewExpense() {
    Expenses expense;

    string dateOfExpenseInString = "";
    int dateOfExpense = 0;
    int choice = 0;

    expense.setLoggedUserID(LOGGED_USER_ID);
    expense.setExpenseID(expensesFileManager.getIdOfLastExpense() + 1);

    do{
    system("cls");
    cout << "----------"<< "DODANIE WYDATKU" << "----------" << endl;
    cout << "Czy wydatek jest z dzisiaj?" << endl;
    cout << "1. TAK" << endl;
    cout << "2. NIE" << endl;
    cin >> choice;
    if (choice == 1) {
        dateOfExpense = AuxiliaryMethods::checkActualDate();
        expense.setExpenseDate(dateOfExpense);
    } else if(choice == 2){
        do {
            cout << "----------------------------------------" << endl;
            cout << "Podaj date wydatku w formacie: YYYY-MM-DD: ";
            cin >> dateOfExpenseInString;
            dateOfExpense = AuxiliaryMethods::conversionStringToIntDate(dateOfExpenseInString);
            if(dateOfExpense == 0) {
                cin.clear();
            }
        } while(dateOfExpense == 0);
        expense.setExpenseDate(dateOfExpense);
    }
    else{
        cout << "Podaj cyfre 1 lub 2!" << endl;
        Sleep(2000);
        cin.clear();
        cin.sync();
        choice = 0;
    }
    }while(choice == 0);

    string valueOfExpenseInString = "";
    float valueOfExpenseInFloat = 0;
    int goodValue = 0;

    do {
        cout << "----------------------------------------" << endl;
        cout << "Podaj wartosc wydatku, np. 100.22: ";
        cin >> valueOfExpenseInString;
        if( !cin ) {
            cout << "Wprowadzona wartosc nie jest liczba!" << endl;
            Sleep(3000);
            cin.clear();
            cin.sync();
            goodValue = 0;
        }
        else{
            valueOfExpenseInFloat = AuxiliaryMethods::conversionStringToFloat(valueOfExpenseInString);
            goodValue = 1;
        }
    } while(goodValue == 0);
    expense.setExpenseValue(valueOfExpenseInFloat);

    string nameOfExpense = "";
    cout << "----------------------------------------" << endl;
    cout << "Podaj nazwe wydatku: ";
    cin.sync();
    getline(cin,nameOfExpense);
    expense.setExpenseName(nameOfExpense);

    return expense;
}

void BudgetManager::printAllExpenses() {
    system("cls");
    //DODAC SORTOWANIE
    //sort (expenses.begin(), expenses.end(), sortByDate);
    cout << "----------"<< "WYDATKI" << "----------" << endl;
    if(!expenses.empty()){
    for(int i = 0; i< expenses.size(); i++) {
        cout << "Expense ID: " << expenses[i].getExpenseID() << endl;
        cout << "User ID: " << expenses[i].getUserID() << endl;
        cout << "Expense Date: " << expenses[i].getExpenseDate() << endl;
        cout << "Expense Value: " << expenses[i].getExpenseValue() << " zl" << endl;
        cout << "Expense Name: " << expenses[i].getExpenseName() << endl;
        cout << "----------------------------------------" << endl;
        system("Pause");
    }
    }
    else{
        cout << "Nie masz jeszcze zadnych wydatkow!" << endl;
        system("Pause");
    }
}

void BudgetManager::summOfExpenses(){
    system("cls");
    cout << "----------"<< "SUMA WYDATKOW" << "----------" << endl;
    if(!expenses.empty()){
    for(int i = 0; i< incomes.size(); i++) {
    summValueOfExpenses += expenses[i].getExpenseValue();
    }
    cout << "Suma wydatkow: " << summValueOfExpenses << " zl" <<  endl;
    system("Pause");
}
else{
    cout << "Nie masz jeszcze zadnych wydatkow!" << endl;
    system("Pause");
}
}

void BudgetManager::showBalance(){
    float summ = summValueOfIncomes - summValueOfExpenses;
    system("cls");
    cout << "----------"<< "BILANS" << "----------" << endl;
    if((summValueOfIncomes - summValueOfExpenses) < 0){
    cout <<  "Przekroczyles swoj budzet! Wydales za duzo o: " << abs(summ) << " zl" << endl;
    system("Pause");
    }
    else{
        cout <<  "Mozesz jeszcze wydac w tym miesiacu: " << abs(summ) << " zl" << endl;
        system("Pause");
    }


}

/*
bool BudgetManager::sortByDate(Expenses* t1, Expenses* t2){
    return t1.*getExpenseDate() < t2.*getExpenseDate();
}
*/
