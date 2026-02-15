# File Handling Examples in C

## Summary Table
| Example Number | Description |
|-----------------|-------------|
| 1               | Read from a file |
| 2               | Write to a file |
| 3               | Append to a file |
| 4               | Copy a file |
| 5               | Delete a file |
| 6               | Rename a file |
| 7               | Check if file exists |
| 8               | List contents of a directory |
| 9               | Open a file in binary mode |
| 10              | Read and write integers |
| 11              | Read and write strings |
| 12              | Read and write structs |
| 13              | Read lines from a file |
| 14              | Write lines to a file |
| 15              | Read a character from a file |
| 16              | Write a character to a file |
| 17              | Check file size |
| 18              | Move file pointer |
| 19              | Flush file buffers |
| 20              | Use file descriptors |
| 21              | Read file till end |
| 22              | Use fprintf for formatted output |
| 23              | Search in a file |
| 24              | Count words in a file |
| 25              | Combine multiple files |
| 26              | Read a file in chunks |
| 27              | Create a backup of a file |
| 28              | Use temporary files |
| 29              | Implement a simple text editor |
| 30              | Read from a CSV file |

## Examples

### Example 1: Read from a file
```c
#include <stdio.h>
int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    fclose(file);
    return 0;
}
```

### Example 2: Write to a file
```c
#include <stdio.h>
int main() {
    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }
    fprintf(file, "Hello, World!\n");
    fclose(file);
    return 0;
}
```

... (Add additional examples here) ...

### Example 30: Read from a CSV file
```c
#include <stdio.h>
#include <string.h>
int main() {
    FILE *file = fopen("data.csv", "r");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ", ");
        while (token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, ", ");
        }
        printf("\n");
    }
    fclose(file);
    return 0;
}
```