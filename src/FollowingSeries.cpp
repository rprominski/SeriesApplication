//
// Created by rafal on 20/10/18.
//

#include "../include/FollowingSeries.h"

int FollowingSeries::getNumberOfWatchedEpisodes() const {
    return numberOfWatchedEpisodes;
}

void FollowingSeries::setNumberOfWatchedEpisodes(int numberOfWatchedEpisodes) {
    FollowingSeries::numberOfWatchedEpisodes = numberOfWatchedEpisodes;
}

int FollowingSeries::CalculateTimeToEndOfSeries() {
    return (getNumberOfEpisodes() - numberOfWatchedEpisodes) * durationInMinutes;
}

FollowingSeries::FollowingSeries(const std::string &name, const std::string &description, int rate,
        int durationInMinutes, int numberOfEpisodes, const std::vector<std::string> &broadcastDays,
        int numberOfWatchedEpisodes) : Series(name, description, rate, durationInMinutes,
                numberOfEpisodes, broadcastDays), numberOfWatchedEpisodes(numberOfWatchedEpisodes) {
    setName(name);
    setDescription(description);
    setRate(rate);
    setDurationInMinutes(durationInMinutes);
}

void FollowingSeries::print(std::ostream &os) const {
    std::string days;
    for(auto i : broadcastDays) {
        days = days + i + " ";
    }
    os << "Name -> " << name << "\nDescription -> " << description << "\nRate -> " << rate
       << "\nDuration (in minutes) -> " << durationInMinutes <<"\nNumber of episodes -> "
       << numberOfEpisodes <<"\nWatched episodes " << numberOfWatchedEpisodes << "\nBroadcast days -> "
       << days <<"\n";

}

std::string FollowingSeries::toString() {
    return Series::toString() + "\n" + std::to_string(numberOfWatchedEpisodes);
}

FollowingSeries::FollowingSeries(std::vector<std::string> args) : Series(args), numberOfWatchedEpisodes(stoi(args[6])){
    setName(args[0]);
    setDescription(args[1]);
    setRate(stoi(args[2]));
    setDurationInMinutes(stoi(args[3]));
}

void FollowingSeries::update(int what, std::string value) {
    if(what < 7) {
        Series::update(what,value);
    }
    if(what == 7) {
        setNumberOfWatchedEpisodes(stoi(value));
    }
}
