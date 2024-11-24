#pragma once
#include "Course.h"
#include "CourseStructure.h"
#include <vector>
#include <fstream>
class CourseVector: public CourseStructure
{
private:
	std::vector<Course> courses;
public:
    virtual void readFile(std::string path);
    virtual void printAll();
    virtual Course findCourse(std::string courseNumber);
};

