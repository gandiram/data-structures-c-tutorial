# Comprehensive Examples

This README now includes 34 complete working examples covering the following topics:

1. Structures
2. Nested Structures
3. Self-referential Structures
4. Bit Fields
5. Unions
6. Typedef
7. Enumerations
--------------------------------------------------------------------------------------------------------------------------------------
## Examples:

### 1. Structures
#include <stdio.h>

struct Rectangle {
    int width;
    int height;
};

int main() {
    struct Rectangle rect;
    rect.width = 10;
    rect.height = 5;
    printf("Width: %d, Height: %d\n", rect.width, rect.height);
    return 0;
}
This program defines a simple structure for a rectangle and initializes an instance of it.
-------------------------------------------------------------------------------------------------------------------------------------
2. Nested Structures
#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    char name[50];
    struct Date hireDate;
};

int main() {
    struct Employee emp = {"Alice", {15, 6, 2020}};
    printf("Employee: %s, Hire Date: %02d/%02d/%04d\n", emp.name, emp.hireDate.day, emp.hireDate.month, emp.hireDate.year);
    return 0;
}
This program shows how to nest structures.
--------------------------------------------------------------------------------------------------------------------------------------
3. Self-referential Structures
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = NULL;
    printList(head);
    return 0;
}
This program demonstrates a simple linked list using self-referential structures.
---------------------------------------------------------------------------------------------------------------------------------------
4. Bit Fields

#include <stdio.h>

struct Bits {
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b3 : 1;
};

int main() {
    struct Bits bits = {1, 0, 1};
    printf("Bits: %u %u %u\n", bits.b1, bits.b2, bits.b3);
    return 0;
}
This program illustrates the use of bit fields in structures.
---------------------------------------------------------------------------------------------------------------------------------------
5. Unions
#include <stdio.h>

union Data {
    int intValue;
    float floatValue;
    char charValue;
};

int main() {
    union Data data;
    data.intValue = 5;
    printf("Int: %d\n", data.intValue);
    data.floatValue = 10.5;
    printf("Float: %f\n", data.floatValue);
    return 0;
}
This program demonstrates how unions work, sharing memory between different data types.
---------------------------------------------------------------------------------------------------------------------------------------
6. Typedef
#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

int main() {
    Point p1 = {10, 20};
    printf("Point: (%d, %d)\n", p1.x, p1.y);
    return 0;
}
This program uses typedef to create a new name for an unnamed structure.
--------------------------------------------------------------------------------------------------------------------------------------
7. Enumerations

#include <stdio.h>

typedef enum {RED, GREEN, BLUE} Color;

int main() {
    Color col = GREEN;
    printf("Color: %d\n", col);
    return 0;
}
This program shows how to define and use enumerations.
