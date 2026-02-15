/*
 * structures.c
 * This file contains comprehensive examples of structures, unions, typedef,
 * enumerations, bit fields, and self-referential structures in C.
 */

#include <stdio.h>
#include <string.h>

/* Structure definition */
typedef struct {
    char name[50];
    int age;
} Person;

/* Union definition */
typedef union {
    int intValue;
    float floatValue;
    char charValue;
} Data;

/* Enumeration definition */
typedef enum {
    RED,
    GREEN,
    BLUE
} Color;

/* Bit field example */
typedef struct {
    unsigned int isReady : 1;
    unsigned int size : 3;
    unsigned int type : 4;
} Status;

/* Self-referential structure */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

void printPerson(Person p) {
    printf("Name: %s, Age: %d\n", p.name, p.age);
}

void demonstrateUnion() {
    Data data;
    data.intValue = 10;
    printf("Union store integer: %d\n", data.intValue);
    data.floatValue = 5.5;  // overwrites intValue
    printf("Union store float: %.2f\n", data.floatValue);
}

void demonstrateEnumeration() {
    Color myColor = GREEN;
    if (myColor == GREEN) {
        printf("Color is green.\n");
    }
}

void demonstrateBitField() {
    Status status;
    status.isReady = 1;
    status.size = 3;
    status.type = 2;
    printf("Status - Is Ready: %d, Size: %d, Type: %d\n", status.isReady, status.size, status.type);
}

void demonstrateSelfReferential() {
    Node node1;
    node1.data = 10;
    Node node2;
    node2.data = 20;
    node1.next = &node2;
    printf("Node 1 data: %d, Node 2 data: %d\n", node1.data, node1.next->data);
}

int main() {
    Person p = {"Alice", 30};
    printPerson(p);

    demonstrateUnion();
    demonstrateEnumeration();
    demonstrateBitField();
    demonstrateSelfReferential();

    return 0;
}