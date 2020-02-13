#ifndef DATEOPERATIONS_H
#define DATEOPERATIONS_H

#include "AuxiliaryMethods.h"

#include <iostream>
#include <string>

using namespace std;

class DateOperations {

public:
    int static conversionStringToIntDate(string dateInString);
    int static checkActualDate();
    bool static checkMonth(int month, int year, int day);
    bool static checkYear(int month, int year, int day);
    string static conversionIntToStringSeparatedDash(int dateInInt);
    int static checkCurrentMonth();
    int static checkPreviousMonth();
    int static checkNumberOfDay(int previousMonth, int year);
    int static getFirstDayOfPreviousMonth(int previousMonthDate);
    string static separateDate(string range);
};

#endif
