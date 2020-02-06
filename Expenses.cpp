#include "Expenses.h"

//Setter
void Expenses::setExpenseID(int newExpenseID) {
    expenseID = newExpenseID;
}
void Expenses::setExpenseDate(int newExpenseDate) {
    dateOfExpense=newExpenseDate;
}
void Expenses::setExpenseValue(float newExpenseValue) {
    valueOfExpense=newExpenseValue;
}
void Expenses::setExpenseName(string newExpenseName) {
    nameOfExpense=newExpenseName;
}
void Expenses::setLoggedUserID(int newLoggedUserID) {
    LOGGED_USER_ID = newLoggedUserID;
}


//Getter
int Expenses::getExpenseID() {
    return expenseID;
}
int Expenses::getExpenseDate() {
    return dateOfExpense;
}
float Expenses::getExpenseValue() {
    return valueOfExpense;
}
string Expenses::getExpenseName() {
    return nameOfExpense;
}
int Expenses::getUserID() {
    return LOGGED_USER_ID;
}

