#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <string>

using namespace std;

class AuxiliaryMethods {

public:
    int static conversionStringToInt(string valueInString);
    float static conversionStringToFloat(string valueInString);
    string static conversionIntToString(int numberInInt);
    string static conversionFloatToString(float numberInFloat);
};

#endif
