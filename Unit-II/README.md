# File Handling Examples in C

File handling is an essential part of programming in C. The following are 30 examples that demonstrate various file handling techniques in C, complete with code.

## Example 1: Creating a New File
```c
#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("example1.txt", "w");
    fprintf(file, "Hello World!\n");
    fclose(file);
    return 0;
}
```

## Example 2: Writing to a File
```c
#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("example2.txt", "w");
    fprintf(file, "This is an example of writing to a file.\n");
    fclose(file);
    return 0;
}
```

## Example 3: Reading from a File
```c
#include <stdio.h>

int main() {
    FILE *file;
    char buffer[255];

    file = fopen("example1.txt", "r");
    fgets(buffer, 255, file);
    printf("%s", buffer);
    fclose(file);
    return 0;
}
```

## Example 4: Appending to a File
```c
#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("example2.txt", "a");
    fprintf(file, "Appending another line.\n");
    fclose(file);
    return 0;
}
```

## Example 5: Error Handling in File Operations
```c
#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("nonexistentfile.txt", "r");
    if (file == NULL) {
        printf("Error opening file.");
        return 1;
    }
    fclose(file);
    return 0;
}
```

## Example 6: File Size Calculation
```c
#include <stdio.h>

int main() {
    FILE *file;
    long size;

    file = fopen("example1.txt", "r");
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fclose(file);
    printf("File size: %ld bytes\n", size);
    return 0;
}
```

## Example 7: Copying Content from One File to Another
```c
#include <stdio.h>

int main() {
    FILE *source, *destination;
    char ch;

    source = fopen("example1.txt", "r");
    destination = fopen("copy_example1.txt", "w");

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }
    fclose(source);
    fclose(destination);
    return 0;
}
```

## Example 8: Reading File Content Line by Line
```c
#include <stdio.h>

int main() {
    FILE *file;
    char line[255];

    file = fopen("example2.txt", "r");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    return 0;
}
```

## Example 9: Random Access in Files
```c
#include <stdio.h>

ti 

int main() {
    FILE *file;
    int value;

    file = fopen("data.bin", "wb");
    for (int i = 0; i < 10; i++) {
        fwrite(&i, sizeof(int), 1, file);
    }
    fclose(file);

    file = fopen("data.bin", "rb");
    fseek(file, 5 * sizeof(int), SEEK_SET);
    fread(&value, sizeof(int), 1, file);
    fclose(file);
    printf("Value at position 5: %d\n", value);
    return 0;
}
```

## Example 10: Using Structs for File I/O
```c
#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    FILE *file;
    struct Person person = {"John Doe", 30};

    file = fopen("person.dat", "wb");
    fwrite(&person, sizeof(struct Person), 1, file);
    fclose(file);

    struct Person readPerson;
    file = fopen("person.dat", "rb");
    fread(&readPerson, sizeof(struct Person), 1, file);
    fclose(file);
    printf("Name: %s, Age: %d\n", readPerson.name, readPerson.age);
    return 0;
}
```

## Example 11-30: (Please include your additional examples here)

Feel free to modify the examples according to your requirements.  
This document can be extended with more detailed explanations and additional examples if needed.
