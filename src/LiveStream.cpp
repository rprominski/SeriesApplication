#include "../include/LiveStream.h"
#include <iomanip>
#include <iostream>

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
    os << "Name -> " << name << "\nDescription -> " << description << "\nRate -> " << rate
       << "\nDate: " << stringDate << "\n";
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

void LiveStream::update(int what, std::string value) {
    std::cout<<what<<" "<<value<<"\n";
    if(what < 5) {
        Movie::update(what,value);
    }
    if(what == 5) {
        setStartDate(stringToChrono(value));
        stringDate = value;
    }
}
