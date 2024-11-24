#pragma once
#include <string>
#include "Course.h"
#include <vector>
class CourseStructure {
public:
    virtual ~CourseStructure() {}
    virtual void readFile(std::string path) = 0;
    virtual void printAll() = 0;
    virtual Course findCourse(std::string courseNumber) = 0;
};