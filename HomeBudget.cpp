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
    incomesManager.addIncome();
}

void HomeBudget::printAllIncomes(){
    incomesManager.printAllIncomes();
}

void HomeBudget::addExpense() {
    expensesManager.addExpense();
}

void HomeBudget::printAllExpenses(){
    expensesManager.printAllExpenses();
}
