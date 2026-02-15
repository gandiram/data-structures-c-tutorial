// structures.c

/*
 * This file contains the implementations of linked list operations in C.
 * The operations provided include creating a node, inserting a node, displaying the list,
 * freeing the linked list, and displaying union data.
 */

#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in a linked list
struct Node {
    int data;
    struct Node* next;
};

/**
 * Function to create a new node.
 *
 * @param value The value to be stored in the new node.
 * @return A pointer to the newly created node.
 */
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/**
 * Function to insert a node at the end of the linked list.
 *
 * @param head A pointer to the pointer of the head of the list.
 * @param newNode A pointer to the new node to be inserted.
 */
void insertNode(struct Node** head, struct Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

/**
 * Function to display the linked list.
 *
 * @param head A pointer to the head of the list.
 */
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/**
 * Function to free the linked list.
 *
 * @param head A pointer to the head of the list.
 */
void freeLinkedList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/**
 * Function to display union of two linked lists.
 *
 * @param head1 A pointer to the head of the first list.
 * @param head2 A pointer to the head of the second list.
 */
void displayUnionData(struct Node* head1, struct Node* head2) {
    struct Node* temp;
    printf("Union of the two lists: ");
    // You can implement logic for union of two lists here
}

