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
    int episodeDurationInMinutes;
    std::vector< DayOfWeek > broadcastDays;
public:
    Series(const std::string &name, const std::string &description, int rate, int durationInMinutes,
           int numberOfEpisodes, int episodeDurationInMinutes, const std::vector<DayOfWeek> &broadcastDays);

public:
    int getNumberOfEpisodes() const;

    void setNumberOfEpisodes(int numberOfEpisodes);

    int getEpisodeDurationInMinutes() const;

    void setEpisodeDurationInMinutes(int episodeDurationInMinutes);

    const std::vector<DayOfWeek> &getBroadcastDays() const;

    void setBroadcastDays(const std::vector<DayOfWeek> &broadcastDays);


};


#endif //SERIESAPPLICATION_SERIES_H
