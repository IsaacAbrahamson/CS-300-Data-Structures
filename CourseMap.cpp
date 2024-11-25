#include "CourseMap.h"
#include "Course.h"
#include <iostream>
#include "Utils.h"

void CourseMap::readFile(std::string path) {
    // Open file stream
    std::ifstream fileStream(path);
    if (!fileStream) std::cerr << "Could not open file!";

    // Parse each line from the file as a new course
    std::string line;
    while (getline(fileStream, line)) {
        Course course = Utils::readCourseLine(line);
        courseMap.insert({course.number, course});
    }
}

void CourseMap::printAll() {
    for (auto [courseId, course] : courseMap) {
        course.printCourse();
    }
}

Course CourseMap::findCourse(std::string courseNumber) {
    if (courseMap.find(courseNumber) != courseMap.end()) {
        return courseMap[courseNumber];
    }
}
