#include "Expenses.h"

//Setter
void Expenses::setExpensesDate(int newExpensesDate) {
    dateOfExpenses=newExpensesDate;
}
void Expenses::setExpensesValue(float newExpensesValue) {
    valueOfExpenses=newExpensesValue;
}
void Expenses::setExpensesName(string newExpensesName) {
    nameOfExpenses=newExpensesName;
}

//Getter
int Expenses::getExpensesDate() {
    return dateOfExpenses;
}
float Expenses::getExpensesValue() {
    return valueOfExpenses;
}
string Expenses::getExpensesName() {
    return nameOfExpenses;
}
