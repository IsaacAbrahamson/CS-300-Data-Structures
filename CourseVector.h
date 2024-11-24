#pragma once
#include "Course.h"
#include <vector>
#include <fstream>
class CourseVector
{
public:
	static std::vector<Course> readFile(std::string path);
	static Course findCourse(std::vector<Course> courses, std::string courseNumber);
};

