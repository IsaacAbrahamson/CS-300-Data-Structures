#include "BinarySearchTree.h"
#include <iostream>
#include "Utils.h"

/* Constructor */
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

/* Destructor */
BinarySearchTree::~BinarySearchTree() {
    // recurse from root deleting every node
    removeNode(root, root->course.number);
}

/** Removes a node. */
Node* BinarySearchTree::removeNode(Node* node, std::string courseNumber) {
    Node* parent = nullptr;
    Node* current = nullptr;
    while (current != nullptr) {
        if (current->course.number == courseNumber) { // Node found
            if (current->left == nullptr && current->right == nullptr) { // Remove leaf
                if (parent == nullptr) { // Node is root
                    root = nullptr;
                }
                else if (parent->left == current) {
                    parent->left = nullptr;
                }
                else {
                    parent->right = nullptr;
                }
            }
            else if (current->right == nullptr) { // Remove node with only left child
                if (parent == nullptr) { // Node is root
                    root = current->left;
                }
                else if (parent->left == current) {
                    parent->left = current->left;
                }
                else {
                    parent->right = current->left;
                }
            }
            else if (current->right == nullptr) { // Remove node with only right child
                if (parent == nullptr) { // Node is root
                    root = current->left;
                }
                else if (parent->left == current) {
                    parent->left = current->right;
                }
                else {
                    parent->right = current->right;
                }
            }
            return nullptr; // Node found and removed
        }
        else if (current->course.number < courseNumber) {
            // Search right
            parent = current;
            current = current->right;
        }
        else {
            // Search left
            parent = current;
            current = current->left;
        }
    }

    return nullptr; // No node found
}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
    inOrder(root);
}

/**
 * Traverse the tree in post-order
 */
void BinarySearchTree::PostOrder() {
    postOrder(root);
}

/**
 * Traverse the tree in pre-order
 */
void BinarySearchTree::PreOrder() {
    preOrder(root);
}

/**
 * Insert a course
 */
void BinarySearchTree::Insert(Course course) {
    // Create new node and insert it
    Node* newNode = new Node(course);
    addNode(newNode);
}

/**
 * Remove a course
 */
void BinarySearchTree::Remove(std::string courseNumber) {
    removeNode(root, courseNumber);
}

/**
 * Search for a course
 */
Course BinarySearchTree::Search(std::string courseNumber) {
    Node* current = root;

    while (current != nullptr) {
        if (current->course.number == courseNumber) {
            // course found so return it
            return current->course;
        }
        else if (courseNumber < current->course.number) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    Course course;
    return course;
}

/**
 * Add a bid to some node (recursive)
 */
void BinarySearchTree::addNode(Node* node) {
    if (root == nullptr) {
        root = node;
        node->left = nullptr;
        node->right = nullptr;
    }
    else {
        Node* current = root;
        while (current != nullptr) {
            if (node->course.number < current->course.number) {
                if (current->left == nullptr) {
                    current->left = node;
                    current = nullptr;
                }
                else {
                    current = current->left;
                }
            }
            else {
                if (current->right == nullptr) {
                    current->right = node;
                    current = nullptr;
                }
                else {
                    current = current->right;
                }
            }
        }
        node->left = nullptr;
        node->right = nullptr;
    }
}

void BinarySearchTree::inOrder(Node* node) {
    if (node != nullptr) {
        inOrder(node->left);
        node->course.printCourse();
        inOrder(node->right);
    }
}

void BinarySearchTree::postOrder(Node* node) {
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        node->course.printCourse();
    }
}

void BinarySearchTree::preOrder(Node* node) {
    if (node != nullptr) {
        node->course.printCourse();
        postOrder(node->left);
        postOrder(node->right);
    }
}

/* Reads a file into the data structure. */
void BinarySearchTree::readFile(std::string path) {
    // Open file stream
    std::ifstream fileStream(path);
    if (!fileStream) std::cerr << "Could not open file!";

    // Parse each line from the file as a new course
    std::string line;
    while (getline(fileStream, line)) {
        Course course = Utils::readCourseLine(line);
        Insert(course);
    }
}
