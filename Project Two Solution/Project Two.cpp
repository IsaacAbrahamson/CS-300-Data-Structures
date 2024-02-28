#include <iostream>
#include "BinarySearchTree.h"
#include <filesystem>

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

// Starting point of application
int main() {
    BinarySearchTree courseTree;

    // TODO: Handle invalid input
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
            } else {
                std::cout << "Invalid file" << std::endl;
            }
        } else if (choice == 2) {
            // Print all courses
            std::cout << std::endl;
            courseTree.InOrder();
        } else if (choice == 3) {
            // Print specific course
            std::cout << "Enter course number:" << std::endl;
            std::string number;
            std::cin >> number;

            Course course = courseTree.Search(number);
            std::cout << std::endl;
            course.printCourse();
            course.printPrereqs();
        } else if (choice == 4) {
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

    std::cout << "Goodbye." << std::endl;
    return 0;
}