#ifndef USERSMANAGER_H
#define USERSMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>

#include "Users.h"

using namespace std;

class UsersManager {

    int logedUserID;
    vector <Users> users;
    Users getDateOfNewUser();
    bool checkExistingOfLogin(string userLogin);

public:
    UsersManager() {
        logedUserID = 0;
    };
    void registerUser();
    int getIDNewUser();
    void printAllUsers();
    void loginUser();

};

#endif
