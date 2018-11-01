//
// Created by rafal on 19/10/18.
//

#include "../include/Series.h"
#include <numeric>

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

Series::Series(const std::string &name, const std::string &description, int rate, int durationInMinutes,
                const std::vector<std::string> &broadcastDays,int numberOfEpisodes) :
                Movie(name, description, rate, durationInMinutes), numberOfEpisodes(numberOfEpisodes),
                broadcastDays(broadcastDays) {}

std::string Series::toString() {
    return Movie::toString() + " " + std::accumulate(broadcastDays.begin(), broadcastDays.end(), std::string("")) +
         " " + std::to_string(numberOfEpisodes);
}
