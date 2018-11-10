#include "../include/UserInterface.h"
#include "../include/FileWriter.h"
#include "../include/LiveStream.h"
#include "../include/MovieFacade.h"
#include "../include/InputValidator.h"
#include <iostream>
#include <fstream>
#include <map>

UserInterface::UserInterface() : end(0) {}

void UserInterface::showOptions() {
    std::cout << "\n1.Add film\n"
        << "2.Add series to following\n"
        << "3.Show all films\n"
        << "4.Remove series from following\n"
        << "5.Remove film\n"
        << "6.Propose something to watching\n"
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
    switch (action) {
        case 1: movieFacade -> addFilm(); break;
        case 2: addSeriesToFollowing(); break;
        case 3: movieFacade -> getAll(); break;
        case 4: movieFacade -> removeFollowing(); break;
        case 5: movieFacade -> removeMovie(); break;
        case 6: proposeMovieForWatching(); break;
        case 7: movieFacade -> update(); break;
        case 8: showStatistics(); break;
        case 9: showInfoAboutMovie();break;
        case 10: showAllFollowing(); break;
        case 11: showComingLiveStreams(); break;
        case 12: end = 1; break;
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
    pool.sort();
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
    pool.sort();
    if(pool.getRecords().empty()) {
        std::cout << "There is no movies to watch\n";
        return;
    }
    srand(time(NULL));
    auto movie = pool.getRecords()[rand() % pool.getRecords().size()];
    std::cout << "Our special AI program chase for you this film:\n" << *movie <<"\n";
}

void UserInterface::addSeriesToFollowing() {
    std::cout << "Give name of series:";
    std::string name;
    std::cin.ignore();
    getline(std::cin,name);
    auto series = pool.findByName(name);
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


