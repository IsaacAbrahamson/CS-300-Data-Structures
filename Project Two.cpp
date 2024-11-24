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

/* Runs the application using specified data structure. */
void startApplication(CourseStructure* structure) {
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
                structure->readFile(path);
            }
            else {
                std::cout << "Invalid file" << std::endl;
            }
        }
        else if (choice == 2) {
            // Print all courses
            structure->printAll();
        }
        else if (choice == 3) {
            // Print specific course
            std::cout << "Enter course number:" << std::endl;
            std::string number;
            std::cin >> number;

            Course course = structure->findCourse(number);

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
            CourseVector structure;
            startApplication(&structure);
        }
        else if (choice == 2) {
            std::cout << "================================" << std::endl;
            std::cout << "Chosen Data Structure: Hashtable" << std::endl;
            std::cout << "================================" << std::endl;
            std::cout << std::endl;
            // TODO: hashtable
            break;
        }
        else if (choice == 3) {
            std::cout << "========================================" << std::endl;
            std::cout << "Chosen Data Structure: Binary Search Tree" << std::endl;
            std::cout << "========================================" << std::endl;
            std::cout << std::endl;

            BinarySearchTree structure;
            startApplication(&structure);
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