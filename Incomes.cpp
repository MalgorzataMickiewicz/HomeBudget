#include "Incomes.h"

//Setter
void Incomes::setIncomeDate(int newIncomeDate) {
    dateOfIncome = newIncomeDate;
}
void Incomes::setIncomeValue(float newIncomeValue) {
    valueOfIncome = newIncomeValue;
}
void Incomes::setIncomeName(string newIncomeName) {
    nameOfIncome = newIncomeName;
}
void Incomes::setLoggedUserID(int newLoggedUserID) {
    LOGGED_USER_ID = newLoggedUserID;
}

//Getter
int Incomes::getIncomeDate() {
    return dateOfIncome;
}
float Incomes::getIncomeValue() {
    return valueOfIncome;
}
string Incomes::getIncomeName() {
    return nameOfIncome;
}
int Incomes::getUserID() {
    return LOGGED_USER_ID;
}
