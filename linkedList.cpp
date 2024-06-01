#include "linkedList.h"

// Constructor
LinkedList::LinkedList() : head(nullptr) {}

// Destructor
LinkedList::~LinkedList() {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}

// Add a node to the list
void LinkedList::append(int data) {
    ListNode* newNode = new ListNode();
    newNode->data = data;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        ListNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Print the list
void LinkedList::printList(){
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

void LinkedList::shift() {
    if (head != nullptr)
        head = head->next;
    else
        std::cout << "\nNothing to remove" << std::endl;
}

void LinkedList::unshift(int data) {
    ListNode* newNode = new ListNode();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void LinkedList::length() {
    int count = 0;
    ListNode* current = head;
    while (current != nullptr) {
        current = current->next;
        count++;
    }
    std::cout << "Length of list is: " << count << std::endl;
}

void LinkedList::pop() {
    ListNode* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    current->next = nullptr;
}

void LinkedList::insert(int data, int index) {
    if (index == 0)
        LinkedList::unshift(data);
    else {
        ListNode* current = head;
        int count = 1;
        
        while (current->next->next != nullptr && count < index) {
            current = current->next;
            count++;
        }
        if (count == index) {
            ListNode* newNode = new ListNode();
            newNode->data = data;

            ListNode* pointer = current->next;
            current->next = newNode;
            current->next->next = pointer;
        }
        if (count < index) {
            LinkedList::append(data);
        }
    }
}

void LinkedList::splice(int index) {
    if (index == 0)
        LinkedList::shift();
    else {
        ListNode* current = head;
        int count = 1;

        while (current->next->next != nullptr && count < index) {
            current = current->next;
            count++;
        }
        if (count == index) {
            ListNode* pointer = current->next->next;
            current->next = pointer;
        }
        if (count < index) {
            LinkedList::pop();
        }
    }
}

void LinkedList::split(int index) {
    ListNode* current = head;
    int count = 1;

    while (current->next != nullptr && count < index) {
        current = current->next;
        count++;
    }
    if (count == index) {
        current->next = nullptr;
    }
}
