#include <iostream>
#include "BinarySearchTree.h"
#include <filesystem>
#include "CourseVector.h"

/* Prints the start menu information. */
void printStartMenu() {
    std::cout << "=== CHOOSE DATA STRUCTURE ===" << std::endl;
    std::cout << "Please enter one of the following options:" << std::endl;
    std::cout << "1: Vector" << std::endl;
    std::cout << "2. Hashtable" << std::endl;
    std::cout << "3. Binary Search Tree" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "=== ==== ===" << std::endl;
    std::cout << std::endl;
}

/* Prints the menu information. */
void printMenu() {
    std::cout << "=== MENU ===" << std::endl;
    std::cout << "Please enter one of the following options:" << std::endl;
    std::cout << "1: Read file" << std::endl;
    std::cout << "2. Print all courses" << std::endl;
    std::cout << "3. Print course information" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "=== ==== ===" << std::endl;
    std::cout << std::endl;
}

/* Runs the application using vector. */
void startVector() {
    std::vector<Course> courses;

    int choice = 0;
    while (choice != 4) {
        printMenu();
        std::cin >> choice;

        if (choice == 1) {
            // Read file
            std::cout << "Enter file name:" << std::endl;
            std::string path;
            std::cin >> path;

            if (std::filesystem::exists(path)) {
                courses = CourseVector::readFile(path);
            }
            else {
                std::cout << "Invalid file" << std::endl;
            }
        }
        else if (choice == 2) {
            // Print all courses
            for (Course course : courses) {
                course.printCourse();
            }
        }
        else if (choice == 3) {
            // Print specific course
            std::cout << "Enter course number:" << std::endl;
            std::string number;
            std::cin >> number;

            Course course = CourseVector::findCourse(courses, number);

            std::cout << std::endl;
            course.printCourse();
            course.printPrereqs();
        }
        else if (choice == 4) {
            // Exit
            break;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid option" << std::endl;
        }

        std::cout << std::endl;
    }
}

/* Runs the application using binary search tree. */
void startBinarySearchTree() {
    BinarySearchTree courseTree;

    int choice = 0;
    while (choice != 4) {
        printMenu();
        std::cin >> choice;

        if (choice == 1) {
            // Read file
            std::cout << "Enter file name:" << std::endl;
            std::string path;
            std::cin >> path;

            if (std::filesystem::exists(path)) {
                courseTree.readFile(path);
            }
            else {
                std::cout << "Invalid file" << std::endl;
            }
        }
        else if (choice == 2) {
            // Print all courses
            std::cout << std::endl;
            courseTree.InOrder();
        }
        else if (choice == 3) {
            // Print specific course
            std::cout << "Enter course number:" << std::endl;
            std::string number;
            std::cin >> number;

            Course course = courseTree.Search(number);
            std::cout << std::endl;
            course.printCourse();
            course.printPrereqs();
        }
        else if (choice == 4) {
            // Exit
            break;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid option" << std::endl;
        }

        std::cout << std::endl;
    }
}

/* Determines which data structure is used for the application. */
void chooseDataStructure() {
    int choice = 0;
    while (choice != 4) {
        printStartMenu();
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "=============================" << std::endl;
            std::cout << "Chosen Data Structure: Vector" << std::endl;
            std::cout << "=============================" << std::endl;
            std::cout << std::endl;
            startVector();
        }
        else if (choice == 2) {
            std::cout << "================================" << std::endl;
            std::cout << "Chosen Data Structure: Hashtable" << std::endl;
            std::cout << "================================" << std::endl;
            std::cout << std::endl;
            startBinarySearchTree();
        }
        else if (choice == 3) {
            std::cout << "========================================" << std::endl;
            std::cout << "Chosen Data Structure: Binary Search Tree" << std::endl;
            std::cout << "========================================" << std::endl;
            std::cout << std::endl;
            startBinarySearchTree();
        }
        else if (choice == 4) {
            // Exit
            break;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid option" << std::endl;
        }

        std::cout << std::endl;
    }
}

// Starting point of application
int main() {
    chooseDataStructure();

    std::cout << "Goodbye." << std::endl;
    return 0;
}