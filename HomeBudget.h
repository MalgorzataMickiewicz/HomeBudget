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
    const string NAME_OF_FILE_WITH_EXPENSES;

public:
     HomeBudget(string nameOfFileWithUsers, string nameOfFileWithIncomes, string nameOfFileWithExpenses)
        : usersManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes), NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses)
        {budgetManager = NULL;
        };
        ~HomeBudget(){
    delete budgetManager;
    budgetManager = NULL;
    }
    int showMenu(int choice);
    int showSecondMenu(int choice);
    void registerUser();
    void loginUser();
    bool ifUserIsLogged();
    void logoutUser();
    void changePassword();
    void addNewPasswordToVector();
    void addIncome();
    void addExpense();
    void showCurrentMonth();
    void showPreviousMonth();
    void showSelectedPeriod();
};

#endif

