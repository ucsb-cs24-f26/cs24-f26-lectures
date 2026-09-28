#ifndef CUSTOMLIST_H
#define CUSTOMLIST_H

#include <string>
#include <iostream>

using namespace std;

/**
 * CustomList - a singly linked list ADT built from nodes and raw
 * pointers, the same plumbing that std::list hides from you.
 *
 * See demo.cpp for a side-by-side comparison with std::list.
 */
class CustomList {
public:
    // Constructor - initializes an empty list
    CustomList();

    // Destructor - frees every node
    ~CustomList() {
        clear();
        head = nullptr;
        tail = nullptr;
    }

    // Frees all nodes and resets the list to empty
    void clear();

    // Add an element to the end - O(1) with the tail pointer
    void push_back(const string& val);

    // Print all elements
    void print() const;

private:
    // Node is a private implementation detail - callers never see this
    struct Node {
        string value;
        Node* next;
        Node(const string& val, Node* nxt = nullptr) : value(val), next(nxt) {}
    };

    Node* head;  // first node
    Node* tail;  // last node - this is what makes push_back O(1)

    void clearHelper(Node* node);  // recursively deletes nodes
};

#endif
