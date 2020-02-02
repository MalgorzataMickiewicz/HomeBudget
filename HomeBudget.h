#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include <iostream>

#include "UsersManager.h"
#include "BudgetManager.h"

using namespace std;

class HomeBudget{

    UsersManager usersManager;
    BudgetManager incomesManager;
    BudgetManager expensesManager;

public:
     HomeBudget(string nameOfFileWithUsers)
        : usersManager(nameOfFileWithUsers){};

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

