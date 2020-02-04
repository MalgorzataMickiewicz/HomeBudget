#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include <iostream>

#include "UsersManager.h"
#include "BudgetManager.h"

using namespace std;

class HomeBudget{

    UsersManager usersManager;
    BudgetManager budgetManager;

public:
     HomeBudget(string nameOfFileWithUsers, string nameOfFileWithIncomes)
        : usersManager(nameOfFileWithUsers), budgetManager(nameOfFileWithIncomes){};

    void registerUser();
    void printAllUsers();
    void loginUser();
    void changePassword();
    void addNewPasswordToVector();

    void addIncome();
    void printAllIncomes();
    void addExpense();
    void printAllExpenses();
};

#endif

