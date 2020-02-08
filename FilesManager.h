#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class FileManager{
    const string NAME_OF_FILE;

public:
    FileManager(string nameOfFile) : NAME_OF_FILE(nameOfFile){
    }
    string getNameOfFile(){
    return NAME_OF_FILE;
    }
};

#endif

