#include "Users.h"

//Setter
void Users::setUserID(int newUserID) {
    userID=newUserID;
}
void Users::setUserName(string newUserName) {
    userName=newUserName;
}
void Users::setUserLastname(string newUserLastame) {
    userLastname=newUserLastame;
}
void Users::setUserLogin(string newUserLogin) {
    userLogin=newUserLogin;
}
void Users::setUserPassword(string newPassword) {
    userPassword=newPassword;
}


//Getter
int Users::getUserID() {
    return userID;
}
string Users::getUserName() {
    return userName;
}
string Users::getUserLastname() {
    return userLastname;
}
string Users::getUserLogin() {
    return userLogin;
}
string Users::getUserPassword() {
    return userPassword;
}

