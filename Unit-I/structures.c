// structures.c

#include <stdio.h>
#include <string.h>

// Defining a structure for a Student
struct Student {
    char name[50];
    int age;
    float gpa;
};

// Function to display student details
void displayStudent(struct Student s) {
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("GPA: %.2f\n", s.gpa);
}

int main() {
    // Creating and initializing a Student instance
    struct Student student1;
    strcpy(student1.name, "John Doe");
    student1.age = 21;
    student1.gpa = 3.8;

    // Displaying student details
    displayStudent(student1);

    return 0;
}