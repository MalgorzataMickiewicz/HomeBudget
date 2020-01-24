#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>

#include "Incomes.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BudgetManager {

    vector <Incomes> incomes;
    Incomes getDateOfNewIncome();

public:

    void addIncome();
    void printAllIncome();

};

#endif
