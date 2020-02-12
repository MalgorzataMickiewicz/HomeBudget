#include "HomeBudget.h"

#include <iostream>

using namespace std;

int main() {
    HomeBudget homeBudget("users.xml", "incomes.xml", "expenses.xml");
    int choice = 0;

     while(1) {
        choice = homeBudget.showMenu(choice);
        if(choice == 1) {
            homeBudget.registerUser();
        } else if(choice == 2) {
            homeBudget.loginUser();
        } else if(choice == 3) {
            exit(0);
        }
        while(homeBudget.ifUserIsLogged()) {
            choice = homeBudget.showSecondMenu(choice);
            if(choice == 1) {
                homeBudget.addIncome();
            } else if(choice == 2) {
                homeBudget.addExpense();
            } else if(choice == 3) {
                homeBudget.showCurrentMonth();
            } else if(choice == 4) {
                homeBudget.showPreviousMonth();
            } else if(choice == 5) {
                homeBudget.showSelectedPeriod();
            } else if(choice == 6) {
                homeBudget.changePassword();
            } else if(choice == 7) {
                homeBudget.logoutUser();
            }
        }
     }
    return 0;
    }


