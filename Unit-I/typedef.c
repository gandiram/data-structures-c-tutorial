// typedef.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    float length;
    float width;
} Rectangle;

typedef unsigned int uint;
typedef long long ll;

typedef int (*Operation)(int, int);

int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main() {
    printf("Typedef Examples\n\n");
    
    Point p = {10, 20};
    printf("Point: (%d, %d)\n", p.x, p.y);
    
    Rectangle r = {5.5, 3.2};
    printf("Rectangle Area: %.2f\n", r.length * r.width);
    
    uint count = 1000;
    printf("Count: %u\n", count);
    
    Operation op = add;
    printf("Add(5,3): %d\n", op(5, 3));
    
    Date d = {15, 8, 1995};
    printf("Date: %d/%d/%d\n", d.day, d.month, d.year);
    
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;
    printf("Node data: %d\n", head->data);
    free(head);
    
    return 0;
}
