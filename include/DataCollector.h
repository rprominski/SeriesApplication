//
// Created by rafal on 10.11.18.
//

#ifndef SERIESAPPLICATION_DATACOLLECTOR_H
#define SERIESAPPLICATION_DATACOLLECTOR_H


#include "Movie.h"

class DataCollector {
public:
    static Movie* newMovie();

    static std::tuple<int,std::string,std::string> movieUpdate();

    static std::string getName();


};


#endif //SERIESAPPLICATION_DATACOLLECTOR_H
