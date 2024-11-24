#pragma once
#include <vector>
#include "Course.h"
class CourseHashtable
{
private:
	std::vector<Course*> courses;
	int tableSize = 200;
	Course* EMPTY_SINCE_START;
	Course* EMPTY_AFTER_REMOVAL;
	int hash(int key);
public:
	CourseHashtable(int size);
	void insert(Course course);
	void remove(Course course);
	Course findCourse(std::string courseNumber);
};

