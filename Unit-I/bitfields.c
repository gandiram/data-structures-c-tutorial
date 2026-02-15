// bitfields.c
#include <stdio.h>

struct Flags {
    unsigned int isActive : 1;
    unsigned int isVerified : 1;
    unsigned int isAdmin : 1;
};

struct Date {
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 12;
};

struct Permissions {
    unsigned int canRead : 1;
    unsigned int canWrite : 1;
    unsigned int canExecute : 1;
};

int main() {
    printf("Bit Fields Examples\n\n");
    
    struct Flags flags;
    flags.isActive = 1;
    flags.isVerified = 0;
    flags.isAdmin = 1;
    printf("Flags struct size: %lu bytes\n", sizeof(struct Flags));
    printf("isActive: %u, isVerified: %u, isAdmin: %u\n", 
           flags.isActive, flags.isVerified, flags.isAdmin);
    
    struct Date date;
    date.day = 25;
    date.month = 12;
    date.year = 2024;
    printf("\nDate struct size: %lu bytes\n", sizeof(struct Date));
    printf("Date: %d/%d/%d\n", date.day, date.month, date.year);
    
    struct Permissions perm;
    perm.canRead = 1;
    perm.canWrite = 1;
    perm.canExecute = 0;
    printf("\nPermissions: Read: %u, Write: %u, Execute: %u\n",
           perm.canRead, perm.canWrite, perm.canExecute);
    
    return 0;
}
