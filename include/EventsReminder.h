//
// Created by rafal on 09.11.18.
//

#ifndef SERIESAPPLICATION_EVENTSREMINDER_H
#define SERIESAPPLICATION_EVENTSREMINDER_H

#include <chrono>
#include <vector>
#include <string>

class EventsReminder {
    std::vector<std::string> reminded;

public:
    void remindeInNext24H();

    int timeToStart(std::chrono::time_point<std::chrono::system_clock> startDate);

};


#endif //SERIESAPPLICATION_EVENTSREMINDER_H
