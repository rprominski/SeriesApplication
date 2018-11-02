//
// Created by rafal on 19/10/18.
//

#include "../include/Series.h"
#include <numeric>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>

int Series::getNumberOfEpisodes() const {
    return numberOfEpisodes;
}

void Series::setNumberOfEpisodes(int numberOfEpisodes) {
    Series::numberOfEpisodes = numberOfEpisodes;
}

const std::vector<std::string> &Series::getBroadcastDays() const {
    return broadcastDays;
}

void Series::setBroadcastDays(const std::vector<std::string> &broadcastDays) {
    Series::broadcastDays = broadcastDays;
}

std::string Series::toString() {
    std::string days;
    for(auto i : broadcastDays) {
        days = days + i + " ";
    }
    return Movie::toString() + "\n" + std::to_string(numberOfEpisodes) + "\n" + days;
}

Series::Series(const std::string &name, const std::string &description, int rate, int durationInMinutes,
        int numberOfEpisodes, const std::vector<std::string> &broadcastDays) :
        Movie(name,description,rate,durationInMinutes),
        numberOfEpisodes(numberOfEpisodes),
        broadcastDays(broadcastDays){}

Series::Series(const std::string &name, const std::string &description, int rate, int durationInMinutes,
        int numberOfEpisodes, const std::string &days) :
        Movie(name,description,rate,durationInMinutes),
        numberOfEpisodes(numberOfEpisodes),
        broadcastDays(parseDays(days)){}

void Series::print(std::ostream &os) const {
    std::string days;
    for(auto i : broadcastDays) {
        std::cout << i <<"\n";
        days = days + i + " ";
    }
    os << "Name -> " << name << "\nDescription -> " << description << "\nRate -> " << rate
       << "\nDuration (in minutes) -> " << durationInMinutes <<"\nNumber of episodes -> "
       << numberOfEpisodes << "\nBroadcast days -> "
       << days <<"\n";
}

std::vector<std::string> Series::parseDays(std::string days) {
    std::transform(days.begin(), days.end(), days.begin(), ::tolower);
    std::istringstream iss(days);
    std::vector<std::string> names = {"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
    std::vector<std::string> words(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());
    std::vector<std::string> result;

    for(auto i : words) {
        if(std::find(names.begin(),names.end(),i) != names.end()) {
            result.push_back(i);
        }
    }
    return result;
}

Series::Series(std::vector<std::string> args) : Movie(args),
    numberOfEpisodes(stoi(args[4])), broadcastDays(parseDays(args[5])) {}
