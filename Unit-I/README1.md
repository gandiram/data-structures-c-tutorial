# Unit-I: Structures - Examples 1 to 7

## Example 1: Structure Basics
### Code:
```c
#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main() {
    struct Point p1;
    p1.x = 10;
    p1.y = 20;
    printf("Point p1: (%d, %d)\n", p1.x, p1.y);
    return 0;
}
```
### Output:
```plaintext
Point p1: (10, 20)
```
### Explanation:
This example demonstrates how to define a simple structure named `Point` that contains two integer members, `x` and `y`, and how to initialize and use it.

---

## Example 2: Array of Structures
### Code:
```c
#include <stdio.h>

struct Student {
    char name[50];
    int age;
};

int main() {
    struct Student students[2] = {{"Alice", 20}, {"Bob", 22}};
    for (int i = 0; i < 2; i++) {
        printf("Student %d: %s, Age: %d\n", i + 1, students[i].name, students[i].age);
    }
    return 0;
}
```
### Output:
```plaintext
Student 1: Alice, Age: 20
Student 2: Bob, Age: 22
```
### Explanation:
This example shows how to create an array of structures to hold multiple students' data.

---

## Example 3: Nested Structures
### Code:
```c
#include <stdio.h>

struct Address {
    char city[50];
    char state[50];
};

struct Person {
    char name[50];
    struct Address address;
};

int main() {
    struct Person p1 = {"Charlie", {"New York", "NY"}};
    printf("Name: %s, City: %s, State: %s\n", p1.name, p1.address.city, p1.address.state);
    return 0;
}
```
### Output:
```plaintext
Name: Charlie, City: New York, State: NY
```
### Explanation:
This example illustrates how to create a structure within another structure, allowing more complex data representation.

---

## Example 4: Passing Structures to Functions
### Code:
```c
#include <stdio.h>

struct Rectangle {
    int width;
    int height;
};

void printArea(struct Rectangle r) {
    printf("Area: %d\n", r.width * r.height);
}

int main() {
    struct Rectangle r1 = {10, 20};
    printArea(r1);
    return 0;
}
```
### Output:
```plaintext
Area: 200
```
### Explanation:
This example shows how to pass a structure to a function to operate on the structure's data.

---

## Example 5: Returning Structures from Functions
### Code:
```c
#include <stdio.h>

struct Circle {
    int radius;
};

struct Circle createCircle(int r) {
    struct Circle circle;
    circle.radius = r;
    return circle;
}

int main() {
    struct Circle c1 = createCircle(10);
    printf("Circle radius: %d\n", c1.radius);
    return 0;
}
```
### Output:
```plaintext
Circle radius: 10
```
### Explanation:
This example illustrates how to return a structure from a function.

---

## Example 6: Anonymous Structures
### Code:
```c
#include <stdio.h>

struct {
    int x;
    int y;
} point;

int main() {
    point.x = 5;
    point.y = 10;
    printf("Point: (%d, %d)\n", point.x, point.y);
    return 0;
}
```
### Output:
```plaintext
Point: (5, 10)
```
### Explanation:
This example demonstrates the use of anonymous structures where we do not use a name for the structure type.

---

## Example 7: Structures and Memory
### Code:
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;
    printf("Node data: %d\n", head->data);
    free(head);
    return 0;
}
```
### Output:
```plaintext
Node data: 1
```
### Explanation:
This example shows how to use dynamic memory allocation with structures to create linked list nodes.
