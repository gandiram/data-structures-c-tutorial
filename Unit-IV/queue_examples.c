# Queue Examples in C

This file contains comprehensive examples of various queue implementations in C:

## 1. Simple Queue

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->items[++(q->rear)] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[(q->front)++];
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}
```

## 2. Circular Queue

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front, rear;
} CircularQueue;

void initialize(CircularQueue *q) {
    q->front = q->rear = -1;
}

int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(CircularQueue *q) {
    return q->front == -1;
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }
    q->items[q->rear] = value;
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
```

## 3. Priority Queue

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int priority;
} Item;

typedef struct {
    Item *items;
    int capacity;
    int size;
} PriorityQueue;

void initialize(PriorityQueue *pq, int capacity) {
    pq->capacity = capacity;
    pq->size = 0;
    pq->items = (Item *)malloc(capacity * sizeof(Item));
}

int isFull(PriorityQueue *pq) {
    return pq->size == pq->capacity;
}

int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}
}

void enqueue(PriorityQueue *pq, int value, int priority) {
    if (isFull(pq)) {
        printf("Priority Queue is full\n");
        return;
    }
    Item item;
    item.value = value;
    item.priority = priority;
    pq->items[pq->size++] = item;
}

int dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty\n");
        return -1;
    }
    int highestPriorityIndex = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->items[i].priority < pq->items[highestPriorityIndex].priority) {
            highestPriorityIndex = i;
        }
    }
    int value = pq->items[highestPriorityIndex].value;
    pq->items[highestPriorityIndex] = pq->items[--(pq->size)];
    return value;
}

void display(PriorityQueue *pq) {
    for (int i = 0; i < pq->size; i++) {
        printf("Value: %d, Priority: %d\n", pq->items[i].value, pq->items[i].priority);
    }
}
```

## 4. Linked List Queue

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} LinkedListQueue;

void initialize(LinkedListQueue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(LinkedListQueue *q) {
    return q->front == NULL;
}

void enqueue(LinkedListQueue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(LinkedListQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

void display(LinkedListQueue *q) {
    Node *current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
```

## 5. Deque Implementation

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front, rear;
} Deque;

void initialize(Deque *dq) {
    dq->front = dq->rear = -1;
}

int isFull(Deque *dq) {
    return (dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1);
}

int isEmpty(Deque *dq) {
    return dq->front == -1;
}

void insertFront(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->items[dq->front] = value;
}

void insertRear(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->items[dq->rear] = value;
}

int deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    int value = dq->items[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
    return value;
}

int deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    int value = dq->items[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
    return value;
}

void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    int i = dq->front;
    while (1) {
        printf("%d ", dq->items[i]);
        if (i == dq->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
```
