//
// Created by Owen Powell on 2019-03-03.
//

#ifndef INC_5_FILECONFIGREADER_FILECONFIGREADER_H
#define INC_5_FILECONFIGREADER_FILECONFIGREADER_H


#include <iostream>
#include <fstream>
#include <string>
#include <map>


class ConfigReader {
public:
    //definition of getString function
    std::string getString();

    //this function allows access to this class from anywhere
    static ConfigReader &Instance() {
        //creates the only instance of this class
        static std::unique_ptr<ConfigReader> instance(new ConfigReader);
        //always returns same instance
        return *instance;
    }

private:
    //default constructor, only available to members and friends of the class
    ConfigReader();

    //the next two functions prevent copying of the only instance of this class
    ConfigReader(const ConfigReader &old);

    const ConfigReader &operator=(const ConfigReader &old);
    //class destructor, throws error when used
    //~ConfigReader();

};


#endif //INC_5_FILECONFIGREADER_FILECONFIGREADER_H