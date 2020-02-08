#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <string>

using namespace std;

class AuxiliaryMethods {

public:
    int static conversionStringToIntDate(string dateInString);
    int static conversionStringToInt(string valueInString);
    int static checkActualDate();
    bool static checkMonth(int month, int year, int day);
    bool static checkYear(int month, int year, int day);
    float static conversionStringToFloat(string valueInString);
    string static conversionIntToStringSeparatedDash(int dateInInt);
    string static conversionIntToString(int numberInInt);
    string static conversionFloatToString(float numberInFloat);
};

#endif
