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

    int loggedUserID;
    vector <Users> users;
    UsersFileManager usersFileManager;
    Users getDateOfNewUser();
    bool checkExistingOfLogin(string userLogin);
    string nameOfFileWithUsers;

public:
    UsersManager(string nameOfFileWithUsers) : usersFileManager(nameOfFileWithUsers) {
        loggedUserID = 0;
        users = usersFileManager.loadUsersFromFile();
    };

    void registerUser();
    int getIDNewUser();
    void printAllUsers();
    void loginUser();
    bool ifUserIsLogged();
    int giveIdLoggedUser();
    void changePassword();
    void addNewPasswordToVector(string userPassword);
};

#endif
