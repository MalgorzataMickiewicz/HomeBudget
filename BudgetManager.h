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

    vector <Incomes> incomes;
    vector <Expenses> expenses;
    IncomesFileManager incomesFileManager;
    Incomes getDateOfNewIncome();
    Expenses getDateOfNewExpense();

public:

    void addIncome();
    void printAllIncomes();
    void addExpense();
    void printAllExpenses();
    //bool sortByDate(Expenses* t1, Expenses* t2);

};

#endif
