//
// Created by rafal on 10.11.18.
//

#include "../include/MoviePrinter.h"
#include "../include/InputValidator.h"
#include "../include/MovieFacade.h"
#include "../include/FollowingSeries.h"
#include "../include/DataCollector.h"

void MoviePrinter::showAllMovies() {
    preSort();
    for(auto i : *MovieFacade::getInstance().getAllMovies()) {
        std::cout << *i <<"\n";
    }
}

void MoviePrinter::showAllFollowing() {
    preSort();
    for(auto i : *MovieFacade::getInstance().getAllMovies()) {
        if(typeid(*i) == typeid(FollowingSeries)) {
            std::cout << *i;
        }
    }
}

void MoviePrinter::showOne() {
    std::string name = DataCollector::getName();
    std::cout << *MovieFacade::getInstance().getByName(name) << "\n";

}

void MoviePrinter::preSort() {
    int type = InputValidator::cinInt("1.Sort by name\n2.Sort by rate\n");
    if(type == 2) {
        MovieFacade::getInstance().sortByRate();
    } else {
        MovieFacade::getInstance().sortByName();
    }
}
