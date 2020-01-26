#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <windows.h>

#include "AuxiliaryMethods.h"

using namespace std;

int AuxiliaryMethods::conversionStringToInt(string dateInString) {

    string shortDateInString = "";
    string yearInString = "";
    string monthInString = "";
    string dayInString = "";
    int dateInInt = 0;
    int dayInInt = 0;
    int monthInInt = 0;
    int yearInInt = 0;

    dayInString = dateInString.substr(8,2);
    monthInString = dateInString.substr(5,2);
    yearInString = dateInString.substr(0,4);

    shortDateInString.insert(0,yearInString);
    shortDateInString.insert(4,monthInString);
    shortDateInString.insert(6,dayInString);

    istringstream changeDateFormat(shortDateInString);
    changeDateFormat >> dateInInt;

    istringstream changeDayFormat(dayInString);
    changeDayFormat >> dayInInt;

    istringstream changeMonthFormat(monthInString);
    changeMonthFormat >> monthInInt;

    istringstream changeYearFormat(yearInString);
    changeYearFormat >> yearInInt;

    if(checkMonth(monthInInt, yearInInt, dayInInt) == false){
        return 0;
    }
    return dateInInt;
}

bool AuxiliaryMethods::checkMonth(int month, int year, int day){
    if (month == 4 || month == 6 || month == 9 || month == 11){
        if(day< 31 && day > 0){
            return true;
        }
        else{
            return false;
        }
    }
    else if (month == 2){

        bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (leapyear == 0){
            if(day < 29 && day > 0){
                return true;
            }
                else{
                    return false;
                }
            }
        else{
        if(day < 30 && day > 0){
            return true;
        }
        else{
            return false;
        }
        }
    }
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){

        if(day < 32 && day > 0){
        return true;
        }
        else{
            return false;
        }
    }
    else{
        cout << "Wpisales bledna date" << endl;
        system("Pause");
        return false;
    }
    }

int AuxiliaryMethods::checkActualDate() {

    string actualDateInString = "";
    int actualDateInInt = 0;

    SYSTEMTIME st;
    GetSystemTime(&st);

    ostringstream yearInString;
    yearInString << st.wYear;
    string yearInString2 = yearInString.str();

    ostringstream monthInString;
    monthInString << st.wMonth;
    string monthInString2 = monthInString.str();

    ostringstream dayInString;
    dayInString << st.wDay;
    string dayInString2 = dayInString.str();

    if (monthInString2.length() < 2){
        monthInString2.insert(0,"0");
    }

    actualDateInString.insert(0,yearInString2);
    actualDateInString.insert(4,monthInString2);
    actualDateInString.insert(6,dayInString2);

    istringstream changeDateFormat(actualDateInString);
    changeDateFormat >> actualDateInInt;

    return actualDateInInt;
}

