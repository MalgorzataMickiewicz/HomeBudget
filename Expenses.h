#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>

using namespace std;

class Expenses {

    int dateOfExpenses;
    float valueOfExpenses;
    string nameOfExpenses;

public:
//Setters
    void setExpensesDate(int newExpensesDate);
    void setExpensesValue(float newExpensesValue);
    void setExpensesName(string newExpensesName);

//Getters
    int getExpensesDate();
    float getExpensesValue();
    string getExpensesName();

};

#endif
