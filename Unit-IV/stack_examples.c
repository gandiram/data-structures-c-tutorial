# Stack Implementation Examples in C

This file includes comprehensive examples demonstrating various stack operations and applications, including parenthesis matching, expression evaluation, palindrome checking, and undo/redo functionality.

## Basic Stack Operations

### Stack Structure
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} Stack;

Stack* createStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int item) {
    if (!isFull(s)) {
        s->items[++s->top] = item;
    } else {
        printf("Stack is full\n");
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return -1;
}
```

### Parenthesis Matching
```c
int isMatching(char *exp) {
    Stack *s = createStack();
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(') {
            push(s, exp[i]);
        } else if (exp[i] == ')') {
            if (isEmpty(s)) {
                return 0;
            }
            pop(s);
        }
    }
    return isEmpty(s);
}
```

### Expression Evaluation
```c
int evaluatePostfix(char* exp) {
    Stack *s = createStack();
    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            push(s, exp[i] - '0');
        } else {
            int val2 = pop(s);
            int val1 = pop(s);
            switch (exp[i]) {
                case '+': push(s, val1 + val2); break;
                case '-': push(s, val1 - val2); break;
                case '*': push(s, val1 * val2); break;
                case '/': push(s, val1 / val2); break;
            }
        }
    }
    return pop(s);
}
```

### Palindrome Checking
```c
int isPalindrome(char *str) {
    Stack *s = createStack();
    for (int i = 0; str[i]; i++) {
        push(s, str[i]);
    }
    for (int i = 0; str[i]; i++) {
        if (str[i] != pop(s)) {
            return 0;
        }
    }
    return 1;
}
```

### Undo/Redo Functionality
```c
typedef struct {
    Stack *undo;
    Stack *redo;
} UndoRedo;

UndoRedo* createUndoRedo() {
    UndoRedo *ur = (UndoRedo*)malloc(sizeof(UndoRedo));
    ur->undo = createStack();
    ur->redo = createStack();
    return ur;
}

void makeChange(UndoRedo *ur, char *change) {
    push(ur->undo, change);
    // Clear redo stack
    while (!isEmpty(ur->redo)) {
        pop(ur->redo);
    }
}

char* undo(UndoRedo *ur) {
    if (isEmpty(ur->undo)) return NULL;
    char *change = pop(ur->undo);
    push(ur->redo, change);
    return change;
}

char* redo(UndoRedo *ur) {
    if (isEmpty(ur->redo)) return NULL;
    char *change = pop(ur->redo);
    push(ur->undo, change);
    return change;
}
```

## Conclusion

This file contains a comprehensive stack implementation in C. The examples can be modified and expanded for various applications as required.