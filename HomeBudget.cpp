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

void HomeBudget::changePassword() {
    usersManager.changePassword();
}

void HomeBudget::addIncome() {
    budgetManager.addIncome();
}

void HomeBudget::printAllIncomes(){
    budgetManager.printAllIncomes();
}

void HomeBudget::addExpense() {
    budgetManager.addExpense();
}

void HomeBudget::printAllExpenses(){
    budgetManager.printAllExpenses();
}
