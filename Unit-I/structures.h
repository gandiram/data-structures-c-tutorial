// structures.h

#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>

// Structure definition for Person
struct Person {
    char name[50];
    int age;
    char gender;
};

// Structure definition for Student
struct Student {
    struct Person personInfo;
    int studentID;
    float gpa;
};

// Union definition for Data
union Data {
    int intValue;
    float floatValue;
    char strValue[50];
};

// Enumeration for Color
enum Color {
    RED,
    GREEN,
    BLUE
};

// Function prototypes
void printPerson(struct Person p);
void printStudent(struct Student s);

#endif // STRUCTURES_H