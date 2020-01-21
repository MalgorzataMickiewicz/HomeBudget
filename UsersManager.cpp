#include "UsersManager.h"

using namespace std;

void UsersManager::registerUser() {
    Users user = getDateOfNewUser();
    users.push_back(user);
    //usersFileManager.addUserToFile(user);
    cout << "Konto zalozone" << endl;
    Sleep(1000);
}

Users UsersManager::getDateOfNewUser() {
    Users user;
    user.setUserID(getIDNewUser());

    string userLogin;
    do {
        cout << "----------"<< "REJESTRACJA" << "----------" << endl << "Podaj login: ";
        cin >> userLogin;
        user.setUserLogin(userLogin);

    } while (checkExistingOfLogin(user.getUserLogin()) == true);

    string userName;
    cout << "Podaj imie: ";
    cin >> userName;
    user.setUserName(userName);

    string userLastname;
    cout << "Podaj nazwisko: ";
    cin >> userLastname;
    user.setUserLastname(userLastname);

    string userPassword;
    cout << "Podaj haslo: ";
    cin >> userPassword;
    user.setUserPassword(userPassword);

    return user;
}

bool UsersManager::checkExistingOfLogin(string userLogin) {
    for(int i=0; i<users.size(); i++) {
        if(users[i].getUserLogin() == userLogin) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

int UsersManager::getIDNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserID()+ 1;
}

void UsersManager::printAllUsers() {
    system("cls");
    cout << "Zapisani uzytkownicy:" << endl;
    for(int i = 0; i< users.size(); i++) {
        cout << users[i].getUserID() << endl;
        cout << users[i].getUserLogin() << endl;
        cout << users[i].getUserName() << endl;
        cout << users[i].getUserLastname() << endl;
        cout << users[i].getUserPassword() << endl;
        system("Pause");
    }
}

void UsersManager::loginUser() {
    Users user;
    int counter = 0;
    string userLogin;
    string userPassword;
    system("cls");
    cout << "----------"<< "LOGOWANIE" << "----------" << endl << "Podaj login: ";
    cin>>userLogin;

    for(int i=0; i<users.size(); i++) {
        if(users[i].getUserLogin() == userLogin) {
            for(int i=0; i<3; i++) {
                cout << "Podaj haslo. Pozostalo prob: " << 3-i << ": ";
                cin >> userPassword;
                if(users[i].getUserPassword() == userPassword) {
                    logedUserID = users[i].getUserID();
                    cout << "Zalogowales sie" << endl;
                    Sleep(1000);
                    i=3;
                    counter++;
                }
                else if(i == 2){
                    cout << "Podales 3 razy bledne haslo. Poczekaj 3 sekundy i sprobuj ponownie" << endl;
                    Sleep(3000);
                    i=-1;
                    system("cls");
                }
        }
        }
        }
        if(counter == 0){
        cout << "Nie ma uzytkownika z takim loginem" << endl;
        Sleep(1000);
    }
}


