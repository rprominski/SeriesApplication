//
// Created by rafal on 19/10/18.
//

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