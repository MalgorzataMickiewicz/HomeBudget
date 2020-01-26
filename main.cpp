#include "HomeBudget.h"

#include <iostream>

using namespace std;

int main()
{
    HomeBudget homeBudget;

    //homeBudget.registerUser();
    //homeBudget.loginUser();
   // homeBudget.addIncome();
    //homeBudget.printAllIncomes();
    homeBudget.addExpense();
    homeBudget.printAllExpenses();

    return 0;
}
