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
                cin.sync();
                getline(cin,dateOfIncomeInString);
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
                cin.sync();
                getline(cin,dateOfExpenseInString);
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
}

void BudgetManager::showPreviousMonth() {
    int date = 2;
    printAllIncomes(date);
}
void BudgetManager::showSelectedPeriod() {
    int date = 3;
    printAllIncomes(date);
}


void BudgetManager::printAllIncomes(int date) {
    int counter = 0;
    system("cls");
    cout << "----------"<< "PRZYCHODY" << "----------" << endl;
    if(!incomes.empty()) {
        sort(incomes.begin(), incomes.end());
        if(date == 1) {
            for(int i = 0; i< incomes.size(); i++) {
                if(incomes[i].getIncomeDate() >= AuxiliaryMethods::checkCurrentMonth()) {
                    cout << "----------------------------------------" << endl;
                    cout << "Income ID: " << incomes[i].getIncomeID() << endl;
                    cout << "User ID: " << incomes[i].getUserID() << endl;
                    cout << "Income Date: " << incomes[i].getIncomeDate() << endl;
                    cout << "Income Value: " << incomes[i].getIncomeValue() << " zl" << endl;
                    cout << "Income Name: " << incomes[i].getIncomeName() << endl;
                    counter++;
                }
            }
        } else if(date == 2) {
            for(int i = 0; i< incomes.size(); i++) {
                int previousMonthDate = AuxiliaryMethods::checkPreviousMonth();
                int previousMonthDateFirstDay = AuxiliaryMethods::getFirstDayOfPreviousMonth(previousMonthDate);
                if((incomes[i].getIncomeDate() >= previousMonthDateFirstDay) && (incomes[i].getIncomeDate() <= previousMonthDate)) {
                    cout << "----------------------------------------" << endl;
                    cout << "Income ID: " << incomes[i].getIncomeID() << endl;
                    cout << "User ID: " << incomes[i].getUserID() << endl;
                    cout << "Income Date: " << incomes[i].getIncomeDate() << endl;
                    cout << "Income Value: " << incomes[i].getIncomeValue() << " zl" << endl;
                    cout << "Income Name: " << incomes[i].getIncomeName() << endl;
                    counter++;
                }
            }
        } else if (date == 3) {
            string firstDateInString = "";
            string secondDateInString = "";
            do {
                cout << "Podaj zakres w formacie YYYY-MM-DD w zakresie od - do" << endl;
                cout << "Na przyklad: 2020-01-01" << endl;
                cout << "Wprowadz 1 date: ";
                cin.sync();
                getline(cin,firstDateInString);
                firstDateWithoutDashes = AuxiliaryMethods::conversionStringToIntDate(firstDateInString);
                if(firstDateWithoutDashes == 0) {
                    cin.clear();
                }
            } while(firstDateWithoutDashes == 0);

            do {
                cout << "Wprowadz 2 date: ";
                cin.sync();
                getline(cin,secondDateInString);
                secondDateWithoutDashes = AuxiliaryMethods::conversionStringToIntDate(secondDateInString);
                if(secondDateWithoutDashes == 0) {
                    cin.clear();
                }
            } while(secondDateWithoutDashes == 0);

            for(int i = 0; i< incomes.size(); i++) {
                if((incomes[i].getIncomeDate() >= firstDateWithoutDashes) && (incomes[i].getIncomeDate() <= secondDateWithoutDashes)) {
                    cout << "----------------------------------------" << endl;
                    cout << "Income ID: " << incomes[i].getIncomeID() << endl;
                    cout << "User ID: " << incomes[i].getUserID() << endl;
                    cout << "Income Date: " << incomes[i].getIncomeDate() << endl;
                    cout << "Income Value: " << incomes[i].getIncomeValue() << " zl" << endl;
                    cout << "Income Name: " << incomes[i].getIncomeName() << endl;
                    counter++;
                }
            }
        } else {
            cout << "Nie masz jeszcze zadnych przychodow!" << endl;
            system("Pause");
        }
    }
    if(counter != 0){
        summOfIncomes(date);
    }
    else{
        cout << "Nie masz przychodow w wybranym zakresie" << endl;
        system("Pause");
        printAllExpenses(date);
    }
}

void BudgetManager::summOfIncomes(int date) {
    cout << endl;
    cout << "----------"<< "SUMA PRZYCHODOW" << "----------" << endl;
    cout << "----------------------------------------" << endl;
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
        } else if(date == 3) {
            for(int i = 0; i< incomes.size(); i++) {
                if((incomes[i].getIncomeDate() >= firstDateWithoutDashes) && (incomes[i].getIncomeDate() <= secondDateWithoutDashes)) {
                    summValueOfIncomes += incomes[i].getIncomeValue();
                }
            }
        }
        cout << "SUMA: " << summValueOfIncomes << " zl" << endl;
        cout << endl;
    } else {
        cout << endl;
        cout << "Nie masz jeszcze zadnych przychodow!" << endl;
        system("Pause");
    }
    printAllExpenses(date);
}

