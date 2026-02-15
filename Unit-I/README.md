# Comprehensive Examples for Structures, Unions, Typedef, and Enumerations

## Structures

### Example 1: Employee Structure
```c
struct Employee {
    int id;
    char name[50];
    float salary;
};

void printEmployee(struct Employee emp) {
    printf("Employee ID: %d\n", emp.id);
    printf("Employee Name: %s\n", emp.name);
    printf("Employee Salary: %.2f\n", emp.salary);
}
```

### Example 2: Point in 2D
```c
struct Point {
    int x;
    int y;
};

void movePoint(struct Point *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}
```

### Example 3: Rectangle
```c
struct Rectangle {
    struct Point topLeft;
    struct Point bottomRight;
};

int area(struct Rectangle rect) {
    return (rect.bottomRight.x - rect.topLeft.x) * (rect.topLeft.y - rect.bottomRight.y);
}
```

## Unions

### Example 1: Data Types
```c
union Data {
    int intValue;
    float floatValue;
    char charValue;
};

void printData(union Data data, char type) {
    if (type == 'i')
        printf("Integer: %d\n", data.intValue);
    else if (type == 'f')
        printf("Float: %.2f\n", data.floatValue);
    else if (type == 'c')
        printf("Character: %c\n", data.charValue);
}
```

### Example 2: Color Representation
```c
union Color {
    struct {
        unsigned char r;
        unsigned char g;
        unsigned char b;
    } rgb;
    unsigned int hex;
};

void printColor(union Color color) {
    printf("RGB: (%d, %d, %d)\n", color.rgb.r, color.rgb.g, color.rgb.b);
    printf("Hex: #%X\n", color.hex);
}
```

### Example 3: IPv4 Address
```c
union IPAddress {
    unsigned char bytes[4];
    unsigned int value;  // This can represent the whole address as a single number
};

void printIPAddress(union IPAddress ip) {
    printf("IP Address: %d.%d.%d.%d\n", ip.bytes[0], ip.bytes[1], ip.bytes[2], ip.bytes[3]);
}
```

## Typedefs

### Example 1: Define a Complex Number Type
```c
typedef struct {
    float real;
    float imag;
} Complex;

void printComplex(Complex c) {
    printf("Complex Number: %.2f + %.2fi\n", c.real, c.imag);
}
```

### Example 2: Function Pointer Typedef
```c
typedef void (*FuncPtr)(int);

void invokeFunction(FuncPtr func, int arg) {
    func(arg);
}
```

### Example 3: Linked List
```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;

void append(Node **head, int newData) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}
```

## Enumerations

### Example 1: Days of the Week
```c
typedef enum { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY } Day;

void printDay(Day day) {
    const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf("Day: %s\n", days[day]);
}
```

### Example 2: Traffic Light States
```c
typedef enum { RED, YELLOW, GREEN } TrafficLight;

void printTrafficLight(TrafficLight light) {
    switch (light) {
        case RED: printf("Stop!\n"); break;
        case YELLOW: printf("Caution!\n"); break;
        case GREEN: printf("Go!\n"); break;
    }
}
```

### Example 3: File Access Modes
```c
typedef enum { READ, WRITE, APPEND } AccessMode;

void openFile(const char *filename, AccessMode mode) {
    const char *modes[] = {"r", "w", "a"};
    FILE *file = fopen(filename, modes[mode]);
}
```
