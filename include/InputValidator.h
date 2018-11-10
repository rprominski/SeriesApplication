//
// Created by rafal on 09.11.18.
//

#ifndef SERIESAPPLICATION_INPUTVALIDATOR_H
#define SERIESAPPLICATION_INPUTVALIDATOR_H

#include <string>

class InputValidator {
public:

    static int cinInt(std::string message = "");

    static std::string cinString(std::string message = "");

    static std::string getLine(std::string message = "");

    static std::string iGetline(std::string message = "");

    static int icinInt(std::string message = "");

};


#endif //SERIESAPPLICATION_INPUTVALIDATOR_H
