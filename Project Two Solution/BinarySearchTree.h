#pragma once
#include "Course.h"
#include <fstream>
struct Node {
    Course course;
    Node* left;
    Node* right;

    Node() {
        left = nullptr;
        right = nullptr;
    }

    Node(Course course) : Node() {
        this->course = course;
    }
};

/**
 * The structure for a binary search tree that has nodes of courses.
 */
class BinarySearchTree {
private:
    Node* root;

    void addNode(Node* node);
    void postOrder(Node* node);
    void preOrder(Node* node);
    void inOrder(Node* node);
    Node* removeNode(Node* node, std::string courseNumber);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void readFile(std::string path);
    void InOrder();
    void PostOrder();
    void PreOrder();
    void Insert(Course course);
    void Remove(std::string courseNumber);
    Course Search(std::string courseNumber);
};
