#include "Incomes.h"

//Setter
void Incomes::setIncomesDate(int newIncomesDate) {
    dateOfIncomes=newIncomesDate;
}
void Incomes::setIncomesValue(float newIncomesValue) {
    valueOfIncomes=newIncomesValue;
}
void Incomes::setIncomesName(string newIncomesName) {
    nameOfIncomes=newIncomesName;
}

//Getter
int Incomes::getIncomesDate() {
    return dateOfIncomes;
}
float Incomes::getIncomesValue() {
    return valueOfIncomes;
}
string Incomes::getIncomesName() {
    return nameOfIncomes;
}
