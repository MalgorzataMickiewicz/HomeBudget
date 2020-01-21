#include "HomeBudget.h"
#include "UsersManager.h"

void HomeBudget::registerUser(){
    usersManager.registerUser();
}

void HomeBudget::printAllUsers() {
    usersManager.printAllUsers();
}

void HomeBudget::loginUser() {
    usersManager.loginUser();
}

