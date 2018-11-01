//
// Created by rafal on 25/10/18.
//

#include "../include/UserInterface.h"
#include "../include/FileWriter.h"
#include <iostream>

UserInterface::UserInterface() : end(0) {}

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
        removeMovie();
    }

    if(action == 3) {
        showAllMovies();
    }

    if(action == 4) {
        end = 1;
    }
}

void UserInterface::start() {
    loadSavedFiles();
    while(!end) {
        showOptions();
        getAction();
        performAction();
        wait();
        system("clear");
    }
}

void UserInterface::addFilm() {
    std::cout<< "Which type would you like to add?\n"
        << "1.Movie\n";
       // << "2.Series\n";

    std::string title,description;
    int type,rate,duration;

    std::cin>>type;
    std::cout<<"Title: "; std::cin.ignore(); std::getline(std::cin,title);
    std::cout<<"Descripion: "; std::getline(std::cin,description);
    std::cout<<"Rate: "; rate = cinInt();
    std::cout<<"Duration (in minutes): "; duration = cinInt();

    if(pool.add(Movie(title,description,rate,duration))) {
        FileWriter fileWriter;
        fileWriter.write(Movie(title,description,rate,duration));
    }
}

void UserInterface::showAllMovies() {
    for(auto i : pool.getRecords()) {
        std:: cout << i.toString() << "\n\n";
    }
}

void UserInterface::removeMovie() {
    std::string name;
    std::cout << "Type name of movie you'd like to remove \n";
    std::cin.ignore();
    std::getline(std::cin,name);
    FileWriter fileWriter;
    if(!fileWriter.deleteRecord(name)) {
        std::cout << "Movie not exists \n";
    }
}

void UserInterface::loadSavedFiles() {
    FileWriter fileWriter;
    for(auto movie :fileWriter.getAllRecords()) {
        pool.add(movie);
    }
}

void UserInterface::wait() {
    std::cout << "Press enter to continue ...";
    std::cin.ignore();
    std::cin.get();
}

int UserInterface::cinInt() {
    std::string s;
    int number;
    while(std::getline(std::cin, s)) {
        try {
            number = stoi(s);
            return number;
        } catch (std::exception &ex) {
            std::cout << "You must give a number. Try again\n";
        }
    }
}
