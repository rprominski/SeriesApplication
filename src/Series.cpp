//
// Created by rafal on 19/10/18.
//

#include "../include/Series.h"

int Series::getNumberOfEpisodes() const {
    return numberOfEpisodes;
}

void Series::setNumberOfEpisodes(int numberOfEpisodes) {
    Series::numberOfEpisodes = numberOfEpisodes;
}

int Series::getEpisodeDurationInMinutes() const {
    return episodeDurationInMinutes;
}

void Series::setEpisodeDurationInMinutes(int episodeDurationInMinutes) {
    Series::episodeDurationInMinutes = episodeDurationInMinutes;
}

const std::vector<DayOfWeek> &Series::getBroadcastDays() const {
    return broadcastDays;
}

void Series::setBroadcastDays(const std::vector<DayOfWeek> &broadcastDays) {
    Series::broadcastDays = broadcastDays;
}

Series::Series(const std::string &name, const std::string &description, int rate, int durationInMinutes,
               int numberOfEpisodes, int episodeDurationInMinutes, const std::vector<DayOfWeek> &broadcastDays) : Movie(
        name, description, rate, durationInMinutes), numberOfEpisodes(numberOfEpisodes), episodeDurationInMinutes(
        episodeDurationInMinutes), broadcastDays(broadcastDays) {}