void BudgetManager::printAllExpenses(int date) {
    int counter = 0;
    cout << "----------"<< "WYDATKI" << "----------" << endl;
    if(!expenses.empty()) {
        sort(expenses.begin(), expenses.end());
        if(date == 1) {
            for(int i = 0; i< expenses.size(); i++) {
                if(expenses[i].getExpenseDate() >=  AuxiliaryMethods::checkCurrentMonth()) {
                    cout << "----------------------------------------" << endl;
                    cout << "Expense ID: " << expenses[i].getExpenseID() << endl;
                    cout << "User ID: " << expenses[i].getUserID() << endl;
                    cout << "Expense Date: " << expenses[i].getExpenseDate() << endl;
                    cout << "Expense Value: " << expenses[i].getExpenseValue() << " zl" << endl;
                    cout << "Expense Name: " << expenses[i].getExpenseName() << endl;
                    counter++;
                }
            }
        } else if(date == 2) {
            for(int i = 0; i< expenses.size(); i++) {
                int previousMonthDate = AuxiliaryMethods::checkPreviousMonth();
                int previousMonthDateFirstDay = AuxiliaryMethods::getFirstDayOfPreviousMonth(previousMonthDate);
                if((expenses[i].getExpenseDate() >= previousMonthDateFirstDay) && (expenses[i].getExpenseDate() <= previousMonthDate)) {
                    cout << "----------------------------------------" << endl;
                    cout << "Expense ID: " << expenses[i].getExpenseID() << endl;
                    cout << "User ID: " << expenses[i].getUserID() << endl;
                    cout << "Expense Date: " << expenses[i].getExpenseDate() << endl;
                    cout << "Expense Value: " << expenses[i].getExpenseValue() << " zl" << endl;
                    cout << "Expense Name: " << expenses[i].getExpenseName() << endl;
                    counter++;
                }
            }
        } else if (date == 3) {
            for(int i = 0; i < expenses.size(); i++) {
                if((expenses[i].getExpenseDate() >= firstDateWithoutDashes) && (expenses[i].getExpenseDate() <= secondDateWithoutDashes)) {
                    cout << "----------------------------------------" << endl;
                    cout << "Income ID: " << expenses[i].getExpenseID() << endl;
                    cout << "User ID: " << expenses[i].getUserID() << endl;
                    cout << "Income Date: " << expenses[i].getExpenseDate() << endl;
                    cout << "Income Value: " << expenses[i].getExpenseValue() << " zl" << endl;
                    cout << "Income Name: " << expenses[i].getExpenseName() << endl;
                    counter++;
                  }
            }
        } else {
            cout << "Nie masz jeszcze zadnych wydatkow!" << endl;
            system("Pause");
        }
    }
    if(counter != 0){
        summOfExpenses(date);
    }
    else{
        cout << "Nie masz wydatkow w wybranym zakresie" << endl;
        system("Pause");
        showBalance(date);
    }
}

void BudgetManager::summOfExpenses(int date) {
    cout << endl;
    cout << "----------"<< "SUMA WYDATKOW" << "----------" << endl;
    cout << "----------------------------------------" << endl;
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
        } else if(date == 3) {
            for(int i = 0; i< expenses.size(); i++) {
                if((expenses[i].getExpenseDate() >= firstDateWithoutDashes) && (expenses[i].getExpenseDate() <= secondDateWithoutDashes)) {
                    summValueOfExpenses += expenses[i].getExpenseValue();
                }
            }
        }
        cout << "SUMA: " << summValueOfExpenses << " zl" <<  endl;
        cout << endl;
    } else {
        cout << "Nie masz jeszcze zadnych wydatkow!" << endl;
        system("Pause");
    }
    showBalance(date);
}

void BudgetManager::showBalance(int date) {
    float summ = summValueOfIncomes - summValueOfExpenses;
    if((summValueOfIncomes == 0) && (summValueOfExpenses == 0)){}
    else{
    if((summValueOfIncomes - summValueOfExpenses) < 0) {
        cout << "----------"<< "BILANS" << "----------" << endl;
        cout << "----------------------------------------" << endl;
        cout <<  "Przekroczyles swoj budzet! Wydales za duzo o: " << abs(summ) << " zl" << endl;
        system("Pause");
    } else {
        cout <<  "Mozesz jeszcze wydac w tym miesiacu: " << abs(summ) << " zl" << endl;
        system("Pause");
    }
    }
    firstDateWithoutDashes = 0;
    secondDateWithoutDashes = 0;
    summValueOfIncomes = 0;
    summValueOfExpenses = 0;
    summ = 0;
}

