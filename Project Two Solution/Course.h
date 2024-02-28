#pragma once
#include <string>
#include <vector>
class Course {
private:
public:
	std::string number;
	std::string name;
	std::vector<std::string> prereqs;
	Course();
	Course(std::string number, std::string name, std::vector<std::string> prereqs);
	void printCourse();
	void printPrereqs();
};

