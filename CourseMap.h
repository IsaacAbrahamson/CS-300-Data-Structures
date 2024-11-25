#pragma once
#include <vector>
#include "CourseStructure.h"
#include "Course.h"
#include <unordered_map>
#include <fstream>
class CourseMap: public CourseStructure
{
private:
	std::unordered_map<std::string, Course> courseMap;
public:
	virtual void readFile(std::string path);
	virtual void printAll();
	virtual Course findCourse(std::string courseNumber);
};

