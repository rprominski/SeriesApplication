#ifndef SERIESAPPLICATION_SERIES_H
#define SERIESAPPLICATION_SERIES_H

#include <vector>
#include <string>
#include "Movie.h"
#include <iostream>

class Series : public virtual Movie {
protected:
    int numberOfEpisodes;
    std::vector<std::string> broadcastDays;

public:
    Series(const std::string &name, const std::string &description, int rate, int durationInMinutes,
           int numberOfEpisodes, const std::vector<std::string> &broadcastDays);

    Series(const std::string &name, const std::string &description, int rate, int durationInMinutes,
                   int numberOfEpisodes, const std::string &days);

    Series(std::vector<std::string> args);

    Series();

    int getNumberOfEpisodes() const;

    void setNumberOfEpisodes(int numberOfEpisodes);

    const std::vector<std::string> &getBroadcastDays() const;

    void setBroadcastDays(const std::vector<std::string> &broadcastDays);

    std::vector<std::string> parseDays(std::string days);

    virtual std::string toString();

    void print(std::ostream& os) const;

    void update(int what, std::string value);
};


#endif //SERIESAPPLICATION_SERIES_H
