#ifndef USERS_H
#define USERS_H

#include <iostream>

using namespace std;

class Users {

    int userID;
    string userName;
    string userLastname;
    string userLogin;
    string userPassword;

public:
//Setters
    void setUserID(int newUserID);
    void setUserName(string newUserName);
    void setUserLastname(string newUserLastname);
    void setUserLogin(string newUserLogin);
    void setUserPassword(string newUserPassword);

//Getters
    int getUserID();
    string getUserName();
    string getUserLastname();
    string getUserLogin();
    string getUserPassword();

};

#endif
