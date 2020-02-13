#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <windows.h>

#include "DateOperations.h"

using namespace std;

int DateOperations::checkActualDate() {

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


    if (dayInString2.length() < 2) {
        dayInString2.insert(0,"0");
    }

    if (monthInString2.length() < 2) {
        monthInString2.insert(0,"0");
    }

    actualDateInString.insert(0,yearInString2);
    actualDateInString.insert(4,monthInString2);
    actualDateInString.insert(6,dayInString2);

    istringstream changeDateFormat(actualDateInString);
    changeDateFormat >> actualDateInInt;

    return actualDateInInt;
}

int DateOperations::checkCurrentMonth(){
    int firstDayOfCurrentMonth = 0;
    string dayInStirng = "";

    int currentDateInInt = checkActualDate();
    string currentDateInString = AuxiliaryMethods::conversionIntToString(currentDateInInt);
    dayInStirng = currentDateInString.substr(6,2);
    int currentDayInInt = AuxiliaryMethods::conversionStringToInt(dayInStirng);
    firstDayOfCurrentMonth = currentDateInInt - currentDayInInt + 1;

    return firstDayOfCurrentMonth;
}

int DateOperations::checkPreviousMonth(){
    int previousMonthInInt = 0;
    int year = 0;
    int previousMonthDate = 0;
     string previousDateInString = "";

    int currentDateInInt = checkActualDate();
    string currentDateInString = AuxiliaryMethods::conversionIntToString(currentDateInInt);
    string currentMonthInString = currentDateInString.substr(4,2);
    string currentDayInString = currentDateInString.substr(6,2);
    string currentYearInString = currentDateInString.substr(0,4);

    int currentDayInInt = AuxiliaryMethods::conversionStringToInt(currentDayInString);
    int currentMonthInInt = AuxiliaryMethods::conversionStringToInt(currentMonthInString);
    int currentYearInInt = AuxiliaryMethods::conversionStringToInt(currentYearInString);

    if(currentMonthInInt > 1){
        previousMonthInInt = currentMonthInInt - 1;
        year = currentYearInInt;
    }
    else{
        previousMonthInInt = 12;
        year = currentYearInInt - 1;
    }
    int numberOfDayPreviousMonthInInt = checkNumberOfDay(previousMonthInInt, year);
    string numberOfDayPreviousMonthInString = AuxiliaryMethods::conversionIntToString(numberOfDayPreviousMonthInInt);
    string previousMonthInString = AuxiliaryMethods::conversionIntToString(previousMonthInInt);
    if(previousMonthInInt < 10){
        previousMonthInString.insert(0,"0");
    }
    string yearInString = AuxiliaryMethods::conversionIntToString(year);
    previousDateInString.insert(0,yearInString);
    previousDateInString.insert(4,previousMonthInString);
    previousDateInString.insert(6,numberOfDayPreviousMonthInString);

    previousMonthDate = AuxiliaryMethods::conversionStringToInt(previousDateInString);

    return previousMonthDate;
}

int DateOperations::getFirstDayOfPreviousMonth(int previousMonthDateInInt){
    int firstDayOfPreviousMonthInInt = 0;
    string previousMonthDateInString = AuxiliaryMethods::conversionIntToString(previousMonthDateInInt);
    string numberOfDayInString = previousMonthDateInString.substr(6,2);
    int numberOfDayInInt = AuxiliaryMethods::conversionStringToInt(numberOfDayInString);
    firstDayOfPreviousMonthInInt = previousMonthDateInInt - numberOfDayInInt +1;

    return firstDayOfPreviousMonthInInt;
}

int DateOperations::checkNumberOfDay(int previousMonth, int year){
    int numberOfDayInMonth = 0;
    if (previousMonth == 4 || previousMonth == 6 || previousMonth == 9 || previousMonth == 11) {
            numberOfDayInMonth = 30;
            return numberOfDayInMonth;
    }else if (previousMonth == 2) {
        bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (leapyear == 0) {
                numberOfDayInMonth = 28;
                return numberOfDayInMonth;
            }else {
             numberOfDayInMonth = 29;
            return numberOfDayInMonth;
        }
        }else if(previousMonth == 1 || previousMonth== 3 || previousMonth == 5 || previousMonth == 7 || previousMonth == 8 || previousMonth == 10 || previousMonth == 12) {
            numberOfDayInMonth = 31;
            return numberOfDayInMonth;
        }
    }

string DateOperations::separateDate(string range){
    string firstDateWithoutDashes = range.substr(0,4);
    firstDateWithoutDashes.insert(4,(range.substr(5,2)));
    firstDateWithoutDashes.insert(6,(range.substr(8,2)));
    return firstDateWithoutDashes;
}

int DateOperations::conversionStringToIntDate(string dateInString) {

    string shortDateInString = "";
    string yearInString = "";
    string monthInString = "";
    string dayInString = "";
    int dateInInt = 0;
    int dayInInt = 0;
    int monthInInt = 0;
    int yearInInt = 0;

    if(dateInString.length() != 10) {
        cout << "Wprowadziles bledna date!" << endl;
        return 0;
    }
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

    if(checkMonth(monthInInt, yearInInt, dayInInt) == false) {
        cout << "Podales bledna date" << endl;
        return 0;
    }
    if(checkYear(monthInInt, yearInInt, dayInInt) == false) {
        cout << "Wprowadziles zbyt stara date! Zbieramy tylko dane z XI wieku" << endl;
        return 0;
    }
    return dateInInt;
}

bool DateOperations::checkMonth(int month, int year, int day) {
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if(day < 31 && day > 0) {
            return true;
        } else {
            return false;
        }
    } else if (month == 2) {
        bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (leapyear == 0) {
            if(day < 29 && day > 0) {
                return true;
            } else {
                return false;
            }
        } else {
            if(day < 30 && day > 0) {
                return true;
            } else {
                return false;
            }
        }
    } else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {

        if(day < 32 && day > 0) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool DateOperations::checkYear(int month, int year, int day) {
    if(year < 2000) {
        return false;
    } else {
        return true;
    }
}

string DateOperations::conversionIntToStringSeparatedDash(int dateInInt) {

    string dateSeparatedDash = "";

    ostringstream changeDateFormat;
    changeDateFormat << dateInInt;
    string dateInString = changeDateFormat.str();

    dateSeparatedDash = dateInString.substr(0,4);
    dateSeparatedDash.insert(4,"-");
    dateSeparatedDash.insert(5,dateInString.substr(4,2));
    dateSeparatedDash.insert(7,"-");
    dateSeparatedDash.insert(8,dateInString.substr(6,2));

    return dateSeparatedDash;
}
