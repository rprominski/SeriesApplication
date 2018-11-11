//
// Created by rafal on 09.11.18.
//

#include <iostream>
#include "../include/InputValidator.h"

int InputValidator::cinInt(std::string message) {
    std::cout << message;
    std::string s;
    int number;
    while(std::getline(std::cin, s)) {
        try {
            number = stoi(s);
            return number;
        } catch (std::exception &ex) {
                std::cout << "You must give a number.\nTry again\n";
        }
    }
}

int InputValidator::icinInt(std::string message) {
    std::cin.ignore();
    return cinInt(message);
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
