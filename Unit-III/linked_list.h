// linked_list.h

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// Structure definition for a singly linked list node
struct SinglyLinkedListNode {
    int data;
    struct SinglyLinkedListNode* next;
};

// Structure definition for a circular linked list node
struct CircularLinkedListNode {
    int data;
    struct CircularLinkedListNode* next;
};

// Structure definition for a doubly linked list node
struct DoublyLinkedListNode {
    int data;
    struct DoublyLinkedListNode* next;
    struct DoublyLinkedListNode* prev;
};

// Function prototypes for singly linked list operations
void insertSinglyLinkedList(struct SinglyLinkedListNode** head, int data);
void deleteSinglyLinkedList(struct SinglyLinkedListNode** head, int key);
void displaySinglyLinkedList(struct SinglyLinkedListNode* node);

// Function prototypes for circular linked list operations
void insertCircularLinkedList(struct CircularLinkedListNode** head, int data);
void deleteCircularLinkedList(struct CircularLinkedListNode** head, int key);
void displayCircularLinkedList(struct CircularLinkedListNode* head);

// Function prototypes for doubly linked list operations
void insertDoublyLinkedList(struct DoublyLinkedListNode** head, int data);
void deleteDoublyLinkedList(struct DoublyLinkedListNode** head, int key);
void displayDoublyLinkedList(struct DoublyLinkedListNode* node);

#endif // LINKED_LIST_H
