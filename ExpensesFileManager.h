#ifndef EXPENSESFILEMANAGER_H
#define EXPENSESFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "XMLFile.h"
#include "Expenses.h"
#include "AuxiliaryMethods.h"

using namespace std;

class ExpensesFileManager: public XMLFile {

    int idLastExpense;

public:
    ExpensesFileManager(string nameOfFile)
        : XMLFile (nameOfFile) {
        idLastExpense = 0;
        };

    void addExpenseToFile(Expenses expense);
    vector <Expenses> loadExpensesFromFile(int idLogedUser);
    int getIdOfLastExpense();
};

#endif
