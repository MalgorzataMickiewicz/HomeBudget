#include "HomeBudget.h"
#include "UsersManager.h"


int HomeBudget::showMenu(int choice){
     system("cls");
     do{
        cout << "------MENU------" << endl;
        cout << "1. Rejestracja" << endl;
        cout << "2. Logowanie" << endl;
        cout << "3. Zamknij program" << endl;
        cout << "Twoj wybor: ";
        cin >> choice;
         if( !cin ){
                cout << "Wpisales nieprawidlowy znak!" << endl;
                Sleep(3000);
                cin.clear();
                cin.sync();
                system("cls");
                }
            else{
                return choice;
            }
     }while(1);
}

int HomeBudget::showSecondMenu(int choice){
     system("cls");
     do{
            cout << "------MENU------" << endl;
            cout << "1. Dodaj przychod" << endl;
            cout << "2. Dodaj wydatek" << endl;
            cout << "3. Bilans z biezacego miesiaca" << endl;
            cout << "4. Bilans z poprzedniego miesiaca" << endl;
            cout << "5. Bilans z wybranego okresu" << endl;
            cout << "6. Zmien haslo" << endl;
            cout << "7. Wyloguj sie" << endl;
            cout << "Twoj wybor: ";
            cin >> choice;
            if( !cin ){
                cout<< "Wpisales nieprawidlowy znak!" << endl;
                Sleep(2000);
                cin.clear();
                cin.sync();
                system("cls");
                }
            else{
                return choice;
            }
     } while(1);
}

void HomeBudget::registerUser() {
    usersManager.registerUser();
}

void HomeBudget::loginUser() {
    usersManager.loginUser();
    if(usersManager.ifUserIsLogged()) {
        budgetManager = new BudgetManager(NAME_OF_FILE_WITH_INCOMES, NAME_OF_FILE_WITH_EXPENSES, usersManager.giveIdLoggedUser());
    }
}

bool HomeBudget::ifUserIsLogged() {
    if(usersManager.ifUserIsLogged()) {
    }
}

void HomeBudget::logoutUser() {
    usersManager.logoutUser();
    delete budgetManager;
    budgetManager = NULL;
}

void HomeBudget::changePassword() {
    usersManager.changePassword();
}

void HomeBudget::addIncome() {
    budgetManager->addIncome();
}

void HomeBudget::addExpense() {
    budgetManager->addExpense();
}

void HomeBudget::showCurrentMonth(){
    budgetManager->showCurrentMonth();
}

void HomeBudget::showPreviousMonth(){
    budgetManager->showPreviousMonth();
}

void HomeBudget::showSelectedPeriod(){
    budgetManager->showSelectedPeriod();
}
