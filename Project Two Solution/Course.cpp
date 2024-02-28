#include "Course.h"
#include <iostream>

/* Default constructor */
Course::Course() {}

/* Constructor */
Course::Course(std::string number, std::string name, std::vector<std::string> prereqs) {
	this->number = number;
	this->name = name;
	this->prereqs = prereqs;
}

void Course::printCourse() {
	std::cout << number << " " << name << std::endl;
}

// Create string of all prereqs on one line
void Course::printPrereqs() {
	// Handle case where course has no prereqs
	if (prereqs.size() == 0) {
		std::cout << "    No prerequisites required." << std::endl;
		return;
	}

	std::string prereqsStr = "";
	for (int i = 0; i < prereqs.size(); i++) {
		if (prereqsStr == "") {
			prereqsStr += prereqs.at(i);
		} else {
			prereqsStr = prereqsStr + ", " + prereqs.at(i);
		}
	}
	std::cout << "    Prerequisites: " << prereqsStr << std::endl;
}