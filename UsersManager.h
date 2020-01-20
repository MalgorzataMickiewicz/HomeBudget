#ifndef USERSMANAGER_H
#define USERSMANAGER_H

#include "Users.h"

#include <iostream>
#include <vector>

using namespace std;

class UsersManager {

    vector <Users> users;

public:
    void registerUser();
};

#endif
