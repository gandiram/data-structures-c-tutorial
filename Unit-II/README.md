# File Operations

## Comprehensive Examples

### 1. File Operations

To read from and write to files in C, you can use the following standard library functions:

- **fopen**: Used to open a file.
- **fprintf**: Used to write formatted output to a file.
- **fscanf**: Used to read formatted input from a file.
- **fclose**: Used to close a file.

```c
#include <stdio.h>

int main() {
    FILE *fptr;
    fptr = fopen("example.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!");
        return 1;
    }
    fprintf(fptr, "Hello, world!\n");
    fclose(fptr);
    return 0;
}
```

### 2. Binary Files

Binary files are handled similarly to text files but require the use of binary mode when opening the file. Use `"wb"` for writing and `"rb"` for reading.

```c
#include <stdio.h>

int main() {
    FILE *fptr;
    int num = 10;
    fptr = fopen("binaryfile.bin", "wb");
    fwrite(&num, sizeof(num), 1, fptr);
    fclose(fptr);
    return 0;
}
```

### 3. File Positioning

File positioning functions include:
- **fseek**: Moves the file pointer to a specific location.
- **ftell**: Returns the current position of the file pointer.
- **rewind**: Moves the file pointer to the beginning of the file.

```c
#include <stdio.h>

int main() {
    FILE *fptr;
    int num;
    fptr = fopen("binaryfile.bin", "rb");
    fseek(fptr, 0, SEEK_SET);
    fread(&num, sizeof(num), 1, fptr);
    printf("Number: %d\n", num);
    fclose(fptr);
    return 0;
}
```

### 4. Command Line Arguments

You can pass arguments to your program using command line arguments:

```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        printf("Argument 1: %s\n", argv[1]);
    } else {
        printf("No arguments provided.\n");
    }
    return 0;
}
```
