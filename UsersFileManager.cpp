#include "Markup.h"
#include "UsersFileManager.h"

using namespace std;

void UsersFileManager::addUserToFile(Users user) {

    CMarkup xml;
    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();//set on Users
    xml.IntoElem();//into Users
    xml.AddElem("User");//add User element
    xml.IntoElem();//into User
    xml.AddElem("UserId", user.getUserID());//Add elemets lke Id, Login, Password, etc.
    xml.AddElem("Login", user.getUserLogin());
    xml.AddElem("Name", user.getUserName());
    xml.AddElem("LastName", user.getUserLastname());
    xml.AddElem("Password", user.getUserPassword());
    xml.Save("users.xml");
}

vector <Users> UsersFileManager::loadUsersFromFile() {
    Users user;
    vector <Users> users;
    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );
    if (fileExists) {
        MCD_STR UserId;//create string variable UserId
        MCD_STR Login;//create string variable Login
        MCD_STR Name;//create string variable Name
        MCD_STR LastName;//create string variable LastName
        MCD_STR Password;//create string variable Password
        while (xml.FindChildElem("User")) {
            xml.FindElem();//set on Users
            xml.IntoElem();//into Users
            xml.IntoElem();//into User
            xml.FindElem("UserId");//looking for UserId
            UserId = xml.GetData();
            xml.FindElem("Login");//looking for Login
            Login = xml.GetData();
            xml.FindElem("Name");//looking for Name
            Name = xml.GetData();
            xml.FindElem("LastName");//looking for LastName
            LastName = xml.GetData();
            xml.FindElem("Password");//looking for Password
            Password = xml.GetData();
            xml.OutOfElem();//out of Child Elem User
            xml.OutOfElem();//out of User
            user.setUserID(atoi(UserId.c_str()));
            user.setUserLogin(Login);
            user.setUserName(Name);
            user.setUserLastname(LastName);
            user.setUserPassword(Password);
            users.push_back(user);
        }
    }
    return users;
}

void UsersFileManager::addUserWithNewPasswordToFile(Users user, int idCurrentUser) {
    CMarkup xml;
    bool fileExists = xml.Load( "users.xml" );
    if (fileExists) {
        MCD_STR UserId;
        MCD_STR Password;
        while (xml.FindChildElem("User")) {
            xml.FindElem();//set on Users
            xml.IntoElem();//into Users
            xml.IntoElem();//into User
            xml.FindElem("UserId");//looking for UserId
            UserId = xml.GetData();
            if(atoi(UserId.c_str()) == idCurrentUser) {
                xml.FindElem("Password");
                xml.RemoveElem();
                xml.AddElem("Password", user.getUserPassword());
                xml.OutOfElem();
                xml.OutOfElem();
                xml.Save("users.xml");
            } else {
                xml.OutOfElem();
                xml.OutOfElem();
            }
        }
    } else
        cout << "Nie udalo sie otworzyc pliku " << getNameOfFile() << " i zapisac w nim danych." << endl;
}


