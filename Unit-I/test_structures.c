#include <stdio.h>
#include <string.h>

// Basic Structures
struct Point {
    int x;
    int y;
};

void test_basic_structures() {
    struct Point p1 = {3, 4};
    printf("Point p1: (%d, %d)\n", p1.x, p1.y);
}

// Self-Referential Structures
struct Node {
    int data;
    struct Node* next;
};

void test_self_referential_structure() {
    struct Node n1;
    n1.data = 10;
    n1.next = NULL;
    printf("Node data: %d\n", n1.data);
}

// Union Types
union Data {
    int intVal;
    float floatVal;
    char charVal;
};

void test_union() {
    union Data data;
    data.intVal = 5;
    printf("Union Data as int: %d\n", data.intVal);
    data.floatVal = 4.5;
    printf("Union Data as float: %f\n", data.floatVal);
}

// Bit Fields
struct Flags {
    unsigned int isVisible : 1;
    unsigned int isEnabled : 1;
};

void test_bit_fields() {
    struct Flags flags = {1, 0};
    printf("Flags - isVisible: %d, isEnabled: %d\n", flags.isVisible, flags.isEnabled);
}

// Enumerations
enum Color {
    RED,
    GREEN,
    BLUE
};

void test_enumerations() {
    enum Color myColor = GREEN;
    printf("Color Enumeration: %d\n", myColor);
}

// Typedef
typedef unsigned long ulong;
void test_typedef() {
    ulong largeNumber = 123456789;
    printf("Typedef unsigned long: %lu\n", largeNumber);
}

// Complex Nested Structures
struct Employee {
    char name[50];
    struct Point location;
};

void test_complex_nested_structure() {
    struct Employee emp;
    strcpy(emp.name, "Alice");
    emp.location.x = 10;
    emp.location.y = 20;
    printf("Employee Name: %s, Location: (%d, %d)\n", emp.name, emp.location.x, emp.location.y);
}

int main() {
    test_basic_structures();
    test_self_referential_structure();
    test_union();
    test_bit_fields();
    test_enumerations();
    test_typedef();
    test_complex_nested_structure();
    return 0;
}