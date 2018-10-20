//
// Created by rafal on 20/10/18.
//

#ifndef SERIESAPPLICATION_FOLLOWINGSERIES_H
#define SERIESAPPLICATION_FOLLOWINGSERIES_H

#include "Series.h"

class FollowingSeries : Series {
private:

    int numberOfWatchedEpisodes;

public:

    int CalculateTimeToEndOfSeries();

    int getNumberOfWatchedEpisodes() const;

    void setNumberOfWatchedEpisodes(int numberOfWatchedEpisodes);
};


#endif //SERIESAPPLICATION_FOLLOWINGSERIES_H
