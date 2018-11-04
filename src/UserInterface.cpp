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
        << "4.Exit\n"
        << "5.Show info about film\n"
        << "6.Propose Movie for watching\n"
        << "7.Update\n"
        << "9.Add series to following\n"
        << "10.Show all following series\n";
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

    if(action == 7) {
        update();
    }

    if(action == 8) {

    }

    if(action == 9) {
        addSeriesToFollowing();
    }

    if(action == 10) {
        showAllFollowing();
    }
}

void UserInterface::start() {
    loadSavedRecords();
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
    pool.showAll();
    std::cin.ignore();
}

void UserInterface::showAllFollowing() {
    followingSeries.sort();
    followingSeries.showAll();
    std::cin.ignore();
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

void UserInterface::loadSavedRecords() {

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
        if (s == "FollowingSeries")  {
            args = fileWriter.getLines(7,input);
            followingSeries.add(new FollowingSeries(args));
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
    if(pool.getRecords().empty()) {
        std::cout << "There is no movies to watch\n";
        return;
    }
    srand(time(NULL));
    auto movie = pool.getRecords()[rand() % pool.getRecords().size()];
    std::cout << "Our special AI program chase for you this film:\n" << *movie <<"\n";
}

void UserInterface::update() {
    std::cout << "What movie do you want to update?\n";
    std::string name;
    std::cin.ignore();
    getline(std::cin,name);
    auto movie = pool.findbyName(name);

    if(movie == nullptr ) {
        std::cout << "Movie doesn't exists\n";
        return;
    }
    std::cout << "What do you want update?\n"
                 "1.Name\n"
                 "2.Descryption\n"
                 "3.Rate\n"
                 "4.Duartion\n";
    if(typeid(*movie) == typeid(Series)) {
        std::cout << "5.Number of episodes\n"
                     "6.Broadcast days\n"
                     "7.Number of watched episodes";
    }

    int what = cinInt();
    if(typeid(*movie) == typeid(Movie) && (what < 0 || what > 4)) {
        return;
    }
    if(typeid(*movie) == typeid(Series)) {
        if(what == 7) {
            if(followingSeries.findbyName(movie->getName()) == nullptr) {
                std::cout << "You must follow series to change number of watched episodes\n";
                return;
            } else {
                movie = followingSeries.findbyName(movie->getName());
            }
        }
        if (what < 0 || what > 7) {
            return;
        }
    }
    std::string stringValue;
    int intValue;
    std::cout <<"New value:\n";
    if(( (what >= 3) && (what <= 5) ) || what == 7) {
        intValue = cinInt();
        stringValue = std::to_string(intValue);
    } else {
        getline(std::cin,stringValue);
    }
    FileWriter fileWriter;
    fileWriter.deleteRecord(movie -> getName());
    movie -> update(what,stringValue);
    fileWriter.write(movie);
}

void UserInterface::addSeriesToFollowing() {
    std::cout << "Give name of series:";
    std::string name;
    std::cin.ignore();
    getline(std::cin,name);
    auto series = pool.findbyName(name);
    if(series == nullptr) {
        std::cout << "Series not exists\n";
        return;
    }
    if(typeid(FollowingSeries) == typeid(*series)) {
        std::cout << "Series is already following\n";
        return;
    }
    if(typeid(Series) != typeid(*series)) {
        std::cout << "It is not a series\n";
        return;
    }

    FileWriter fileWriter;
    Series s = *dynamic_cast<Series*>((series));;
    auto *fs = new FollowingSeries(s.getName(),s.getDescription(),s.getRate(),
            s.getDurationInMinutes(),s.getNumberOfEpisodes(),s.getBroadcastDays(),0);

   // std::cout << *fs;
   fileWriter.write(fs);
   followingSeries.add(fs);
}
