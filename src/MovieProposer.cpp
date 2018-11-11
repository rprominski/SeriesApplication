//
// Created by rafal on 11.11.18.
//

#include "../include/MovieProposer.h"
#include "../include/MovieFacade.h"
#include "../include/StatisticMaker.h"

void MovieProposer::proposeSomethingToWatch() {
    srand(time(NULL));
    StatisticMaker sM;
    std::vector<std::string> days;
    for(auto i: sM.makeStatisticSeriesPerDay()) {
        if(i.second == 0) {
            days.push_back(i.first);
        }
    }
    Movie* movie = nullptr;
    for(auto i : *MovieFacade::getInstance().getAllMovies()) {
        if(typeid(*i) == typeid(Series)) {
            for(auto j : dynamic_cast<Series*>(i) -> getBroadcastDays()) {
                if(std::find(days.begin(),days.end(),j) == days.end()) {
                    std::cout <<"You don't watch anything in " << j <<"\nMaybe try this:\n" << *i;
                    return;
                }
            }
        }
        if(typeid(*i) == typeid(Movie)) {
            if(movie == nullptr) {
                movie = i;
            } else {
                if((i -> getRate() > movie -> getRate()) && (rand() % 3 == 0)) {
                    movie = i;
                }
            }
        }
    }
    if(movie != nullptr) {
        std::cout << "This movie have high rate. Interested?\n" << *movie <<"\n";
        return;
    }

    std::cout <<"Sorry, I didn't find anything interesting\n";
}
