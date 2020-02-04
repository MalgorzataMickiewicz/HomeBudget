#ifndef INCOMESFILEMANAGER_H
#define INCOMESFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "XMLFile.h"
#include "Incomes.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomesFileManager: public XMLFile {

    int CurrentUserID;

public:
    IncomesFileManager(string nameOfFile)
        : XMLFile (nameOfFile) {};

    void addIncomeToFile(Incomes income);
    vector <Incomes> loadIncomesFromFile();
};

#endif
