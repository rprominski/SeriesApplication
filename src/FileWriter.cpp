//
// Created by rafal on 19/10/18.
//

#include "../include/FileWriter.h"
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

void FileWriter::write(Movie data) {
    std::ofstream output(path,std::ios::app);
    if(typeid(data) == typeid(Movie)) {
        output << "Movie\n";
    }
    output << data.toString() << std::endl;
}

bool FileWriter::deleteRecord(std::string recordName) {
    std::ifstream input(path);
    std::ofstream copy("temp");
    std::string s,name;
    bool find = false;

    while(getline(input,s)) {
        std::stringstream ss(s);
        ss >> name;
        if(name != recordName) {
            copy << s << std::endl;
            find = true;
        }
    }
    std::rename("temp",path.c_str());

    return find ? true : false;
}

std::vector<Movie> FileWriter::getAllRecords() {
    std::vector <Movie> records;
    std::ifstream input(path);
    std::string s,data;
    while(getline(input,s)) {
        std::vector <std::string> args;
        if(s == "Movie") {
            std::string arg;
            for(int i = 0; i < 4; i++) {
                getline(input,arg);
                args.push_back(arg);
            }
            records.push_back(Movie(args));
        }
    }
    return records;
}




