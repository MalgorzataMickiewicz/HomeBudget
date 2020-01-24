#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>

using namespace std;

class Incomes {

    int dateOfIncome;
    float valueOfIncome;
    string nameOfIncome;

public:
//Setters
    void setIncomeDate(int newIncomeDate);
    void setIncomeValue(float newIncomeValue);
    void setIncomeName(string newIncomeName);

//Getters
    int getIncomeDate();
    float getIncomeValue();
    string getIncomeName();

};

#endif
