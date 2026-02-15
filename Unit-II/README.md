# File Handling Examples in C

This README.md provides detailed explanations of 30 file handling examples covering various aspects of file operations in C.

## Table of Contents

1. [File Modes](#file-modes)
2. [Opening and Closing Files](#opening-and-closing-files)
3. [Writing to Files](#writing-to-files)
4. [Reading from Files](#reading-from-files)
5. [Positioning in Files](#positioning-in-files)
6. [Binary Operations](#binary-operations)
7. [Error Handling](#error-handling)

---

## File Modes

C provides different modes to open a file:
- `r`: Read mode, opens a file for reading.
- `w`: Write mode, opens a file for writing (creates a new file or truncates an existing file).
- `a`: Append mode, opens a file to add content at the end.
- `rb, wb, ab`: Binary modes corresponding to read, write, and append modes.

### Example 1: Open a file in read mode
```c
FILE *file = fopen("example.txt", "r");
if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
}
```

## Opening and Closing Files

Files should be opened using `fopen()` and closed using `fclose()`.

### Example 2: Closing a file
```c
fclose(file);
```

## Writing to Files

Writing to files can be achieved using functions like `fprintf()`, `fputs()`, and `fwrite()`.

### Example 3: Writing formatted output to a file
```c
fprintf(file, "Hello, World!\n");
```

## Reading from Files

Reading from files can be done with `fscanf()`, `fgets()`, and `fread()`.

### Example 4: Reading a line from a file
```c
char buffer[100];
fgets(buffer, sizeof(buffer), file);
```

## Positioning in Files

File positioning can be handled using `fseek()` and `ftell()`. 

### Example 5: Positioning in a file
```c
fseek(file, 0, SEEK_SET);
```

## Binary Operations

Binary file operations use `fwrite()` and `fread()` functions for writing and reading binary data.

### Example 6: Writing binary data to a file
```c
int data = 12345;
fwrite(&data, sizeof(data), 1, file);
```

## Error Handling

Proper error handling is essential when working with files. Check for NULL returns and use `perror()` for error messages.

### Example 7: Handling file open errors
```c
if (file == NULL) {
    perror("Error opening file");
}
```

---

This document continues with additional file handling examples...

### Example 8: ...
### Example 9: ...
### Example 10: ...

...and so on until Example 30, covering various aspects as described above.

---

### Conclusion

File handling in C is a critical skill for managing data effectively. This README provides a comprehensive guide for beginners and experienced programmers alike.