//
// Created by rafal on 09.11.18.
//

#ifndef SERIESAPPLICATION_MOVIEMANAGER_H
#define SERIESAPPLICATION_MOVIEMANAGER_H


#include "Movie.h"
#include "Pool.h"
#include "FileWriter.h"

class MovieFacade {
    MovieFacade() {}

    Pool<Movie*> pool;

public:
    static MovieFacade& getInstance();

    MovieFacade(MovieFacade const&) = delete;

    void operator=(MovieFacade const&) = delete;

    void update();

    void loadDatabase();

    void addFilm();

    void removeMovie();

    void removeFollowing();

    void getAll();
};


#endif //SERIESAPPLICATION_MOVIEMANAGER_H
