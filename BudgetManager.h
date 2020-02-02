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

using namespace std;

class BudgetManager {

    vector <Incomes> incomes;
    vector <Expenses> expenses;
    Incomes getDateOfNewIncome();
    Expenses getDateOfNewExpense();

public:

    void addIncome();
    void printAllIncomes();
    void addExpense();
    void printAllExpenses();
<<<<<<< HEAD
    bool sortByDate(Expenses* t1, Expenses* t2);
=======
    bool sortByDate(Expenses& t1, Expenses& t2);
>>>>>>> Balance

};

#endif
