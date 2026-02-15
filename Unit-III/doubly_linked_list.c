/*
 * doubly_linked_list.c
 * 
 * This file contains the implementation of a Doubly Linked List in C.
 * It includes functions for insertion, deletion, and traversal of the list.
 */

#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Function to delete a node with a given value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;

    // If the list is empty
    if (temp == NULL) {
        return;
    }

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Change head
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    // Find the node to be deleted
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If the key was not found in the list
    if (temp == NULL) {
        return;
    }

    // Unlink the node from the list
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

// Function to traverse and print the list
void traverseList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function to demonstrate the linked list operations
int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    printf("Doubly Linked List after insertion: ");
    traverseList(head);

    deleteNode(&head, 20);
    printf("Doubly Linked List after deletion of 20: ");
    traverseList(head);

    return 0;
}