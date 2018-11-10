//
// Created by rafal on 25/10/18.
//

#ifndef SERIESAPPLICATION_USERINTERFACE_H
#define SERIESAPPLICATION_USERINTERFACE_H


#include "Movie.h"
#include "Pool.h"
#include "FollowingSeries.h"
#include "MovieFacade.h"

class UserInterface {
    bool end;
    int action;
    Pool <Movie*> pool;
    MovieFacade *movieFacade = &MovieFacade::getInstance();

    void getAction();

    void performAction();

    void showOptions();

    void wait();

    void showInfoAboutMovie();

    void proposeMovieForWatching();

    void update();

    void addSeriesToFollowing();

    void showAllFollowing();

    void showStatistics();

    void showComingLiveStreams();

    void estimateWeeklyTime();

public:
    void start();

    UserInterface();
};


#endif //SERIESAPPLICATION_USERINTERFACE_H
