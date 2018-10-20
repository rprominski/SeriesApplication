//
// Created by rafal on 19/10/18.
//

#ifndef SERIESAPPLICATION_MOVIE_H
#define SERIESAPPLICATION_MOVIE_H


#include <string>

class Movie {
private:
    std::string name;
    std::string description;
    int rate;
    int durationInMinutes;

public:
    Movie(const std::string &name, const std::string &description, int rate, int durationInMinutes);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    int getRate() const;

    void setRate(int rate);

    int getDurationInMinutes() const;

    void setDurationInMinutes(int durationInMinutes);
};


#endif //SERIESAPPLICATION_MOVIE_H
