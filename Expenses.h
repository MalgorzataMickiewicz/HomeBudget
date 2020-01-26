#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>

using namespace std;

class Expenses {

    int dateOfExpense;
    float valueOfExpense;
    string nameOfExpense;

public:
//Setters
    void setExpenseDate(int newExpenseDate);
    void setExpenseValue(float newExpenseValue);
    void setExpenseName(string newExpenseName);

//Getters
    int getExpenseDate();
    float getExpenseValue();
    string getExpenseName();

};

#endif
