//
// Created by rafal on 19/10/18.
//

#include "../include/FileWriter.h"
#include <fstream>

FileWriter::FileWriter(const std::string &path) : path(path) {}

//FileWriter::FileWriter() : path("") {}

const std::string &FileWriter::getPath() const {
    return path;
}

void FileWriter::setPath(const std::string &path) {
    FileWriter::path = path;
}

void FileWriter::write(std::string data) {
    std::ofstream output(path);
    output << data << std::endl;
}


