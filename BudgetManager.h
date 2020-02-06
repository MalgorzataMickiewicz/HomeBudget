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

    Incomes getDateOfNewIncome();
    Expenses getDateOfNewExpense();

public:
    BudgetManager(string nameOfFile, string nameOfFile2, int loggedUserID)
        : incomesFileManager(nameOfFile), expensesFileManager(nameOfFile2), LOGGED_USER_ID(loggedUserID){
    incomes = incomesFileManager.loadIncomesFromFile(LOGGED_USER_ID),
    expenses = expensesFileManager.loadExpensesFromFile(LOGGED_USER_ID);
    };

    void addIncome();
    void printAllIncomes();
    void addExpense();
    void printAllExpenses();
    //bool sortByDate(Expenses* t1, Expenses* t2);

};

#endif
