#include "Utils.h"

Course Utils::readCourseLine(std::string line)
{
    // Split line on comma
    // See https://stackoverflow.com/a/44495206
    std::string delimiter = ",";
    std::vector<std::string> split;
    std::string str = std::string(line);
    size_t pos = 0;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        split.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    split.push_back(str);

    // First split is course number, second split is course name, and
    // remaining splits are prereq numbers
    std::string number = split.at(0);
    std::string name = split.at(1);
    std::vector<std::string> prereqs(split.begin() + 2, split.end());

    Course course(number, name, prereqs);
    return course;
}
