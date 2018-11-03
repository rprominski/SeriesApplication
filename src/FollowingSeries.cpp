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
