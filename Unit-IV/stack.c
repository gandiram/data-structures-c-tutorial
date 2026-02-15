/*
 * stack.c - Implementation of stack operations in C.
 *
 * This file contains the implementation of a stack data structure with the following operations:
 * - Push: Add an element to the stack.
 * - Pop: Remove and return the top element from the stack.
 * - Peek: Get the top element without removing it.
 * - isEmpty: Check if the stack is empty.
 * - Display: Print the elements of the stack.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
typedef struct Stack {
    int items[MAX]; // Array to store stack elements
    int top;        // Index of the top element
} Stack;

// Function to create and initialize a stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1; // Initialize top to -1 indicating the stack is empty
    return stack;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot push %d\n", item);
        return;
    }
    stack->items[++stack->top] = item; // Increment top and add item
    printf("Pushed %d to stack\n", item);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop from an empty stack\n");
        return -1; // Return -1 to indicate error
    }
    return stack->items[stack->top--]; // Return top item and decrement top
}

// Function to peek at the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty: Cannot peek\n");
        return -1; // Return -1 to indicate error
    }
    return stack->items[stack->top]; // Return top item without removing it
}

// Function to display the elements of the stack
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

// Example usage of the stack
int main() {
    Stack* stack = createStack(); // Create a stack
    push(stack, 10);   // Push elements onto the stack
    push(stack, 20);
    push(stack, 30);
    display(stack);     // Display stack contents
    printf("Popped %d from stack\n", pop(stack)); // Pop an element
    printf("Top element is %d\n", peek(stack)); // Peek at top element
    display(stack);     // Display stack contents again
    return 0;
}