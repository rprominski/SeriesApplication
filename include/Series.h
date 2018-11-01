//
// Created by rafal on 19/10/18.
//

#ifndef SERIESAPPLICATION_SERIES_H
#define SERIESAPPLICATION_SERIES_H

#include <vector>
#include <string>
#include "Movie.h"
#include "DayOfWeek.h"

class Series : public Movie {
private:

    int numberOfEpisodes;
    std::vector<std::string> broadcastDays;
public:
    Series(const std::string &name, const std::string &description, int rate, int durationInMinutes,
           const std::vector<std::string> &broadcastDays,int numberOfEpisodes);

    Series(const std::string &name, const std::string &description, int rate, int durationInMinutes,
           int numberOfEpisodes, const std::vector<std::string> &broadcastDays);

public:
    int getNumberOfEpisodes() const;

    void setNumberOfEpisodes(int numberOfEpisodes);

    const std::vector<std::string> &getBroadcastDays() const;

    void setBroadcastDays(const std::vector<std::string> &broadcastDays);

    std::string toString();

};


#endif //SERIESAPPLICATION_SERIES_H
