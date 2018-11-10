//
// Created by rafal on 09.11.18.
//

#include "../include/EventsReminder.h"
#include "../include/MovieFacade.h"
#include "../include/LiveStream.h"

void EventsReminder::remindeInNext24H() {
    for(auto i : *MovieFacade::getInstance().getAllMovies()) {
        bool first = true;
        if((typeid(*i) == typeid(LiveStream)) &&
            find(reminded.begin(),reminded.end(),i -> getName()) == reminded.end() &&
            timeToStart(dynamic_cast<LiveStream*>(i) ->getStartDate()) <= 24 &&
            timeToStart(dynamic_cast<LiveStream*>(i) ->getStartDate()) >= 0 ) {
                if(first) {
                    std::cout << "The are some events in next 24h:\n";
                    first = false;
                }
                std::cout << *i << "\n";
                reminded.push_back(i -> getName());
            }

    }
}

int EventsReminder::timeToStart(std::chrono::time_point<std::chrono::system_clock> startDate) {
    auto now = std::chrono::system_clock::now();
    auto hours = std::chrono::duration_cast<std::chrono::hours>(startDate - now);
    return hours.count();
}
