#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include <iostream>

#include "UsersManager.h"
#include "BudgetManager.h"

using namespace std;

class HomeBudget{

    UsersManager usersManager;
    BudgetManager incomesManager;

public:
    void registerUser();
    void printAllUsers();
    void loginUser();
    void changePassword();
    void addNewPasswordToVector();

    void addIncome();
    void printAllIncome();
};

#endif

