# Unit-I: Basics of Data Structures in C

## 1. Structures
Structures in C are used to group different types of data together. Each element in a structure can be of different data types.

### Example 1: Define a Structure for a Student
```c
#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    float marks;
};

int main() {
    struct Student student1;
    // Assigning values
    strcpy(student1.name, "Alice");
    student1.roll_no = 101;
    student1.marks = 88.5;

    printf("Name: %s\n", student1.name);
    printf("Roll Number: %d\n", student1.roll_no);
    printf("Marks: %.2f\n", student1.marks);
    return 0;
}
```

### Example 2: Structure for a Book
```c
#include <stdio.h>

struct Book {
    char title[100];
    char author[50];
    int year;
};

int main() {
    struct Book book1;
    // Assigning values
    strcpy(book1.title, "C Programming");
    strcpy(book1.author, "Dennis Ritchie");
    book1.year = 1978;

    printf("Title: %s\n", book1.title);
    printf("Author: %s\n", book1.author);
    printf("Year: %d\n", book1.year);
    return 0;
}
```

### Example 3: Structure for a Point
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
    printf("Point coordinates: (%d, %d)\n", p1.x, p1.y);
    return 0;
}
```


## 2. Unions
Unions in C are similar to structures, but they use the same memory location for all their members, allowing for more efficient use of memory.

### Example 1: Union for an Integer or Float
```c
#include <stdio.h>

union Data {
    int intVal;
    float floatVal;
};

int main() {
    union Data data;
    data.intVal = 10;
    printf("Integer: %d\n", data.intVal);
    data.floatVal = 220.5;
    printf("Float: %.2f\n", data.floatVal);
    // Note: intVal value is now overwritten
    printf("Integer after float assignment: %d\n", data.intVal);
    return 0;
}
```

### Example 2: Union for Different Types of Data
```c
#include <stdio.h>

union Value {
    int intVal;
    char charVal;
};

int main() {
    union Value val;
    val.intVal = 65;
    printf("Integer Value: %d\n", val.intVal);
    val.charVal = 'B';
    printf("Character Value: %c\n", val.charVal);
    // Note: intVal value is now overwritten
    printf("Integer after char assignment: %d\n", val.intVal);
    return 0;
}
```

### Example 3: Union for Storing Different Data Types
```c
#include <stdio.h>

union Measurement {
    float feet;
    float meters;
};

int main() {
    union Measurement m1;
    m1.feet = 5.5;
    printf("Height in Feet: %.2f\n", m1.feet);
    m1.meters = 1.65;
    printf("Height in Meters: %.2f\n", m1.meters);
    // Note: feet value is now overwritten
    printf("Feet after meters assignment: %.2f\n", m1.feet);
    return 0;
}
```


## 3. Typedef
Typedef is used to create an alias for existing data types, improving code readability.

### Example 1: Typedef for a Simple Data Type
```c
#include <stdio.h>

typedef unsigned long ulong;

int main() {
    ulong a = 12345678;
    printf("Value: %lu\n", a);
    return 0;
}
```

### Example 2: Typedef for a Structure
```c
#include <stdio.h>

typedef struct {
    char name[50];
    int age;
} Person;

int main() {
    Person p1;
    strcpy(p1.name, "John");
    p1.age = 30;
    printf("Name: %s, Age: %d\n", p1.name, p1.age);
    return 0;
}
```

### Example 3: Typedef for a Function Pointer
```c
#include <stdio.h>

typedef int (*operation)(int, int);

int add(int a, int b) {
    return a + b;
}

int main() {
    operation op = add;
    printf("Sum: %d\n", op(10, 5));
    return 0;
}
```


## 4. Enumerations
Enumerations are a user-defined data type that consists of integral constants, improving code readability.

### Example 1: Define Days of the Week
```c
#include <stdio.h>

typedef enum { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY } Day;

int main() {
    Day today = WEDNESDAY;
    printf("Today is day number: %d\n", today);
    return 0;
}
```

### Example 2: Define Colors
```c
#include <stdio.h>

typedef enum { RED, GREEN, BLUE } Color;

int main() {
    Color myColor = GREEN;
    printf("Selected Color: %d\n", myColor);
    return 0;
}
```

### Example 3: Define Error Codes
```c
#include <stdio.h>

typedef enum { SUCCESS, FAILURE, ERROR_NOT_FOUND } ErrorCode;

int main() {
    ErrorCode code = ERROR_NOT_FOUND;
    if (code == ERROR_NOT_FOUND) {
        printf("Error: Resource not found!\n");
    }
    return 0;
}
```

---

## Conclusion
Understanding structures, unions, typedef, and enumerations is fundamental in C programming. They help in organizing data effectively, allowing us to write cleaner and more maintainable code.