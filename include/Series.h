//
// Created by rafal on 19/10/18.
//

#ifndef SERIESAPPLICATION_SERIES_H
#define SERIESAPPLICATION_SERIES_H

#include <vector>
#include <string>
#include "Movie.h"
#include "DayOfWeek.h"
#include <iostream>
class Series : public virtual Movie {
private:

    int numberOfEpisodes;
    std::vector<std::string> broadcastDays;
public:
    Series(const std::string &name, const std::string &description, int rate, int durationInMinutes,
           int numberOfEpisodes, const std::vector<std::string> &broadcastDays);

    Series(const std::string &name, const std::string &description, int rate, int durationInMinutes,
                   int numberOfEpisodes, const std::string &days);

    Series(std::vector<std::string> args);

    //using Movie::Movie;

    int getNumberOfEpisodes() const;

    void setNumberOfEpisodes(int numberOfEpisodes);

    const std::vector<std::string> &getBroadcastDays() const;

    void setBroadcastDays(const std::vector<std::string> &broadcastDays);

    std::vector<std::string> parseDays(std::string days);

    std::string toString();

    void print(std::ostream& os) const;

};


#endif //SERIESAPPLICATION_SERIES_H
