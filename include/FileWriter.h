#ifndef SERIESAPPLICATION_FILEWRITER_H
#define SERIESAPPLICATION_FILEWRITER_H
#include <string>
#include <vector>
#include "Movie.h"
#include "Series.h"

class FileWriter {
private:
    std::string path;

public:
    FileWriter(const std::string &path);

    FileWriter();

    void write(Movie* data);

    bool deleteRecord(std::string recordName);

    const std::string &getPath() const;

    void setPath(const std::string &path);

    std::vector<std::string> getLines(int numberOfLines, std::ifstream& input);

};


#endif //SERIESAPPLICATION_FILEWRITER_H
