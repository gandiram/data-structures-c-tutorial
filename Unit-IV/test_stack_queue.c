# Test Cases for Stack and Queue Operations

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack implementation
typedef struct Stack {
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (!isFull(stack)) {
        stack->array[++stack->top] = item;
    }
}

int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return -1; // or some sentinel value
}

// Function to check for precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Infix to Postfix conversion
char* infixToPostfix(char* exp) {
    Stack* stack = createStack(strlen(exp));
    char* result = (char*)malloc(strlen(exp) + 1);
    int j = 0;

    for (int i = 0; exp[i]; i++) {
        if (isalnum(exp[i])) {
            result[j++] = exp[i];
        } else if (exp[i] == '(') {
            push(stack, exp[i]);
        } else if (exp[i] == ')') {
            while (!isEmpty(stack) && stack->array[stack->top] != '(') {
                result[j++] = pop(stack);
            }
            pop(stack); // Remove '('
        } else { // Operator
            while (!isEmpty(stack) && precedence(stack->array[stack->top]) >= precedence(exp[i])) {
                result[j++] = pop(stack);
            }
            push(stack, exp[i]);
        }
    }

    while (!isEmpty(stack)) {
        result[j++] = pop(stack);
    }
    result[j] = '\0';
    free(stack->array);
    free(stack);
    return result;
}

// Postfix Evaluation
int evaluatePostfix(char* exp) {
    Stack* stack = createStack(strlen(exp));

    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            push(stack, exp[i] - '0');
        } else {
            int val2 = pop(stack);
            int val1 = pop(stack);
            switch (exp[i]) {
                case '+': push(stack, val1 + val2); break;
                case '-': push(stack, val1 - val2); break;
                case '*': push(stack, val1 * val2); break;
                case '/': push(stack, val1 / val2); break;
            }
        }
    }
    return pop(stack);
}

// Queue implementation
typedef struct Queue {
    int front, rear, capacity;
    int* array;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFullQueue(Queue* queue) {
    return queue->size == queue->capacity;
}

int isEmptyQueue(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, int item) {
    if (!isFullQueue(queue)) {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->array[queue->rear] = item;
        queue->size++;
    }
}

int dequeue(Queue* queue) {
    if (!isEmptyQueue(queue)) {
        int item = queue->array[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size--;
        return item;
    }
    return -1; // or some sentinel value
}

// Unit tests
int main() {
    // Stack tests
    Stack* stack = createStack(5);
    push(stack, 10);
    printf("Stack Pop: %d\n", pop(stack)); // expect 10

    // Infix to Postfix test
    char infix[] = "A+B*C";
    char* postfix = infixToPostfix(infix);
    printf("Infix to Postfix: %s\n", postfix);
    free(postfix);

    // Postfix Evaluation test
    char postfixExpr[] = "231*+9-";
    printf("Postfix Evaluation: %d\n", evaluatePostfix(postfixExpr)); // expect result

    // Queue tests
    Queue* queue = createQueue(5);
    enqueue(queue, 1);
    printf("Queue Dequeue: %d\n", dequeue(queue)); // expect 1

    free(stack->array);
    free(stack);
    free(queue->array);
    free(queue);
    return 0;
}
