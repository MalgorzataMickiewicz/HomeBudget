#include "Markup.h"
#include "IncomesFileManager.h"

using namespace std;

void IncomesFileManager::addIncomeToFile(Incomes income){

    CMarkup xml;
    bool fileExists = xml.Load( "Incomes.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();//set on Incomes
    xml.IntoElem();//into Incomes
    xml.AddElem("Income");//add Income element
    xml.IntoElem();//into Income
    xml.AddElem("Date", income.getIncomeDate());//Add elemets lke Id, Login, Password, etc.
    xml.AddElem("Value", income.getIncomeValue());
    xml.AddElem("Name", income.getIncomeName());
    xml.Save("Incomes.xml");
}

/*
vector <Users> UsersFileManager::loadUsersFromFile(){
    Users user;
    vector <Users> users;
    CMarkup xml;

    bool fileExists = xml.Load( "Users.xml" );
    if (fileExists){
            MCD_STR UserId;//create string variable UserId
            MCD_STR Login;//create string variable Login
            MCD_STR Name;//create string variable Name
            MCD_STR LastName;//create string variable LastName
            MCD_STR Password;//create string variable Password
            while (xml.FindChildElem("User")){
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
*/
