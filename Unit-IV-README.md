# Unit IV

## Stack and Queue Examples

### Stack Example
A stack is a data structure that follows the Last In First Out (LIFO) principle. Here is a simple implementation of a stack in C:

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int items[MAX];
    int top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow");
        return;
    }
    stack->items[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow");
        return -1;
    }
    return stack->items[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty");
        return -1;
    }
    return stack->items[stack->top];
}

int main() {
    struct Stack* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    printf("Top element is %d\n", peek(stack));
    printf("Popped element is %d\n", pop(stack));
    return 0;
}
```

### Queue Example
A queue is a data structure that follows the First In First Out (FIFO) principle. Here’s a simple implementation of a queue in C:

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int items[MAX];
    int front, rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

int isFull(struct Queue* queue) {
    return queue->rear == MAX - 1;
}

int isEmpty(struct Queue* queue) {
    return queue->front > queue->rear;
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full");
        return;
    }
    queue->items[++queue->rear] = item;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty");
        return -1;
    }
    return queue->items[queue->front++];
}

int main() {
    struct Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    printf("Dequeued element is %d\n", dequeue(queue));
    return 0;
}
```

## Conclusion
Understanding these data structures is crucial for efficient programming and algorithm design.