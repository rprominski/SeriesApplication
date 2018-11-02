//
// Created by rafal on 19/10/18.
//

#ifndef SERIESAPPLICATION_MOVIE_H
#define SERIESAPPLICATION_MOVIE_H

#include <string>
#include <vector>

class Movie {
protected:
    std::string name;
    std::string description;
    int rate;
    int durationInMinutes;

public:
    Movie(const std::string &name, const std::string &description, int rate, int durationInMinutes);

    Movie();

    Movie(std::vector<std::string> &data);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    int getRate() const;

    void setRate(int rate);

    int getDurationInMinutes() const;

    void setDurationInMinutes(int durationInMinutes);

    bool operator==(const std::string& s);

    friend std::ostream& operator<<(std::ostream& os, const Movie& movie);

    bool operator<(const Movie& m1);

    virtual void print(std::ostream& os) const;

    virtual std::string toString();
};


#endif //SERIESAPPLICATION_MOVIE_H
