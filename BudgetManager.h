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

    vector <Incomes> incomes;
    vector <Expenses> expenses;
    string nameOfFileWithIncomes;
    IncomesFileManager incomesFileManager;

    Incomes getDateOfNewIncome();
    Expenses getDateOfNewExpense();

public:
    BudgetManager(string nameOfFileWithIncomes) : incomesFileManager(nameOfFileWithIncomes)
    {incomes = incomesFileManager.loadIncomesFromFile();
    };

    void addIncome();
    void printAllIncomes();
    void addExpense();
    void printAllExpenses();
    //bool sortByDate(Expenses* t1, Expenses* t2);

};

#endif
