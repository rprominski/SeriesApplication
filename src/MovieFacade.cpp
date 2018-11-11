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
    try {
        auto t = dataCollector.movieUpdate();
        auto movie = pool.findByName(std::get<1>(t));
        if (movie == nullptr) {
            std::cout << "Record does not exist\n";
            return;
        }
        fileWriter.deleteRecord(movie->getName());
        movie->update(std::get<0>(t), std::get<2>(t));
        fileWriter.write(movie);
    }catch(std::string ex) {
        std::cout << ex <<"\n";
    }

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

std::vector<Movie*>* MovieFacade::getAllMovies() {
    return const_cast<std::vector<Movie *> *>(&pool.getRecords());
}

void MovieFacade::addFilm() {
    DataCollector dataCollector;
    try {
        auto record = dataCollector.newMovie();

        pool += (record);
        FileWriter fileWriter;
        fileWriter.write(record);
    }catch (std::string ex) {
        std::cout << ex << "\n";
    }
}

void MovieFacade::removeMovie() {
    try {
        std::string name = DataCollector::getName();

        if (pool.findByName(name) == nullptr) {
            throw std::string("Movie does not exist\n");
        }
        pool -= (name);
        FileWriter fileWriter;
        fileWriter.deleteRecord(name);
    } catch(std::string ex) {
        std::cout << ex << "\n";
    }
}

void MovieFacade::removeFollowing() {
    std::string name;
    name = InputValidator::iGetline("Give a name of movie you'd like to remove \n");
    try {
        if (pool.findByName(name) == nullptr) {
            std::cout << "Movie does not exist\n";
            return;
        }
        Series s = *dynamic_cast<Series *>(pool.findByName(name));
        auto *fs = new Series(s.getName(), s.getDescription(), s.getRate(),
                              s.getDurationInMinutes(), s.getNumberOfEpisodes(), s.getBroadcastDays());
        pool -= (name);
        pool += (fs);
        FileWriter fileWriter;
        fileWriter.deleteRecord(name);
        fileWriter.write(fs);
    } catch(std::string ex) {
        std::cout << ex << "\n";
    }
}

void MovieFacade::addSeriesToFollowing() {
    std::string name;

    name = InputValidator::getLine("Give name of series:\n");
    auto series = pool.findByName(name);

    if(series == nullptr) {
        std::cout <<("Bad name\n");
        return;
    }
    if(typeid(FollowingSeries) == typeid(*series)) {
        std::cout <<("Series is already following\n");
        return;
    }
    if(typeid(Series) != typeid(*series)) {
        std::cout <<("It is not a series\n");
        return;
    }

    FileWriter fileWriter;
    Series s = *dynamic_cast<Series*>(series);
    auto *fs = new FollowingSeries(s.getName(),s.getDescription(),s.getRate(),
                                   s.getDurationInMinutes(),s.getNumberOfEpisodes(),s.getBroadcastDays(),0);

    fileWriter.deleteRecord(name);
    fileWriter.write(fs);
    pool -= (name);
    pool += (fs);
}

void MovieFacade::sortByName() {
    pool.sortByName();
}

void MovieFacade::sortByRate() {
    pool.sortByRate();
}

Movie* MovieFacade::getByName(std::string name) {
    return pool.findByName(name);
}
