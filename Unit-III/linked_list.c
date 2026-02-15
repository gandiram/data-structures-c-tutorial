/*
 * linked_list.c
 * Implementation of a singly linked list in C.
 * This program includes functions for inserting, deleting,
 * searching, and traversing the linked list, with detailed comments.
 */

#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct Node {
    int data;        // Data stored in the node
    struct Node* next; // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If the list is empty, set new node as head
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next; // Traverse to the last node
    }
    temp->next = newNode; // Link the new node at the end
}

// Function to delete a node by value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head, *prev = NULL;
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        return;
    }
    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    // If key was not present in linked list
    if (temp == NULL) return;
    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to search for a value in the list
struct Node* search(struct Node* head, int key) {
    struct Node* current = head; // Initialize current
    while (current != NULL) {
        if (current->data == key) {
            return current; // Return node if key is found
        }
        current = current->next;
    }
    return NULL; // Return NULL if key is not found
}

// Function to traverse the list and print its elements
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data); // Print current node's data
        temp = temp->next; // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list
}

// Main function for demonstration
int main() {
    struct Node* head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    printf("Linked List after insertion: ");
    traverse(head);
    deleteNode(&head, 20);
    printf("Linked List after deletion of 20: ");
    traverse(head);
    struct Node* foundNode = search(head, 30);
    if (foundNode != NULL) {
        printf("Found: %d\n", foundNode->data);
    } else {
        printf("Value not found\n");
    }
    return 0;
}