#include "../include/UserInterface.h"
#include "../include/FileWriter.h"
#include "../include/LiveStream.h"
#include "../include/MovieFacade.h"
#include "../include/InputValidator.h"
#include "../include/MoviePrinter.h"
#include <iostream>
#include <fstream>
#include <map>

UserInterface::UserInterface() : end(0) {}

void UserInterface::showOptions() {
    eventsReminder.remindeInNext24H();
    std::cout << "\n1.Add film\n"
        << "2.Add series to following\n"
        << "3.Show all films\n"
        << "4.Remove series from following\n"
        << "5.Remove film\n"
        << "6.Update\n"
        << "7.Propose something to watching\n"
        << "8.Print statistics of following series\n"
        << "9.Show info about film\n"
        << "10.Show all following series\n"
        << "11.Exit\n";
}

void UserInterface::getAction() {
    std::cin>>action;
}

void UserInterface::performAction() {
    switch (action) {
        case 1: movieFacade -> addFilm(); break;
        case 2: movieFacade -> addSeriesToFollowing(); break;
        case 3: MoviePrinter::showAllMovies(); break;
        case 4: movieFacade -> removeFollowing(); break;
        case 5: movieFacade -> removeMovie(); break;
        case 6: movieFacade -> update(); break;
        case 7: proposeMovieForWatching(); break;
        case 8: showStatistics(); break;
        case 9: MoviePrinter::showOne();break;
        case 10: MoviePrinter::showAllFollowing(); break;
        case 11: end = true; break;
        default: break;
    }
}

void UserInterface::start() {
    movieFacade ->loadDatabase();
    while(!end) {
        showOptions();
        getAction();
        performAction();
        wait();
    }
}

void UserInterface::showAllFollowing() {
    pool.sortByRate();
    for(auto i : pool.getRecords()) {
        if(typeid(*i) == typeid(FollowingSeries)) {
            std::cout <<*i <<"\n";
        }
    }
    std::cin.ignore();
}

void UserInterface::wait() {
    std::cout << "Press enter to continue ...";
    std::cin.get();
}

void UserInterface::showInfoAboutMovie() {
    std::string name;
    std::cout << "Give a name\n";
    std::cin.ignore();
    getline(std::cin,name);
    auto info = pool.findByName(name);

    if(info == nullptr) {
        std::cout << "Movie doesn't exists\n";
        return;
    }
    std::cout << *info << std::endl;
}

void UserInterface::proposeMovieForWatching() {
    pool.sortByRate();
    if(pool.getRecords().empty()) {
        std::cout << "There is no movies to watch\n";
        return;
    }
    srand(time(NULL));
    auto movie = pool.getRecords()[rand() % pool.getRecords().size()];
    std::cout << "Our special AI program chase for you this film:\n" << *movie <<"\n";
}

void UserInterface::showStatistics() {
    std::map <std::string,int> seriesPerDay;
    for(auto i : pool.getRecords()) {
        if(typeid(*i) == typeid(FollowingSeries)) {
            auto * fs = dynamic_cast<FollowingSeries*>(i);
            int time = fs->calculateTimeToEndOfSeries();
            std::cout << fs->getName() << "\nWatched    Episodes : " << fs->getNumberOfWatchedEpisodes() << "/"
                      << fs->getNumberOfEpisodes() << "\nRemaining time: " << time / 60 << "h " << time % 60
                      << "min\n\n";
            for(auto j : fs->getBroadcastDays()) {
                seriesPerDay[j]++;
            }
        }
    }
    estimateWeeklyTime();
    std::cout << "\nNumber of following series in each day of week:\n";
    for(auto i : seriesPerDay ) {
        std::cout << i.first <<" " <<i.second <<"\n";
    }
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


