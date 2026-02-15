# Additional Comprehensive Examples 7-34

## Structures

### Example 7
```c
#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    struct Student s1;
    printf("Enter name: ");
    scanf("%s", s1.name);
    printf("Enter age: ");
    scanf("%d", &s1.age);
    printf("Enter GPA: ");
    scanf("%f", &s1.gpa);
    printf("Student Name: %s, Age: %d, GPA: %.2f\n", s1.name, s1.age, s1.gpa);
    return 0;
}
```
This example demonstrates how to define and use a structure in C to store student information.

## Nested Structures

### Example 8
```c
#include <stdio.h>

struct Address {
    char street[100];
    char city[50];
};

struct Employee {
    char name[50];
    struct Address address;
};

int main() {
    struct Employee emp;
    printf("Enter name: ");
    scanf("%s", emp.name);
    printf("Enter street: ");
    scanf("%s", emp.address.street);
    printf("Enter city: ");
    scanf("%s", emp.address.city);
    printf("Employee Name: %s, Address: %s, %s\n", emp.name, emp.address.street, emp.address.city);
    return 0;
}
```
This example shows how to create nested structures to store an employee's address along with their name.

## Self-Referential Structures

### Example 9
```c
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
```
In this example, a self-referential structure is used to create a linked list and traverse it.

## Bit Fields

### Example 10
```c
#include <stdio.h>

struct BitField {
    unsigned int a : 3;
    unsigned int b : 5;
};

int main() {
    struct BitField bf;
    bf.a = 5;
    bf.b = 19;
    printf("a: %u, b: %u\n", bf.a, bf.b);
    return 0;
}
```
This example illustrates how to define a structure with bit fields to save memory when handling smaller data.

## Unions

### Example 11
```c
#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data data;
    data.i = 10;
    printf("Data.i: %d\n", data.i);
    data.f = 220.5;
    printf("Data.f: %.1f\n", data.f);
    data.c = 'A';
    printf("Data.c: %c\n", data.c);
    return 0;
}
```
This example demonstrates how to use a union to save memory by storing different data types in the same memory location.

## Typedef

### Example 12
```c
#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

int main() {
    Point p;
    p.x = 10;
    p.y = 20;
    printf("Point coordinates: (%d, %d)\n", p.x, p.y);
    return 0;
}
```
Using typedef simplifies type definitions and creates user-friendly type aliases.

## Enumerations

### Example 13
```c
#include <stdio.h>

enum Weekday {Sun, Mon, Tue, Wed, Thu, Fri, Sat};

int main() {
    enum Weekday today;
    today = Fri;
    printf("Today is day %d of the week.\n", today);
    return 0;
}
```
In this example, the enumeration is used to define named constants for weekdays, making the code more readable.