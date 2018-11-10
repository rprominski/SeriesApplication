//
// Created by rafal on 09.11.18.
//

#include <iostream>
#include "../include/InputValidator.h"
#include "../include/MessagePrinter.h"

int InputValidator::cinInt(std::string message) {
    std::cout << message;
    std::string s;
    int number;
    while(std::getline(std::cin, s)) {
        try {
            number = stoi(s);
            return number;
        } catch (std::exception &ex) {
            MessagePrinter mp;
            mp.badInt(); mp.again();
        }
    }
}

int InputValidator::icinInt(std::string message) {
    std::cin.ignore();
    cinInt(message);
}

std::string InputValidator::cinString(std::string message) {
    std::cout << message;
    std::string s;
    std::getline(std::cin,s);
}

std::string InputValidator::iGetline(std::string message) {
    std::cout << message;
    std::string s;
    std::cin.ignore();
    std::getline(std::cin,s);
    return s;
}

std::string InputValidator::getLine(std::string message) {
    std::cout << message;
    std::string s;
    std::getline(std::cin,s);
    return s;
}
