//
// Created by rafal on 05.11.18.
//

#include "../include/LiveStream.h"
#include <iomanip>
std::chrono::time_point<std::chrono::system_clock> LiveStream::getStartDate() const {
    return startDate;
}

void LiveStream::setStartDate(std::chrono::time_point<std::chrono::system_clock> startDate) {
    LiveStream::startDate = startDate;
}

LiveStream::LiveStream(const std::string &name, const std::string &description, int rate, int durationInMinutes,
                       std::string startDate) :
                       Movie(name, description, rate, durationInMinutes), startDate(stringToChrono(startDate)) {}

void LiveStream::print(std::ostream &os) const {
    Movie::print(os);
    //os << startDate <<"\n";
}

std::string LiveStream::toString() {
    return Movie::toString() + "\n" + stringDate;
}

LiveStream::LiveStream(std::vector<std::string> args) : Movie(args),startDate(stringToChrono(args[4])) {}

std::chrono::time_point<std::chrono::system_clock> LiveStream::stringToChrono(std::string date) {
    stringDate = date;
    std::tm tm = {};
    std::stringstream ss(date);
    ss >> std::get_time(&tm, "%d.%m.%Y %H:%M");
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

int LiveStream::timeToStart() {
    auto end = std::chrono::system_clock::now();
    auto hours = std::chrono::duration_cast<std::chrono::hours>(end - startDate);
    return hours.count();
}
