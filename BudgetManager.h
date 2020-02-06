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

using namespace std;

class BudgetManager {

    const int LOGGED_USER_ID;
    vector <Incomes> incomes;
    vector <Expenses> expenses;
    IncomesFileManager incomesFileManager;

    Incomes getDateOfNewIncome();
    Expenses getDateOfNewExpense();

public:
    BudgetManager(string nameOfFile, int loggedUserID)
        : incomesFileManager(nameOfFile), LOGGED_USER_ID(loggedUserID){
    incomes = incomesFileManager.loadIncomesFromFile(LOGGED_USER_ID);
    };

    void addIncome();
    void printAllIncomes();
    void addExpense();
    void printAllExpenses();
    //bool sortByDate(Expenses* t1, Expenses* t2);

};

#endif
