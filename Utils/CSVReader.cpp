#include "CSVReader.h"

std::vector<std::vector<std::string>> CSVReader::getData() {
    std::ifstream file(fileName);
    std::vector<std::vector<std::string>> dataList;
    std::string line;

    while (getline(file, line)) {
        std::vector<std::string> vec = split(line);
        dataList.push_back(vec);
    }

    file.close();
    return dataList;
}

std::vector<std::string> CSVReader::split(std::string& s) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
//        std::cout << token.c_str() << ' ' << token.length() << ' ';
    }
//    std::cout << std::endl;

    res.push_back(s.substr(pos_start));
    return res;
}