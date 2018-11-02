//
// Created by rafal on 25/10/18.
//

#include "../include/UserInterface.h"
#include "../include/FileWriter.h"
#include <iostream>
#include <fstream>

UserInterface::UserInterface() : end(0) {}

void UserInterface::showOptions() {
    std::cout << "\n1.Add film\n"
        << "2.Remove film\n"
        << "3.Show all films\n"
        << "4 Exit\n"
        << "5 Show info about film\n"
        << "6 Propose Movie for watching\n";
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

    if(action == 5) {
        showInfoAboutMovie();
    }

    if(action == 6) {
        proposeMovieForWatching();
    }
}

void UserInterface::start() {
    loadSavedFiles();
    while(!end) {
        showOptions();
        getAction();
        performAction();
        wait();
       // system("clear");
    }
}

void UserInterface::addFilm() {
    std::cout<< "Which type would you like to add?\n"
        << "1.Movie\n"
        << "2.Series\n";

    std::string title,description;
    int type,rate,duration;

    std::cin>>type;
    std::cout<<"Title: "; std::cin.ignore(); std::getline(std::cin,title);
    std::cout<<"Descripion: "; std::getline(std::cin,description);
    std::cout<<"Rate: "; rate = cinInt();
    if(type == 1) {
        std::cout<<"Duration (in minutes): "; duration = cinInt();

        if(pool.add(new Movie(title,description,rate,duration))) {
            FileWriter fileWriter;
            fileWriter.write(new Movie(title,description,rate,duration));
        }
    }
    if(type == 2) {
        int episodes;
        std::string days;

        std::cout<<"Episode duration (in minutes): "; duration = cinInt();
        std::cout<<"Number of episodes: "; episodes = cinInt();
        std::cout<<"Broadcast days, possible values : \n"
                   "monday tuesday wednesday thursday friday saturday sunday\n"; getline(std::cin,days);
        if(pool.add(new Series(title,description,rate,duration,episodes,days))) {
            FileWriter fileWriter;
            fileWriter.write(new Series(title,description,rate,duration,episodes,days));
        }
    }
}

void UserInterface::showAllMovies() {
    pool.sort();
    for(auto i : pool.getRecords()) {
        std:: cout << *i << "\n\n";
    }
}

void UserInterface::removeMovie() {
    std::string name;
    std::cout << "Type name of movie you'd like to remove \n";
    std::cin.ignore();
    std::getline(std::cin,name);

    if(pool.findbyName(name) == nullptr) {
        std::cout << "Movie not exists \n";
        return;
    }
    FileWriter fileWriter;
    pool.remove(name);
    fileWriter.deleteRecord(name);
}

void UserInterface::loadSavedFiles() {

    std::ifstream input("Database");
    std::string s,data;
    FileWriter fileWriter;
    while(getline(input,s)) {
        std::vector<std::string> args;
        if (s == "Movie") {
            args = fileWriter.getLines(4,input);
            pool.add(new Movie(args));
        }
        if (s == "Series") {
            args = fileWriter.getLines(6,input);
            pool.add(new Series(args));
        }

    }
}

void UserInterface::wait() {
    std::cout << "Press enter to continue ...";
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

void UserInterface::showInfoAboutMovie() {
    std::string name;
    std::cout << "Give a name\n";
    std::cin.ignore();
    getline(std::cin,name);
    auto info = pool.findbyName(name);
    if(info == nullptr) {
        std::cout << "Movie doesn't exists\n";
        return;
    }
    std::cout << *info << std::endl;
}

void UserInterface::proposeMovieForWatching() {
    pool.sort();
//    if(pool.getRecords().size() == 0) {
   //     std::cout << "There is no movies to watch\n";
 //       return;
  //  }
 //   std::cout << pool.getRecords()[0];
}
