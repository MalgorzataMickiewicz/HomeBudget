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
    do {
        system("cls");
        cout << "----------"<< "DODANIE PRZYCHODU" << "----------" << endl;
        cout << "Czy przychod jest z dzisiaj?" << endl;
        cout << "1. TAK" << endl;
        cout << "2. NIE" << endl;
        cin >> choice;
        if (choice == 1) {
            dateOfIncome = AuxiliaryMethods::checkActualDate();
            income.setIncomeDate(dateOfIncome);
        } else if(choice == 2) {
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
        } else {
            cout << "Podaj cyfre 1 lub 2!" << endl;
            Sleep(2000);
            cin.clear();
            cin.sync();
            choice = 0;
        }
    } while(choice == 0);

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
        } else {
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

    do {
        system("cls");
        cout << "----------"<< "DODANIE WYDATKU" << "----------" << endl;
        cout << "Czy wydatek jest z dzisiaj?" << endl;
        cout << "1. TAK" << endl;
        cout << "2. NIE" << endl;
        cin >> choice;
        if (choice == 1) {
            dateOfExpense = AuxiliaryMethods::checkActualDate();
            expense.setExpenseDate(dateOfExpense);
        } else if(choice == 2) {
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
        } else {
            cout << "Podaj cyfre 1 lub 2!" << endl;
            Sleep(2000);
            cin.clear();
            cin.sync();
            choice = 0;
        }
    } while(choice == 0);

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
        } else {
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

void BudgetManager::showCurrentMonth() {
    int date = 1;
    printAllIncomes(date);
    summOfIncomes(date);
    printAllExpenses(date);
    summOfExpenses(date);
    showBalance(date);
}

void BudgetManager::showPreviousMonth() {
    int date = 2;
    printAllIncomes(date);
    summOfIncomes(date);
    printAllExpenses(date);
    summOfExpenses(date);
    showBalance(date);
}
void BudgetManager::showSelectedPeriod() {
    int date = 3;
    printAllIncomes(date);
    summOfIncomes(date);
    printAllExpenses(date);
    summOfExpenses(date);
    showBalance(date);
}


void BudgetManager::printAllIncomes(int date) {
    //string range = "";
    //if (date == 3){
    //cout << "Podaj zakres w formacie YYYY-MM-DD - YYYY-MM-DD" << endl;
    //cout << "Na przyklad: 2020-01-01 - 2020-02-01" << ": ";
    //getline(cin,range);
    //}

    system("cls");
    cout << "----------"<< "PRZYCHODY" << "----------" << endl;
    if(!incomes.empty()) {
        sort(incomes.begin(), incomes.end());
        if(date == 1) {
            for(int i = 0; i< incomes.size(); i++) {
                if(incomes[i].getIncomeDate() >= AuxiliaryMethods::checkCurrentMonth()) {
                    cout << "Income ID: " << incomes[i].getIncomeID() << endl;
                    cout << "User ID: " << incomes[i].getUserID() << endl;
                    cout << "Income Date: " << incomes[i].getIncomeDate() << endl;
                    cout << "Income Value: " << incomes[i].getIncomeValue() << " zl" << endl;
                    cout << "Income Name: " << incomes[i].getIncomeName() << endl;
                    cout << "----------------------------------------" << endl;
                }
            }
        } else if(date == 2) {
            for(int i = 0; i< incomes.size(); i++) {
                int previousMonthDate = AuxiliaryMethods::checkPreviousMonth();
                int previousMonthDateFirstDay = AuxiliaryMethods::getFirstDayOfPreviousMonth(previousMonthDate);
                if((incomes[i].getIncomeDate() >= previousMonthDateFirstDay) && (incomes[i].getIncomeDate() <= previousMonthDate)) {
                    cout << "Income ID: " << incomes[i].getIncomeID() << endl;
                    cout << "User ID: " << incomes[i].getUserID() << endl;
                    cout << "Income Date: " << incomes[i].getIncomeDate() << endl;
                    cout << "Income Value: " << incomes[i].getIncomeValue() << " zl" << endl;
                    cout << "Income Name: " << incomes[i].getIncomeName() << endl;
                    cout << "----------------------------------------" << endl;
                }
            }
        }
    } else {
        cout << "Nie masz jeszcze zadnych przychodow!" << endl;
        system("Pause");
    }
}

void BudgetManager::summOfIncomes(int date) {
    cout << "SUMA PRZYCHODOW: ";
    if(!incomes.empty()) {
        if(date == 1) {
            for(int i = 0; i< incomes.size(); i++) {
                if(incomes[i].getIncomeDate() >=  AuxiliaryMethods::checkCurrentMonth()) {
                    summValueOfIncomes += incomes[i].getIncomeValue();
                }
            }
        } else if(date == 2) {
            for(int i = 0; i< incomes.size(); i++) {
                int previousMonthDate = AuxiliaryMethods::checkPreviousMonth();
                int previousMonthDateFirstDay = AuxiliaryMethods::getFirstDayOfPreviousMonth(previousMonthDate);
                if((incomes[i].getIncomeDate() >= previousMonthDateFirstDay) && (incomes[i].getIncomeDate() <= previousMonthDate)) {
                    summValueOfIncomes += incomes[i].getIncomeValue();
                }
            }
        }
        cout << summValueOfIncomes << " zl" << endl;
        cout << endl;
    } else {
        cout << endl;
        cout << "Nie masz jeszcze zadnych przychodow!" << endl;
        system("Pause");
    }
}

void BudgetManager::printAllExpenses(int date) {
    cout << "----------"<< "WYDATKI" << "----------" << endl;
    if(!expenses.empty()) {
        sort(expenses.begin(), expenses.end());
        if(date == 1) {
            for(int i = 0; i< expenses.size(); i++) {
                if(expenses[i].getExpenseDate() >=  AuxiliaryMethods::checkCurrentMonth()) {
                    cout << "Expense ID: " << expenses[i].getExpenseID() << endl;
                    cout << "User ID: " << expenses[i].getUserID() << endl;
                    cout << "Expense Date: " << expenses[i].getExpenseDate() << endl;
                    cout << "Expense Value: " << expenses[i].getExpenseValue() << " zl" << endl;
                    cout << "Expense Name: " << expenses[i].getExpenseName() << endl;
                    cout << "----------------------------------------" << endl;
                }
            }
        } else if(date == 2) {
            for(int i = 0; i< expenses.size(); i++) {
                int previousMonthDate = AuxiliaryMethods::checkPreviousMonth();
                int previousMonthDateFirstDay = AuxiliaryMethods::getFirstDayOfPreviousMonth(previousMonthDate);
                if((expenses[i].getExpenseDate() >= previousMonthDateFirstDay) && (expenses[i].getExpenseDate() <= previousMonthDate)) {
                    cout << "Expense ID: " << expenses[i].getExpenseID() << endl;
                    cout << "User ID: " << expenses[i].getUserID() << endl;
                    cout << "Expense Date: " << expenses[i].getExpenseDate() << endl;
                    cout << "Expense Value: " << expenses[i].getExpenseValue() << " zl" << endl;
                    cout << "Expense Name: " << expenses[i].getExpenseName() << endl;
                    cout << "----------------------------------------" << endl;
                }
            }
        }
    } else {
        cout << "Nie masz jeszcze zadnych wydatkow!" << endl;
        system("Pause");
    }
}

void BudgetManager::summOfExpenses(int date) {
    cout << "SUMA WYDATKOW: ";
    if(!expenses.empty()) {
        if(date == 1) {
            summValueOfExpenses = 0;
            for(int i = 0; i< expenses.size(); i++) {
                if(expenses[i].getExpenseDate() >=  AuxiliaryMethods::checkCurrentMonth()) {
                    summValueOfExpenses += expenses[i].getExpenseValue();
                }
            }
        } else if(date == 2) {
            for(int i = 0; i< expenses.size(); i++) {
                int previousMonthDate = AuxiliaryMethods::checkPreviousMonth();
                int previousMonthDateFirstDay = AuxiliaryMethods::getFirstDayOfPreviousMonth(previousMonthDate);
                if((expenses[i].getExpenseDate() >= previousMonthDateFirstDay) && (expenses[i].getExpenseDate() <= previousMonthDate)) {
                    summValueOfExpenses += expenses[i].getExpenseValue();
                }
            }
        }
        cout << summValueOfExpenses << " zl" <<  endl;
        cout << endl;
    } else {
        cout << "Nie masz jeszcze zadnych wydatkow!" << endl;
        system("Pause");
    }
}

void BudgetManager::showBalance(int date) {
    float summ = summValueOfIncomes - summValueOfExpenses;
    cout << "----------"<< "BILANS" << "----------" << endl;
    if((summValueOfIncomes - summValueOfExpenses) < 0) {
        cout <<  "Przekroczyles swoj budzet! Wydales za duzo o: " << abs(summ) << " zl" << endl;
        system("Pause");
    } else {
        cout <<  "Mozesz jeszcze wydac w tym miesiacu: " << abs(summ) << " zl" << endl;
        system("Pause");
    }
}

