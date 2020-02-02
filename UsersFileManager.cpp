#include "Markup.h"
#include "UsersFileManager.h"

using namespace std;

void UsersFileManager::addUserToFile(Users user){

    CMarkup xml;
    bool fileExists = xml.Load( "Users.xml" );

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
    xml.Save("Users.xml");
}
/*
vector <Users> UsersFileManager::loadUsersFromFile(){
    Users user;
    vector <Users> users;
    string dataOneUserSeparetedWithVerticalLines = "";

    textFile.open(getNameOfFile().c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, dataOneUserSeparetedWithVerticalLines))
        {
            user = getDateOfUser(dataOneUserSeparetedWithVerticalLines);
            users.push_back(user);
        }
        textFile.close();
    }
  return users;
}
*/
