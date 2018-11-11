//
// Created by rafal on 25/10/18.
//

#ifndef SERIESAPPLICATION_USERINTERFACE_H
#define SERIESAPPLICATION_USERINTERFACE_H


#include "Movie.h"
#include "Pool.h"
#include "FollowingSeries.h"
#include "MovieFacade.h"
#include "EventsReminder.h"
#include "StatisticMaker.h"
#include "MovieProposer.h"

class UserInterface {
    bool end;
    int action;
    Pool <Movie*> pool;
    MovieFacade *movieFacade = &MovieFacade::getInstance();
    EventsReminder eventsReminder;
    StatisticMaker statisticMaker;
    MovieProposer movieProposer;

    void getAction();

    void performAction();

    void showOptions();

    void wait();

public:
    void start();

    UserInterface();
};


#endif //SERIESAPPLICATION_USERINTERFACE_H
