/*
 * circular_linked_list.c
 * Implementation of Circular Linked List in C
 * Supports insert, delete, traverse operations
 */

#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the circular linked list
struct Node {
    int data; // Data part of the node
    struct Node* next; // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode; // Pointing to itself
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode; // If list is empty, new node becomes head
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next; // Traverse to the end
        }
        temp->next = newNode; // Link last node to new node
    }
    newNode->next = *head; // Link new node back to head
}

// Function to delete a node from circular linked list
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) return;
    struct Node *temp = *head, *prev = NULL;

    // If head needs to be removed
    if (temp->data == value) {
        while (temp->next != *head) {
            temp = temp->next; // Find the last node
        }
        if (temp == *head) {
            free(*head); // List contains only one node
            *head = NULL;
            return;
        }
        temp->next = (*head)->next; // Link last node to second node
        struct Node* toDelete = *head;
        *head = (*head)->next; // Update head
        free(toDelete); // Free old head
        return;
    }

    // Traverse the list to find the node to be deleted
    while (temp->next != *head && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next->data == value) {
        struct Node* toDelete = temp->next;
        temp->next = toDelete->next; // Bypass the node to be deleted
        free(toDelete); // Free the deleted node
    }
}

// Function to traverse the circular linked list
void traverse(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n"); // Newline after traversal
}

// Main function to demonstrate operations
int main() {
    struct Node* head = NULL; // Initializing head of the list

    printf("Inserting values 10, 20, 30 into circular linked list:\n");
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    printf("List after insertion: ");
    traverse(head);

    printf("Deleting value 20 from circular linked list:\n");
    deleteNode(&head, 20);
    printf("List after deletion: ");
    traverse(head);

    return 0;
}
