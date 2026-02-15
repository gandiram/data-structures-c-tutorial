#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

// Structure definition for a Queue
typedef struct {
    int *items;
    int front;
    int rear;
    int maxSize;
} Queue;

// Function prototypes for queue operations
Queue* createQueue(int maxSize);
void destroyQueue(Queue* queue);
bool isFull(Queue* queue);
bool isEmpty(Queue* queue);
void enqueue(Queue* queue, int item);
int dequeue(Queue* queue);
int peek(Queue* queue);
void displayQueue(Queue* queue);

#endif // QUEUE_H
