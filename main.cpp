#include "HomeBudget.h"

#include <iostream>

using namespace std;

int main()
{
    HomeBudget homeBudget;

    homeBudget.registerUser();
    homeBudget.printAllUsers();
    homeBudget.loginUser();

    return 0;
}
