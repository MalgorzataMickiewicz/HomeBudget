#ifndef INCOMESFILEMANAGER_H
#define INCOMESFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "FilesManager.h"
#include "Incomes.h"
#include "AuxiliaryMethods.h"
#include "DateOperations.h"
using namespace std;

class IncomesFileManager: public FileManager {

    int idLastIncome;

public:
    IncomesFileManager(string nameOfFile)
        : FileManager (nameOfFile) {
        idLastIncome = 0;
        };

    void addIncomeToFile(Incomes income);
    vector <Incomes> loadIncomesFromFile(int idLogedUser);
    int getIdOfLastIncome();
};

#endif
