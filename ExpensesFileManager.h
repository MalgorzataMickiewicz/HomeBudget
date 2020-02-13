#ifndef EXPENSESFILEMANAGER_H
#define EXPENSESFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "FilesManager.h"
#include "Expenses.h"
#include "AuxiliaryMethods.h"
#include "DateOperations.h"

using namespace std;

class ExpensesFileManager: public FileManager {

    int idLastExpense;

public:
    ExpensesFileManager(string nameOfFile)
        : FileManager (nameOfFile) {
        idLastExpense = 0;
        };

    void addExpenseToFile(Expenses expense);
    vector <Expenses> loadExpensesFromFile(int idLogedUser);
    int getIdOfLastExpense();
};

#endif
