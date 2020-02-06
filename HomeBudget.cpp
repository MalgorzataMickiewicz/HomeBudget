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
    if(usersManager.ifUserIsLogged()){
        budgetManager = new BudgetManager(NAME_OF_FILE_WITH_INCOMES, usersManager.giveIdLoggedUser());
    }
}

bool HomeBudget::ifUserIsLogged(){
    if(usersManager.ifUserIsLogged()){
    }
}

void HomeBudget::logoutUser(){
    usersManager.logoutUser();
    delete budgetManager;
    budgetManager = NULL;
}

void HomeBudget::changePassword() {
    usersManager.changePassword();
}

void HomeBudget::addIncome() {
    budgetManager->addIncome();
}

void HomeBudget::printAllIncomes(){
    budgetManager->printAllIncomes();
}

void HomeBudget::addExpense() {
    budgetManager->addExpense();
}

void HomeBudget::printAllExpenses(){
    budgetManager->printAllExpenses();
}
