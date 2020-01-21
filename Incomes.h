#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>

using namespace std;

class Incomes {

    int dateOfIncomes;
    float valueOfIncomes;
    string nameOfIncomes;

public:
//Setters
    void setIncomesDate(int newIncomesDate);
    void setIncomesValue(float newIncomesValue);
    void setIncomesName(string newIncomesname);

//Getters
    int getIncomesDate();
    float getIncomesValue();
    string getIncomesName();

};

#endif
