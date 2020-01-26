#include "Expenses.h"

//Setter
void Expenses::setExpenseDate(int newExpenseDate) {
    dateOfExpense=newExpenseDate;
}
void Expenses::setExpenseValue(float newExpenseValue) {
    valueOfExpense=newExpenseValue;
}
void Expenses::setExpenseName(string newExpenseName) {
    nameOfExpense=newExpenseName;
}

//Getter
int Expenses::getExpenseDate() {
    return dateOfExpense;
}
float Expenses::getExpenseValue() {
    return valueOfExpense;
}
string Expenses::getExpenseName() {
    return nameOfExpense;
}
