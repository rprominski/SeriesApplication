//
// Created by rafal on 11.11.18.
//

#include "../include/StatisticMaker.h"
#include "../include/MovieFacade.h"
#include "../include/FollowingSeries.h"

void StatisticMaker::showRemainingTimeOfFollowing() {
    for(auto i : *MovieFacade::getInstance().getAllMovies()) {
        if(typeid(*i) == typeid(FollowingSeries)) {
            auto * fs = dynamic_cast<FollowingSeries*>(i);
            int time = fs->calculateTimeToEndOfSeries();
            std::cout << fs->getName() << "\nWatched    Episodes : " << fs->getNumberOfWatchedEpisodes() << "/"
                      << fs->getNumberOfEpisodes() << "\nRemaining time: " << time / 60 << "h " << time % 60
                      << "min\n\n";
        }
    }
}

void StatisticMaker::showNumberOfFollowingSeriesPerDay() {
    std::map<std::string, int> seriesPerDay = makeStatisticSeriesPerDay();

    for (auto i : *MovieFacade::getInstance().getAllMovies()) {
        if (typeid(*i) == typeid(FollowingSeries)) {
            auto *fs = dynamic_cast<FollowingSeries*>(i);
            for (auto j : fs->getBroadcastDays()) {
                seriesPerDay[j]++;
            }
        }
    }
    std::cout << "Number of following series in each day of week:"
            << "\nmonday: " << seriesPerDay["monday"] << "\ntuesday: " << seriesPerDay["tuesday"]
            << "\nwednesday: " << seriesPerDay["wednesday"] << "\nthursday: " << seriesPerDay["thursday"]
            << "\nfirday: " << seriesPerDay["friday"] << "\nsaturday: " << seriesPerDay["saturday"]
            << "\nsunday: " << seriesPerDay["sunday"] << "\n\n";
}

void StatisticMaker::showWeeklyTimeForFolling() {
    int time = 0;
    for(auto i : *MovieFacade::getInstance().getAllMovies()) {
        if(typeid(*i) == typeid(FollowingSeries)) {
            FollowingSeries* fs = dynamic_cast<FollowingSeries*>(i);
            time += (fs->getDurationInMinutes() * fs->getBroadcastDays().size());
        }
    }
    std::cout << "You need " << time/60 << "h " << time%60 <<"m per week to watch all your following series\n\n";
    std::cin.ignore();
}

std::map<std::string, int> StatisticMaker::makeStatisticSeriesPerDay() {
    std::map<std::string, int> seriesPerDay;

    for (auto i : *MovieFacade::getInstance().getAllMovies()) {
        if (typeid(*i) == typeid(FollowingSeries)) {
            auto *fs = dynamic_cast<FollowingSeries*>(i);
            for (auto j : fs->getBroadcastDays()) {
                seriesPerDay[j]++;
            }
        }
    }
    return seriesPerDay;
}

void StatisticMaker::showAll() {
    showRemainingTimeOfFollowing();
    showNumberOfFollowingSeriesPerDay();
    showWeeklyTimeForFolling();
}


