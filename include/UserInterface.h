//
// Created by rafal on 25/10/18.
//

#ifndef SERIESAPPLICATION_USERINTERFACE_H
#define SERIESAPPLICATION_USERINTERFACE_H


#include "Movie.h"
#include "Pool.h"

class UserInterface {
    bool end;
    int action;
    Pool <Movie> pool;

    void getAction();

    void performAction();

    void showOptions();

    void exit();

    void addFilm();

    void showAllFilms();
public:
    void start();

    UserInterface();
};


#endif //SERIESAPPLICATION_USERINTERFACE_H