//
// Created by Owen Powell on 2019-03-03.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include "FileConfigReader.h"

using namespace std;

//create ConfigReader object
ConfigReader::ConfigReader() {}

//ConfigReader destructor, throws error
//ConfigReader::~ConfigReader(){}

//call getString function here
string ConfigReader::getString(){

    string configProperties;

    //try/catch block to detect exceptions when opening the file
    try {
        //open config file
        ifstream inFile("config.txt");

        //get contents of file
        getline(inFile, configProperties);
        //read until end of file
        while (!inFile.eof()) {
            //read in to variable
            inFile >> configProperties;
            //print contents of variable
            cout << configProperties << endl;
        }
        //close file
        inFile.close();
    }
    //catch a failure to open file
    catch (const ifstream::failure &e) {
        cout << "Exception opening/reading file" << endl;
    }

    return 0;
}