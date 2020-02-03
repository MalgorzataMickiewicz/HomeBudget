#include "HomeBudget.h"

#include <iostream>

using namespace std;

int main()
{
    HomeBudget homeBudget("Users.txt");

    //homeBudget.registerUser();
    //homeBudget.addIncome();
    //homeBudget.printAllUsers();
    homeBudget.loginUser();
    //homeBudget.printAllIncomes();
    //homeBudget.addExpense();
    //homeBudget.printAllExpenses();
    homeBudget.changePassword();

    return 0;
}
