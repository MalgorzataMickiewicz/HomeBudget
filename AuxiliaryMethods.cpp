#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>

#include "AuxiliaryMethods.h"

using namespace std;

int AuxiliaryMethods::conversionStringToInt(string dateInString){

    string shortDateInString = "";
    string yearInString = "";
    string monthInString = "";
    string dayInString = "";
    int dateInInt = 0;

        //DODAC WALIDACJE SPRAWDZAJACA CZY DATA JEST POPRAWNA

    dayInString = dateInString.substr(8,2);
    monthInString = dateInString.substr(5,2);
    yearInString = dateInString.substr(0,4);

    shortDateInString.insert(0,yearInString);
    shortDateInString.insert(4,monthInString);
    shortDateInString.insert(6,dayInString);
    cout << "shorDatyeInString: " << shortDateInString << endl;

    istringstream changeDateFormat(shortDateInString);
    changeDateFormat >> dateInInt;


    cout << "date in int: " << dateInInt << endl;
    system("Pause");

    return dateInInt;
}
