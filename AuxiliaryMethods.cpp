#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <windows.h>

#include "AuxiliaryMethods.h"

using namespace std;

float AuxiliaryMethods::conversionStringToFloat(string valueInString) {
    string comma = ",";
    string dot = ".";
    string shortValueInString = "";
    int lengthOfString = 0;

    int placeOfComma = valueInString.find(comma);
    if(placeOfComma != string::npos){
        valueInString.replace(placeOfComma,1,".");
        lengthOfString = valueInString.length();
        shortValueInString = valueInString.substr(0,placeOfComma+3);
    }
    else{
        int placeOfDot = valueInString.find(dot);
        if(placeOfComma != string::npos){
        lengthOfString = valueInString.length();
        shortValueInString = valueInString.substr(0,placeOfDot+3);
        }
        else{
        shortValueInString = valueInString;
        }
    }
    float valueInFloat = atof(shortValueInString.c_str());
    return valueInFloat;
}

int AuxiliaryMethods::conversionStringToInt(string valueInString) {

    int valueInInt = atoi(valueInString.c_str());
    return valueInInt;
}

string AuxiliaryMethods::conversionIntToString(int numberInInt) {
    ostringstream ss;
    ss << numberInInt;
    string numberInString = ss.str();
    return numberInString;
}

string AuxiliaryMethods::conversionFloatToString(float numberInFloat){
    stringstream ss;
    ss << numberInFloat;
    string s(ss.str());
    return s;
}
