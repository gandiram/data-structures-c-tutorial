/*
 * infix_postfix.c
 * This program converts infix expressions to postfix (Reverse Polish Notation)
 * and evaluates postfix expressions. It uses stacks for both operations.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for stack
#define MAX 100
struct Stack {
    int top;
    int items[MAX];
};

// Function to create and initialize a stack
struct Stack* createStack() {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int item) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// Function to get the top element of the stack
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->items[stack->top];
}

// Function to check the precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = createStack();
    int i, j = 0;
    char symbol;

    for (i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];

        // If the symbol is an operand (number/variable), add it to the postfix expression
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        }
        // If the symbol is '(', push it to stack
        else if (symbol == '(') {
            push(stack, symbol);
        }
        // If the symbol is ')', pop from stack to postfix until '(' is encountered
        else if (symbol == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack); // Remove '(' from stack
        }
        // If the symbol is an operator
        else {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(symbol)) {
                postfix[j++] = pop(stack);
            }
            push(stack, symbol);
        }
    }

    // Pop all the operators from the stack
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0'; // Null terminate the postfix expression
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    struct Stack *stack = createStack();
    int i;
    int operand1, operand2;

    for (i = 0; postfix[i] != '\0'; i++) {
        char symbol = postfix[i];

        // If the symbol is an operand, push it onto the stack
        if (isdigit(symbol)) {
            push(stack, symbol - '0');
        }
        // If the symbol is an operator
        else {
            operand2 = pop(stack);
            operand1 = pop(stack);
            switch (symbol) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }

    // The final result is the only item left in the stack
    return pop(stack);
}

int main() {
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result of evaluation: %d\n", result);
    return 0;
}