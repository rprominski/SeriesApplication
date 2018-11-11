//
// Created by rafal on 10.11.18.
//

#include <iostream>
#include <tuple>
#include "../include/DataCollector.h"
#include "../include/InputValidator.h"
#include "../include/Series.h"
#include "../include/LiveStream.h"

Movie *DataCollector::newMovie() {
    std::cout<< "Which type would you like to add?\n1.Movie\n2.Series\n3.Live stream\n";
    std::string title,description;
    int type,rate,duration;
    InputValidator iv;

    std::cin>>type;
    std::cout<<"Title: "; std::cin.ignore(); std::getline(std::cin,title);
    std::cout<<"Descripion: "; std::getline(std::cin,description);
    std::cout<<"Rate: "; rate = iv.cinInt();
    if(type == 1) {
        duration = iv.cinInt("Duration (in minutes): ");
        return new Movie(title,description,rate,duration);
        }

    if(type == 2) {
        int episodes;
        std::string days;

        duration = iv.cinInt("Episode duration (in minutes): ");
        episodes = iv.cinInt("Number of episodes: ");
        days = iv.getLine("Broadcast days, possible values :"
                          "\nmonday tuesday wednesday thursday friday saturday sunday\n");
        return new Series(title,description,rate,duration,episodes,days); {
        }
    }
    if(type == 3) {
        std::string date;
        date = iv.getLine("Give date in format:\nDD.MM.YYYY hh:mm\n");
        return new LiveStream(title,description,rate,duration,date);
        }

    throw std::string("Bad argument");
}

std::tuple<int, std::string, std::string> DataCollector::movieUpdate() {
    int type = 5;
    type = InputValidator::icinInt("1.Movie\n2.Series\n3.Following series\n");
    std::string name = InputValidator::getLine("Give a name\n");
    std::cout << "What do you want update?\n1.Nothing\n2.Descryption\n3.Rate\n4.Duartion\n";
    if(type == 2) {
        std::cout << "5.Number of episodes\n6.Broadcast days\n";
    }
    if(type == 3) {
        std::cout << "5.Number of episodes\n6.Broadcast days\n7.Number of watched episodes\n";
    }

    int what = InputValidator::cinInt();
    if(what == 1) {
        throw ("Nothing");
    }
    if((type == 1 && (what < 0 || what > 4)) ||
            (type == 2 && (what < 0 || what > 6)) ||
            (type == 3 && (what < 0 || what > 7)) ||
            (type < 0 || type > 4)) {
        throw std::string("Bad argument");
    }

    std::string stringValue;
    int intValue;
    std::cout <<"New value:\n";
    if(( (what >= 3) && (what <= 5) ) || what == 7) {
        intValue = InputValidator::cinInt();
        stringValue = std::to_string(intValue);
    } else {
        getline(std::cin,stringValue);
    }
    return std::make_tuple(what,name,stringValue);
}

std::string DataCollector::getName() {
    std::string name = InputValidator::iGetline("Give a name\n");
    return name;
}
