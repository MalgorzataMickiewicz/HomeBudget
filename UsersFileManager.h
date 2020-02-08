#ifndef USERSFILEMANAGER_H
#define USERSFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "FilesManager.h"
#include "Users.h"

using namespace std;

class UsersFileManager: public FileManager {

public:
    UsersFileManager(string nameOfFile)
        : FileManager (nameOfFile) {};

    void addUserToFile(Users user);
    vector <Users> loadUsersFromFile();
    void addUserWithNewPasswordToFile(Users user, int idCurrentUser);
};

#endif
