# Test Cases for Structure Operations, Union Examples, Typedef Usage, and Enumeration Demonstrations in C

#include <stdio.h>
#include <string.h>

// Structure Operations Test
struct Student {
    char name[50];
    int age;
};

void test_structure_operations() {
    struct Student s1;
    strcpy(s1.name, "Alice");
    s1.age = 20;

    printf("Name: %s, Age: %d\n", s1.name, s1.age);
}

// Union Examples Test
union Data {
    int i;
    float f;
    char str[20];
};

void test_union_examples() {
    union Data data;
    data.i = 10;
    printf("Union int: %d\n", data.i);
    data.f = 220.5;
    printf("Union float: %f\n", data.f);
    strcpy(data.str, "Hello");
    printf("Union string: %s\n", data.str);
}

// Typedef Usage Test
typedef unsigned long ulong;

void test_typedef_usage() {
    ulong num = 123456789;
    printf("Typedef unsigned long: %lu\n", num);
}

// Enumeration Demonstrations Test
enum Color {RED, GREEN, BLUE};

void test_enum_demonstrations() {
    enum Color myColor;
    myColor = GREEN;
    printf("Enumeration Color: %d\n", myColor);
}

int main() {
    printf("=== Structure Operations Test ===\n");
    test_structure_operations();

    printf("\n=== Union Examples Test ===\n");
    test_union_examples();

    printf("\n=== Typedef Usage Test ===\n");
    test_typedef_usage();

    printf("\n=== Enumeration Demonstrations Test ===\n");
    test_enum_demonstrations();

    return 0;
}