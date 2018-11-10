//
// Created by rafal on 09.11.18.
//

#include <fstream>
#include <tuple>
#include "../include/MovieFacade.h"
#include "../include/FileWriter.h"
#include "../include/FollowingSeries.h"
#include "../include/LiveStream.h"
#include "../include/InputValidator.h"
#include "../include/DataCollector.h"

MovieFacade& MovieFacade::getInstance()
{
    static MovieFacade instance;
    return instance;
}

void MovieFacade::update() {

    FileWriter fileWriter;
    DataCollector dataCollector;
    auto t = dataCollector.movieUpdate();
    auto movie = pool.findByName(std::get<1>(t));

    fileWriter.deleteRecord(movie -> getName());
    movie -> update(std::get<0>(t),std::get<2>(t));
    fileWriter.write(movie);
}

void MovieFacade::loadDatabase() {
    std::ifstream input("Database");
    std::string s,data;
    FileWriter fileWriter;

    while(getline(input,s)) {
        std::vector<std::string> args;
        if (s == "Movie") {
            args = fileWriter.getLines(4,input);
            pool+=(new Movie(args));
        }
        if (s == "Series") {
            args = fileWriter.getLines(6,input);
            pool+=(new Series(args));
        }
        if (s == "FollowingSeries")  {
            args = fileWriter.getLines(7,input);
            pool+=(new FollowingSeries(args));
        }
        if (s == "LiveStream")  {
            args = fileWriter.getLines(5,input);
            pool+=(new LiveStream(args));
        }
    }
}

void MovieFacade::getAll() {
    pool.sort();
    pool.showAll();
}

void MovieFacade::addFilm() {
    DataCollector dataCollector;
    auto record = dataCollector.newMovie();

    pool.add(record);
    FileWriter fileWriter;
    fileWriter.write(record);
}

void MovieFacade::removeMovie() {
    std::string name;
    name = InputValidator::iGetline("Give a name of movie you'd like to remove \n");

    if(pool.findByName(name) == nullptr) {
        std::cout << "Movie not exists \n";
        return;
    }
    pool.remove(name);
    FileWriter fileWriter;
    fileWriter.deleteRecord(name);
}

void MovieFacade::removeFollowing() {
    std::string name;
    name = InputValidator::iGetline("Give a name of movie you'd like to remove \n");

    if(pool.findByName(name) == nullptr) {
        std::cout << "Movie not exists \n";
        return;
    }
    Series s = *dynamic_cast<Series *>(pool.findByName(name));
    auto *fs = new Series(s.getName(),s.getDescription(),s.getRate(),
                          s.getDurationInMinutes(),s.getNumberOfEpisodes(),s.getBroadcastDays());
    pool.remove(name);
    pool.add(fs);
    FileWriter fileWriter;
    fileWriter.deleteRecord(name);
    fileWriter.write(fs);
}