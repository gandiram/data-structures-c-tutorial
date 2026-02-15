## Example 8: Nested Structures
A nested structure is a structure within another structure.

```c
struct Address {
    char city[50];
    char state[50];
};

struct Employee {
    char name[100];
    int id;
    struct Address address; // Nested structure
};

struct Employee emp;
strcpy(emp.name, "John Doe");
emp.id = 123;
strcpy(emp.address.city, "New York");
strcpy(emp.address.state, "NY");
```  

## Example 9: Self-Referential Structures
A self-referential structure is a structure that references itself, commonly used in linked lists.

```c
struct Node {
    int data;
    struct Node* next; // Pointer to another Node
};

struct Node node1;
node1.data = 10;
node1.next = NULL; // Initializing next as NULL
```  

## Example 10: Bit Fields
Bit fields allow the packing of data in a structure, saving space.

```c
struct Status {
    unsigned int isAlive : 1;
    unsigned int isRunning : 1;
    unsigned int errorCode : 3;
};
struct Status s;
s.isAlive = 1;
s.isRunning = 0;
s.errorCode = 3;
```  

## Example 11: Unions
A union is similar to a structure but allows storing different data types in the same memory location.

```c
union Data {
    int i;
    float f;
    char str[20];
};
union Data data;
data.i = 10; // Fitting integer
```  

## Example 12: Typedef
Typedef is used to create new names for existing data types.

```c
typedef unsigned long ulong;
ulong count = 1000;
```  

## Example 13: Enumerations
Enumerations are user-defined data types that consist of integral constants.

```c
typedef enum { RED, GREEN, BLUE } Color;
Color myColor = GREEN;
```  

## Example 14: Nested Structure Example
```c
struct Student {
    char name[50];
    struct Date {
        int day;
        int month;
        int year;
    } dob;
};
struct Student student1;
strcpy(student1.name, "Alice");
student1.dob.day = 15;
student1.dob.month = 8;
student1.dob.year = 2000;
```

## Example 15: Recursive Definition Using Self-Referential Structures
```c
struct List {
    int value;
    struct List *next;
};
struct List item1, item2;
item1.value = 1;
item2.value = 2;
item1.next = &item2;
item2.next = NULL;
```

## Example 16: Demonstrating Bit Fields in a Struct
```c
struct Flags {
    unsigned int isAdmin : 1;
    unsigned int hasAccess : 1;
};
struct Flags userFlags;
userFlags.isAdmin = 1;
```

## Example 17: Example of Union Usage
```c
union Value {
    int intValue;
    char charValue;
};
union Value myValue;
myValue.intValue = 42; // Sets intValue
printf("Integer: %d\n", myValue.intValue);
```

## Example 18: Using Typedef to Simplify Code
```c
typedef short int sht;
sht smallNumber = 3000;
```

## Example 19: Color Enum Example
```c
typedef enum Color { YELLOW, RED, BLUE } Color;
Color bgColor = RED;
```

## Example 20: Nested Structures with Union Example
```c
struct Employee {
    char name[50];
    union {
        int id;
        char ssn[12];
    } identifier;
};
```  

## Example 21: Programming a Self-Referencing Linked List
```c
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
```  

## Example 22: Bit Field for Flags in Data
```c
struct Features {
    unsigned int feature1 : 1;
    unsigned int feature2 : 1;
};
struct Features deviceFeatures;
deviceFeatures.feature1 = 1;
```  

## Example 23: Unions for Memory Efficiency
```c
union NumericValue {
    int i;
    float f;
};
union NumericValue numVal;
numVal.f = 5.5; // Only one can be used at a time
```  

## Example 24: Typedef Allowing for Easy Struct Naming
```c
typedef struct {
    int x;
    int y;
} Point;
Point p1 = {10, 20};
```  

## Example 25: Enum for Weekdays
```c
typedef enum Days { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY } Day;
Day today = MONDAY;
```  

## Example 26: Nested Struct with Array
```c
struct Course {
    char title[30];
    int credits;
};
struct Department {
    char name[30];
    struct Course courses[5];  // Array of structures
};
```  

## Example 27: Self-referential Struct for Doubly Linked List
```c
struct DListNode {
    int data;
    struct DListNode* next;
    struct DListNode* prev;
};
```  

## Example 28: Bit Fields for Control Register
```c
struct ControlRegister {
    unsigned int enable : 1;
    unsigned int mode : 2;
};
struct ControlRegister reg;
reg.enable = 1;
```  

## Example 29: Unions for Multi-Type Data Storage
```c
union MixedData {
    int id;
    float price;
};
union MixedData item;
item.id = 123;
```  

## Example 30: Using Typedef with Complex Structures
```c
typedef struct {
    int x;
    int y;
} Point;
typedef struct {
    Point p1;
    Point p2;
} Line;
```  

## Example 31: Enum for State Representation
```c
typedef enum States { START, PROCESS, END } State;
State currentState = START;
```  

## Example 32: Self-referential Structures for Trees
```c
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
```  

## Example 33: Nested Structures for Employee Directory
```c
struct Address {
    char street[50];
    char city[50];
};
struct Employee {
    char name[50];
    struct Address address;
};
```  

## Example 34: Union for Different Types
```c
union DataIdentifier {
    int id;
    char code[10];
};
union DataIdentifier identifier;
identifier.id = 101;
```