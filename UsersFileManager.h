#ifndef USERSFILEMANAGER_H
#define USERSFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "XMLFile.h"
#include "Users.h"

using namespace std;

class UsersFileManager: public XMLFile {

    int lastUserID;
    int CurrentUserID;

public:
    UsersFileManager(string nameOfFile)
        : XMLFile (nameOfFile) {};

    void addUserToFile(Users user);
    vector <Users> loadUsersFromFile();
    void addUserWithNewPasswordToFile(Users user, int idCurrentUser);
    //int getIdOfUser();
};

#endif
