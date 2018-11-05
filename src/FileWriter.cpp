//
// Created by rafal on 19/10/18.
//

#include "../include/FileWriter.h"
#include "../include/FollowingSeries.h"
#include "../include/LiveStream.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>

FileWriter::FileWriter(const std::string &path) : path(path) {}

FileWriter::FileWriter() : path("Database") {}

const std::string &FileWriter::getPath() const {
    return path;
}

void FileWriter::setPath(const std::string &path) {
    FileWriter::path = path;
}

void FileWriter::write(Movie* data) {
    std::ofstream output(path,std::ios::app);
    if(typeid(*data) == typeid(FollowingSeries)) {
        output << "FollowingSeries\n";
    } else
    if(typeid(*data) == typeid(Series)) {
        output << "Series\n";
    } else
        if(typeid(*data) == typeid(LiveStream)) {
            output << "LiveStream\n";
        }
    if(typeid(*data) == typeid(Movie)) {
        output << "Movie\n";
    }

    output << data -> toString() << std::endl;
}

bool FileWriter::deleteRecord(std::string recordName) {
    std::ifstream input(path);
    std::ofstream copy("temp");
    std::string s;
    bool find = false;

    while(getline(input,s)) {
        std::vector <std::string> args;
        int argsNumber;
        std::string arg;
        if(s == "Movie") {
            argsNumber = 4;
        }
        if(s == "Series") {
            argsNumber = 6;
        }
        if(s == "FollowingSeries") {
            argsNumber = 7;
        }
        for(int i = 0; i < argsNumber; i++) {
            getline(input,arg);
            args.push_back(arg);
        }
        if(recordName != args[0]) {
            copy << s <<"\n";
            for(auto i : args) {
                copy << i << std::endl;
            }
            find = true;
        }
    }
    std::rename("temp",path.c_str());

    return find;
}

std::vector<std::string> FileWriter::getLines(int numberOfLines, std::ifstream &input) {
    std::vector<std::string> lines;
    std::string line;

    for(int i = 0; i < numberOfLines; i++) {
        getline(input,line);
        lines.push_back(line);
    }
    return lines;
}




