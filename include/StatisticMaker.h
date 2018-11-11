//
// Created by rafal on 11.11.18.
//

#ifndef SERIESAPPLICATION_STATISTICMAKER_H
#define SERIESAPPLICATION_STATISTICMAKER_H

#include <map>
#include <string>

class StatisticMaker {

    void showRemainingTimeOfFollowing();

    void showNumberOfFollowingSeriesPerDay();

    void showWeeklyTimeForFolling();

public:
    std::map<std::string,int> makeStatisticSeriesPerDay();

    void showAll();

};


#endif //SERIESAPPLICATION_STATISTICMAKER_H
