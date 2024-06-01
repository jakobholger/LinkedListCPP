#pragma once

#include <iostream>

// Define the ListNode structure
struct ListNode {
    int data;
    ListNode* next = nullptr;
};

// Define the LinkedList structure
class LinkedList {
private:
    ListNode* head;

public:
    LinkedList();             // Constructor
    ~LinkedList();            // Destructor
    void append(int data);   // Add a node to the list
    void pop();            // Remove last element in the list
    void printList();   // Print the list
    void shift(); // Remove first node
    void unshift(int data); // Add node as first node
    void length();          // Print the length of the list
    void insert(int data, int index);  // Insert a node at a specific index
    void splice(int index);     // Remove a node at a specific index
    void split(int index);      // Remove all nodes after a specific index
};