#ifndef SERIESAPPLICATION_FOLLOWINGSERIES_H
#define SERIESAPPLICATION_FOLLOWINGSERIES_H

#include "Series.h"

class FollowingSeries : public  Series {
private:

    int numberOfWatchedEpisodes;

public:

    int calculateTimeToEndOfSeries();

    int getNumberOfWatchedEpisodes() const;

    void setNumberOfWatchedEpisodes(int numberOfWatchedEpisodes);

    FollowingSeries(const std::string &name, const std::string &description, int rate,
                    int durationInMinutes, int numberOfEpisodes,
                    const std::vector<std::string> &broadcastDays, int numberOfWatchedEpisodes);

    void print(std::ostream& os) const;

    std::string toString();

    FollowingSeries(std::vector<std::string> args);

    void update(int what, std::string value);
};


#endif //SERIESAPPLICATION_FOLLOWINGSERIES_H
