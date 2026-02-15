/*
 * queue.c
 * Implementation of a simple queue data structure in C.
 * This implementation supports the following operations:
 * - Enqueue
 * - Dequeue
 * - Peek
 * - Check if the queue is empty
 * - Display the contents of the queue
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct Node {
    int data;
    struct Node* next;
};

// Define the structure for the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add an item to the queue
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = createNode(value);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to remove an item from the queue
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1; // or suitable error code
    }
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Function to get the front item of the queue
int peek(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1; // or suitable error code
    }
    return q->front->data;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Function to display the contents of the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue contents: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Example usage of the queue implementation
int main() {
    struct Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    printf("Dequeued: %d\n", dequeue(q));
    display(q);
    printf("Front item is: %d\n", peek(q));
    return 0;
}