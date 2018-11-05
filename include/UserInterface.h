//
// Created by rafal on 25/10/18.
//

#ifndef SERIESAPPLICATION_USERINTERFACE_H
#define SERIESAPPLICATION_USERINTERFACE_H


#include "Movie.h"
#include "Pool.h"
#include "FollowingSeries.h"

class UserInterface {
    bool end;
    int action;
    Pool <Movie*> pool;
    void getAction();

    void performAction();

    void showOptions();

    void addFilm();

    void showAllMovies();

    void removeMovie();

    void loadSavedRecords();

    void wait();

    int cinInt();

    void showInfoAboutMovie();

    void proposeMovieForWatching();

    void update();

    void addSeriesToFollowing();

    void showAllFollowing();

    void showStatistics();

    void showComingLiveStreams();

    void estimateWeeklyTime();

    void removeFollowing();

public:
    void start();

    UserInterface();
};


#endif //SERIESAPPLICATION_USERINTERFACE_H
