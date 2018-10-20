//
// Created by rafal on 19/10/18.
//
#include <string>
#ifndef SERIESAPPLICATION_FILEWRITER_H
#define SERIESAPPLICATION_FILEWRITER_H


class FileWriter {
private:

    std::string path;

public:

    FileWriter(const std::string &path);

    FileWriter();

    void write(std::string data);

    void deleteRecord(std::string recordName);

    const std::string &getPath() const;

    void setPath(const std::string &path);

};


#endif //SERIESAPPLICATION_FILEWRITER_H
