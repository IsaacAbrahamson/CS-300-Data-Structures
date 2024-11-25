# CS-300 Data Structures

## Overview

In this class, I built a simple command line application that interacts with course data using different data structures.

The three data structures that can be used are:

- Vector
- Map
- BinarySearchTree

Vector and Map use the built-in C++ functionality, but I made the BinarySearchTree data structure myself.

## Runtime analysis

### Vector

The vector code loops over every line in the file and adds it to the list as well as adding the prerequisites to a list. Adding an item to the end of a vector is O(1). The read file and add items is O(n) + 1 and the validate prerequisites is O(n^2).

### Hashmap

The map has the same runtime complexity as the vector because we are doing the same operation of looping over the file and then looping over the prerequisites while looping over the courses. So the entire read file operation will be n^2. The process of inserting an item into a hashmap is usually o(1) but in worse-case scenario it can take multiple tries to insert, but this does not qualify as o(n). So the read file and add items is O(n) + 1 and the validate prerequisites is O(n^2).

### Binary Search tree

The tree has the same runtime complexity as the vector and hashtable because we are doing the same operation of looping over the file and then looping over the prerequisites while looping over the courses. So the entire read file operation will be n^2. The process of inserting an item into a tree is worse than a vector or hashmap because we traverse the tree to add it which is O(n) inside the O(n). So the read file and add items is O(n^2) and the validate prerequisites is O(n^2) which is O(n^2)+O(n^2) or just O(n^2).

## Advantages and Disadvantages

Each of the three data structures have their own advantages and disadvantages. For vectors, the major advantages are that items can be read from the vector in constant time, items can be added to the end in constant time, and they are simple to implement. The major disadvantages for vectors are that it is slower to insert and delete elements in random access and searching a vector for element requires linear time. For maps, the major advantage is near constant time searching, insert, and delete. The disadvantages to maps are the difficulty to implement, collisions if a poor hash function is used, and getting items in order. Finally, the advantages for binary search trees are that they are ordered making sorting unnecessary; insert, search, and delete are in log n; and they are simple to implement. The disadvantage to binary search trees is that they have slightly worse memory performance due to additional pointers and constructs needed for the structure itself.

## Recomendation

Based on the analysis above as well as my own practice implementing these various structures throughout the course, I would recommend using a binary search tree for this project. I found that this data structure was more straightforward to create than a map, and it has more benefits than a vector. To recap the analysis above, binary search trees have very good performance (log n) for common operations such as searching, inserting, and deleting. Additionally, because binary search trees are ordered, there is no need to sort items later which was one of the requirements for the project.