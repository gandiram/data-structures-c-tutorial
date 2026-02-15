// enumerations.c
#include <stdio.h>

enum Color { RED, GREEN, BLUE, YELLOW };
enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };
enum Status { INACTIVE = 0, ACTIVE = 1, PENDING = 2 };

int main() {
    printf("Enumeration Examples\n\n");
    
    enum Color myColor = GREEN;
    printf("Color: %d\n", myColor);
    
    enum Day today = FRI;
    printf("Day: %d\n", today);
    
    enum Status userStatus = ACTIVE;
    printf("Status: %d\n", userStatus);
    
    printf("\nEnum values:\n");
    printf("RED: %d, GREEN: %d, BLUE: %d\n", RED, GREEN, BLUE);
    printf("INACTIVE: %d, ACTIVE: %d, PENDING: %d\n", INACTIVE, ACTIVE, PENDING);
    
    return 0;
}
