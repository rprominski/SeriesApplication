#include "../include/UserInterface.h"
#include "../include/FileWriter.h"
#include "../include/LiveStream.h"
#include <iostream>
#include <fstream>

UserInterface::UserInterface() : end(0) {}

void UserInterface::showOptions() {
    std::cout << "\n1.Add film\n"
        << "2.Add series to following\n"
        << "3.Show all films\n"
        << "4.Remove series from following\n"
        << "5.Remove film\n"
        << "6.Propose Movie for watching\n"
        << "7.Update\n"
        << "8.Print statistics of following series\n"
        << "9.Show info about film\n"
        << "10.Show all following series\n"
        << "11.Show coming live streams\n"
        << "12.Exit\n";
}

void UserInterface::getAction() {
    std::cin>>action;
}

void UserInterface::performAction() {
    if(action == 1) {
        addFilm();
    }

    if(action == 2) {
        addSeriesToFollowing();
    }

    if(action == 3) {
        showAllMovies();
    }

    if(action == 4) {
        removeFollowing();
    }

    if(action == 5) {
        removeMovie();
    }

    if(action == 6) {
        proposeMovieForWatching();
    }

    if(action == 7) {
        update();
    }

    if(action == 8) {
        showStatistics();
    }

    if(action == 9) {
        showInfoAboutMovie();
    }

    if(action == 10) {
        showAllFollowing();
    }

    if(action == 11) {
        showComingLiveStreams();
    }

    if(action == 12) {
        end = 1;
    }
}

void UserInterface::start() {
    loadSavedRecords();
    while(!end) {
        showOptions();
        getAction();
        performAction();
        wait();
    }
}

void UserInterface::addFilm() {
    std::cout<< "Which type would you like to add?\n"
        << "1.Movie\n"
        << "2.Series\n"
        << "3.Live stream\n";

    std::string title,description;
    int type,rate,duration;

    std::cin>>type;
    std::cout<<"Title: "; std::cin.ignore(); std::getline(std::cin,title);
    std::cout<<"Descripion: "; std::getline(std::cin,description);
    std::cout<<"Rate: "; rate = cinInt();
    if(type == 1) {
        std::cout<<"Duration (in minutes): "; duration = cinInt();

        if(pool+=(new Movie(title,description,rate,duration))) {
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
        if(pool+=(new Series(title,description,rate,duration,episodes,days))) {
            FileWriter fileWriter;
            fileWriter.write(new Series(title,description,rate,duration,episodes,days));
        }
    }
    if(type == 3) {
        std::cout << "Give date in format:\nDD.MM.YYYY hh:mm\n";
        std::string date;
        getline(std::cin,date);

        if(pool+=(new LiveStream(title,description,rate,duration,date))) {
            FileWriter fileWriter;
            fileWriter.write(new LiveStream(title,description,rate,duration,date));
        }
    }
}

void UserInterface::showAllMovies() {
    pool.sort();
    pool.showAll();
    std::cin.ignore();
}

void UserInterface::showAllFollowing() {
    pool.sort();
    for(auto i : pool.getRecords()) {
        if(typeid(*i) == typeid(FollowingSeries)) {
            std::cout <<*i <<"\n";
        }
    }
    std::cin.ignore();
}

void UserInterface::removeMovie() {
    std::string name;
    std::cout << "Give a name of movie you'd like to remove \n";
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
            pool+=(new Movie(args));
        }
        if (s == "Series") {
            args = fileWriter.getLines(6,input);
            pool+=(new Series(args));
        }
        if (s == "FollowingSeries")  {
            args = fileWriter.getLines(7,input);
            pool+=(new FollowingSeries(args));
        }
        if (s == "LiveStream")  {
            args = fileWriter.getLines(5,input);
            pool+=(new LiveStream(args));
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
                     "6.Broadcast days\n";

    }
    if(typeid(*movie) == typeid(FollowingSeries)) {
        std::cout << "5.Number of episodes\n"
                     "6.Broadcast days\n"
                     "7.Number of watched episodes\n";
    }

    int what = cinInt();
    if(typeid(*movie) == typeid(Movie) && (what < 0 || what > 4)) {
        return;
    }
    if((typeid(*movie) == typeid(Series)) && (what < 0 || what > 6)) {
        return;
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
    Series s = *dynamic_cast<Series*>(series);
    auto *fs = new FollowingSeries(s.getName(),s.getDescription(),s.getRate(),
            s.getDurationInMinutes(),s.getNumberOfEpisodes(),s.getBroadcastDays(),0);

    fileWriter.deleteRecord(name);
    fileWriter.write(fs);
    pool.remove(name);
    pool += (fs);
}

void UserInterface::showStatistics() {
    for(auto i : pool.getRecords()) {
        if(typeid(*i) == typeid(FollowingSeries)) {
            auto * fs = dynamic_cast<FollowingSeries*>(i);
            int time = fs->calculateTimeToEndOfSeries();
            std::cout << fs->getName() << "\nWatched    Episodes : " << fs->getNumberOfWatchedEpisodes() << "/"
                      << fs->getNumberOfEpisodes() << "\nRemaining time: " << time / 60 << "h " << time % 60
                      << "min\n\n";
        }
    }
    estimateWeeklyTime();
}

void UserInterface::showComingLiveStreams() {
    std::cout << "Live streams in next 24h:\n";
    for(auto i : pool.getRecords()) {
        if(typeid(*i) == typeid(LiveStream)) {
            LiveStream *ls = dynamic_cast<LiveStream*>(i);
            if(ls -> timeToStart() <= 24) {
                std::cout << *ls <<"\n";
            }
        }
    }
    std::cin.ignore();
}

void UserInterface::estimateWeeklyTime() {
    int time = 0;
    for(auto i : pool.getRecords()) {
        if(typeid(*i) == typeid(FollowingSeries)) {
            FollowingSeries* fs = dynamic_cast<FollowingSeries*>(i);
            time += (fs->getDurationInMinutes() * fs->getBroadcastDays().size());
        }
    }
    std::cout << "You need " << time/60 << "h " << time%60 <<"m per week to watch all your following series\n";
    std::cin.ignore();
}

void UserInterface::removeFollowing() {
    std::string name;
    std::cout << "Give a name of movie you'd like to remove \n";
    std::cin.ignore();
    std::getline(std::cin,name);

    if(pool.findbyName(name) == nullptr) {
        std::cout << "Movie not exists \n";
        return;
    }
    Series s = *dynamic_cast<Series *>(pool.findbyName(name));
    auto *fs = new Series(s.getName(),s.getDescription(),s.getRate(),
                                   s.getDurationInMinutes(),s.getNumberOfEpisodes(),s.getBroadcastDays());
    FileWriter fileWriter;
    pool.remove(name);
    pool.add(fs);
    fileWriter.deleteRecord(name);
    fileWriter.write(fs);
}

