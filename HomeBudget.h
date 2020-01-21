#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include "UsersManager.h"

#include <iostream>

using namespace std;

class HomeBudget{

    UsersManager usersManager;

public:
    void registerUser();
    void printAllUsers();
    void loginUser();
};

#endif

