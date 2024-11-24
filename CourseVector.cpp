#include "CourseVector.h"
#include <iostream>
#include "Utils.h"

void CourseVector::readFile(std::string path)
{
    std::vector<Course> newCourses;

    // Open file stream
    std::ifstream fileStream(path);
    if (!fileStream) std::cerr << "Could not open file!";

    // Parse each line from the file as a new course
    std::string line;
    while (getline(fileStream, line)) {
        Course course = Utils::readCourseLine(line);
        newCourses.push_back(course);
    }

    this->courses = newCourses;
}

void CourseVector::printAll() {
    for (Course course : courses) {
        course.printCourse();
    }
}

Course CourseVector::findCourse(std::string courseNumber)
{
    // Assume courses vector is unsorted. If vector was sorted when read from file
    // then this could be a faster operation. Leaving unsorted because this is used
    // to compare average runtimes per data structure.
    for (Course course : courses) {
        if (course.number == courseNumber) {
            return course;
        }
    }
}
