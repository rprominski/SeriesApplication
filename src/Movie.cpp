//
// Created by rafal on 19/10/18.
//

#include <iostream>
#include "../include/Movie.h"

Movie::Movie(std::string name, std::string description,
        int rate, int durationInMinutes) : name(name), description(description),
         durationInMinutes(durationInMinutes) {
    setRate(rate);
}

Movie::Movie(std::vector<std::string> data): name(data[0]), description(data[1]),
                                              durationInMinutes(stoi(data[3])) {
    setRate(stoi(data[2]));
}

Movie::Movie() {}

const std::string &Movie::getName() const {
    return name;
}

void Movie::setName(const std::string &name) {
    Movie::name = name;
}

const std::string &Movie::getDescription() const {
    return description;
}

void Movie::setDescription(const std::string &description) {
    Movie::description = description;
}

int Movie::getRate() const {
    return rate;
}

int Movie::setRate(int rate) {
            Movie::rate = rate;
            if(rate < 0) {
                Movie::rate = 0;
            }
            if(rate > 10) {
        Movie::rate = 10;
    }
    return rate;
}

int Movie::getDurationInMinutes() const {
    return durationInMinutes;
}

void Movie::setDurationInMinutes(int durationInMinutes) {
    Movie::durationInMinutes = durationInMinutes;
}

bool Movie::operator==(const std::string &s) {
    return name == s;
}

std::string Movie::toString() {
    return name + "\n" + description + "\n" + std::to_string(rate) + "\n" + std::to_string(durationInMinutes);
}

std::ostream &operator<<(std::ostream &os, const Movie &movie) {
    movie.print(os);
    return os;
}

void Movie::print(std::ostream &os) const {
    os << "Name -> " << name << "\nDescription -> " << description << "\nRate -> " << rate
       << "\nDuration (in minutes) -> " << durationInMinutes <<"\n";
}

bool Movie::operator<(const Movie *m1) {
    return m1->getRate() < this -> getRate();
}

void Movie::update(int what, std::string value) {
    if(what == 1) {
       setName(value);
    }
    if(what == 2) {
        setDescription(value);
    }
    if(what == 3) {
       setRate(stoi(value));
    }
    if(what == 4) {
       setDurationInMinutes(stoi(value));
    }
}