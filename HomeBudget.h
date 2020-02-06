#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include <iostream>

#include "UsersManager.h"
#include "BudgetManager.h"

using namespace std;

class HomeBudget{

    UsersManager usersManager;
    BudgetManager *budgetManager;

    const string NAME_OF_FILE_WITH_INCOMES;

public:
     HomeBudget(string nameOfFileWithUsers, string nameOfFileWithIncomes)
        : usersManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes)
        {budgetManager = NULL;
        };
        ~HomeBudget(){
    delete budgetManager;
    budgetManager = NULL;
    }

    void registerUser();
    void printAllUsers();
    void loginUser();
    bool ifUserIsLogged();
    void logoutUser();
    void changePassword();
    void addNewPasswordToVector();
    void addIncome();
    void printAllIncomes();
    void addExpense();
    void printAllExpenses();
};

#endif

