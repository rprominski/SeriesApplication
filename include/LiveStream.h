#ifndef SERIESAPPLICATION_LIVESTREAMING_H
#define SERIESAPPLICATION_LIVESTREAMING_H

#include "Movie.h"
#include <chrono>

class LiveStream : public Movie{
    std::string stringDate;
    std::chrono::time_point<std::chrono::system_clock> startDate;
    std::chrono::time_point<std::chrono::system_clock> stringToChrono(std::string date);

public:

    std::chrono::time_point<std::chrono::system_clock> getStartDate() const;

    void setStartDate(std::chrono::time_point<std::chrono::system_clock> startDate);

    LiveStream(const std::string &name, const std::string &description, int rate, int durationInMinutes,
               std::string startDate);

    void print(std::ostream& os) const;

    void update(int what, std::string value);

    std::string toString();

    LiveStream(std::vector<std::string> vector);
};


#endif //SERIESAPPLICATION_LIVESTREAMING_H
