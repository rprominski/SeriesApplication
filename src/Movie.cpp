//
// Created by rafal on 19/10/18.
//

#include <iostream>
#include "../include/Movie.h"

Movie::Movie(const std::string &name, const std::string &description,
        int rate, int durationInMinutes) : name(name), description(description),
        rate(rate), durationInMinutes(durationInMinutes) {}

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

void Movie::setRate(int rate) {
    Movie::rate = rate;
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

Movie::Movie() {

}

Movie::Movie(std::vector<std::string> &data): name(data[0]), description(data[1]),
                                              rate(stoi(data[2])), durationInMinutes(stoi(data[3])) {}

std::ostream &operator<<(std::ostream &os, const Movie &movie) {
    os << "Name -> " << movie.name << "\nDescription -> " << movie.description << "\nRate -> " << movie.rate
    << "\nDuration (in minutes) -> " << movie.durationInMinutes;
    return os;
}

