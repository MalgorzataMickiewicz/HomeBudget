#include "UsersManager.h"

using namespace std;

void UsersManager::registerUser() {
    Users user = getDateOfNewUser();
    users.push_back(user);
    usersFileManager.addUserToFile(user);
    cout << "Konto zalozone" << endl;
    Sleep(1000);
}

Users UsersManager::getDateOfNewUser() {
    Users user;
    user.setUserID(getIDNewUser());

    string userLogin;
    do {
        system("cls");
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

void UsersManager::loginUser() {
    Users user;
    int counter = 0;
    string userLogin;
    string userPassword;
    system("cls");
    cout << "----------"<< "LOGOWANIE" << "----------" << endl << "Podaj login: ";
    cin>>userLogin;

    for(int i = 0; i<users.size(); i++) {
        if(users[i].getUserLogin() == userLogin) {
            for(int j=0; j<3; j++) {
                cout << "Podaj haslo. Pozostalo prob: " << 3-j << ": ";
                cin >> userPassword;
                if(users[i].getUserPassword() == userPassword) {
                    loggedUserID = users[i].getUserID();
                    cout << "Zalogowales sie" << endl;
                    Sleep(1000);
                    j = 3;
                    counter++;
                } else if(j == 2) {
                    cout << "Podales 3 razy bledne haslo. Poczekaj 3 sekundy i sprobuj ponownie" << endl;
                    Sleep(3000);
                    j = -1;
                    system("cls");
                }
            }
        }
    }
    if(counter == 0) {
        cout << "Nie ma uzytkownika z takim loginem" << endl;
        Sleep(1000);
    }
}

bool UsersManager::ifUserIsLogged() {
    if(loggedUserID > 0) {
        return true;
    } else {
        return false;
    }
}

int UsersManager::giveIdLoggedUser() {
    return loggedUserID;
}

void UsersManager::logoutUser() {
    loggedUserID = 0;
}

void UsersManager::changePassword() {
    system("cls");
    string userPassword;
    cout << "----------"<< "ZMIANA HASLA" << "----------" << endl << "Podaj nowe haslo: ";
    cin >> userPassword;
    addNewPasswordToVector(userPassword);
}

void UsersManager::addNewPasswordToVector(string userPassword) {
    Users user;
    int idCurrentUser = 0;
    for(int i = 0; i < users.size(); i++) {
        if(users[i].getUserID() == loggedUserID) {
            users[i].setUserPassword(userPassword);
            user.setUserPassword(userPassword);
            cout<<"Haslo zostalo zmienione"<<endl;
            Sleep(1000);
            idCurrentUser = users[i].getUserID();
            usersFileManager.addUserWithNewPasswordToFile(user, idCurrentUser);
        }
    }
}

