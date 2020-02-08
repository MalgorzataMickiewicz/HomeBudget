#include "HomeBudget.h"

#include <iostream>

using namespace std;

int main() {
    HomeBudget homeBudget("users.xml", "incomes.xml", "expenses.xml");

    //homeBudget.registerUser();
    //homeBudget.addIncome();
    //homeBudget.printAllUsers();
    homeBudget.loginUser();
    //homeBudget.printAllUsers();
    homeBudget.addIncome();
    //homeBudget.addIncome();
    //homeBudget.printAllIncomes();
    //homeBudget.addExpense();
    //homeBudget.addExpense();
    //homeBudget.printAllExpenses();
    //homeBudget.changePassword();
    homeBudget.summOfIncomes();
    homeBudget.summOfExpenses();
    homeBudget.showBalance();

    return 0;
}
