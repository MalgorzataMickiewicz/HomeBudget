#ifndef USERSMANAGER_H
#define USERSMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>

#include "Users.h"
#include "UsersFileManager.h"

using namespace std;

class UsersManager {

    int logedUserID;
    vector <Users> users;
    UsersFileManager usersFileManager;
    Users getDateOfNewUser();
    bool checkExistingOfLogin(string userLogin);
    string nameOfFileWithUsers;

public:
    UsersManager(string nameOfFileWithUsers) : usersFileManager(nameOfFileWithUsers) {
        logedUserID = 0;
        users = usersFileManager.loadUsersFromFile();
    };

    void registerUser();
    int getIDNewUser();
    void printAllUsers();
    void loginUser();
    void changePassword();
    void addNewPasswordToVector(string userPassword);
};

#endif
