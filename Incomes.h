#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Incomes {

    int incomeID;
    int LOGGED_USER_ID;
    int dateOfIncome;
    float valueOfIncome;
    string nameOfIncome;

public:

//Setters
    void setIncomeID(int incomeID);
    void setIncomeDate(int newIncomeDate);
    void setIncomeValue(float newIncomeValue);
    void setIncomeName(string newIncomeName);
    void setLoggedUserID(int newLoggedUserID);

//Getters
    int getIncomeID();
    int getIncomeDate();
    float getIncomeValue();
    string getIncomeName();
    int getUserID();

};

#endif
