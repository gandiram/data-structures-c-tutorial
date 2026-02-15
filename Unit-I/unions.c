// unions.c

#include <stdio.h>
#include <string.h>

// Example of a simple union
union Data {
   int i;
   float f;
   char str[20];
};

int main() {
   union Data data;

   // Using integer type
   data.i = 10;
   printf("data.i = %d\n", data.i);

   // Using float type
   data.f = 220.5;
   printf("data.f = %.2f\n", data.f);
   printf("data.i = %d (this value is overwritten)\n", data.i);

   // Using string type
   strcpy(data.str, "Hello World");
   printf("data.str = %s\n", data.str);
   printf("data.i = %d (this value is overwritten)\n", data.i);
   printf("data.f = %.2f (this value is overwritten)\n", data.f);

   return 0;
}

// Example of a union within a struct
struct Student {
   char name[50];
   int id;
   union {
       float gpa;
       int year;
   } info;
};

void printStudent(struct Student student) {
   printf("Name: %s\n", student.name);
   printf("ID: %d\n", student.id);
   printf("GPA: %.2f\n", student.info.gpa);
}

int main() {
   struct Student student1;
   strcpy(student1.name, "John Doe");
   student1.id = 12345;
   student1.info.gpa = 3.5;
   printStudent(student1);
   return 0;
}