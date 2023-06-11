#ifndef IHW3_CSVREADER_H
#define IHW3_CSVREADER_H

#include "common.h"

class CSVReader {
    std::string fileName;
    std::string delimiter;

    std::vector<std::string> split(std::string& s);

public:
    explicit CSVReader(std::string filename, std::string delm = ",") :
        fileName(std::move(filename)), delimiter(std::move(delm)) {
    };

    std::vector<std::vector<std::string>> getData();
};

#endif //IHW3_CSVREADER_H
