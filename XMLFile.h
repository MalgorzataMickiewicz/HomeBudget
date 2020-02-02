#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class XMLFile{
    const string NAME_OF_FILE;

public:
    XMLFile(string nameOfFile) : NAME_OF_FILE(nameOfFile){
    }
    string getNameOfFile(){
    return NAME_OF_FILE;}

    //bool isTheFileIsempty();
    //bool isTheTemporaryFileIsempty();
};

#endif

