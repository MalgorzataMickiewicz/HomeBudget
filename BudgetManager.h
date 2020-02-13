#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>

#include "Incomes.h"
#include "Expenses.h"
#include "AuxiliaryMethods.h"
#include "IncomesFileManager.h"
#include "ExpensesFileManager.h"

using namespace std;

class BudgetManager {

    const int LOGGED_USER_ID;
    vector <Incomes> incomes;
    vector <Expenses> expenses;
    IncomesFileManager incomesFileManager;
    ExpensesFileManager expensesFileManager;
    float summValueOfIncomes;
    float summValueOfExpenses;
    int firstDateWithoutDashes;
    int secondDateWithoutDashes;

    Incomes getDateOfNewIncome();
    Expenses getDateOfNewExpense();

public:
    BudgetManager(string nameOfFile, string nameOfFile2, int loggedUserID)
        : incomesFileManager(nameOfFile), expensesFileManager(nameOfFile2), LOGGED_USER_ID(loggedUserID){
    incomes = incomesFileManager.loadIncomesFromFile(LOGGED_USER_ID),
    expenses = expensesFileManager.loadExpensesFromFile(LOGGED_USER_ID),
    summValueOfIncomes = 0,
    summValueOfExpenses = 0,
    firstDateWithoutDashes = 0,
    secondDateWithoutDashes= 0;
    };

    void addIncome();
    void addExpense();
    void showCurrentMonth();
    void showPreviousMonth();
    void showSelectedPeriod();
    void printAllIncomes(int date);
    void printAllExpenses(int date);
    void summOfIncomes(int date);
    void summOfExpenses(int date);
    void showBalance(int date);
    //bool sortByDate(Expenses &t1, Expenses &t2);
};

#endif
