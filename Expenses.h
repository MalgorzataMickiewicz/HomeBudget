#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>

using namespace std;

class Expenses {

    int expenseID;
    int LOGGED_USER_ID;
    int dateOfExpense;
    float valueOfExpense;
    string nameOfExpense;

public:
//Setters
    void setExpenseID(int expenseID);
    void setExpenseDate(int newExpenseDate);
    void setExpenseValue(float newExpenseValue);
    void setExpenseName(string newExpenseName);
    void setLoggedUserID(int newLoggedUserID);

//Getters
    int getExpenseID();
    int getExpenseDate();
    float getExpenseValue();
    string getExpenseName();
    int getUserID();

    bool operator<(const Expenses& other) const
    {
      return dateOfExpense < other.dateOfExpense;
    }
};

#endif
