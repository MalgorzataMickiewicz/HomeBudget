#include "HomeBudget.h"

#include <iostream>

using namespace std;

int main()
{
    HomeBudget homeBudget("Users.xml", "Incomes.xml");

    //homeBudget.registerUser();
    //homeBudget.addIncome();
    //homeBudget.printAllUsers();
    homeBudget.loginUser();
    //homeBudget.printAllUsers();
    homeBudget.addIncome();
    homeBudget.printAllIncomes();
    //homeBudget.addExpense();
    //homeBudget.printAllExpenses();
    //homeBudget.changePassword();

    return 0;
}
