//
// Created by rafal on 25/10/18.
//

#include "../include/UserInterface.h"
#include "../include/FileWriter.h"
#include <iostream>

void UserInterface::showOptions() {
    std::cout << "1. Add film \n"
        << "2. Remove film \n"
        << "3. Show all films \n"
        << "4 Exit \n";


}

void UserInterface::getAction() {
    std::cin>>action;
}

void UserInterface::performAction() {
    if(action == 1) {
        addFilm();
    }

    if(action == 2) {

    }

    if(action == 3) {
        showAllFilms();
    }

    if(action == 4) {
        end = 1;
    }
}

void UserInterface::start() {

    while(!end) {
        showOptions();
        getAction();
        performAction();
    }
}

UserInterface::UserInterface() : end(0) {}

void UserInterface::addFilm() {
    std::cout<< "Which type would you like to add?\n"
        << "1.Movie\n"
        << "2.Series\n";

    std::string title,description;
    int type,rate,duration;

    std::cin>>type;
    std::cout<<"Title: "; std::cin >> title; //NEED GETLINE
    std::cout<<"Descripion: "; std::cin >> description;/*getline(std::cin,description); std::cin.ignore(); //NEED GETLINE*/
    std::cout<<"Rate: "; std::cin >> rate;
    std::cout<<"Duration (in minutes): "; std::cin >> duration;

    if(pool.add(Movie(title,description,rate,duration))) {
        FileWriter fileWriter;
        fileWriter.write(Movie(Movie(title,description,rate,duration)));
    }

}

void UserInterface::showAllFilms() {
    for(auto i : pool.getRecords()) {
        std:: cout << i.toString() << std::endl;
    }
}
