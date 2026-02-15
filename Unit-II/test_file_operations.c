# Test File Operations

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_file_operations() {
    FILE *file;
    file = fopen("test.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "This is a test file.");
    fclose(file);

    file = fopen("test.txt", "r");
    char buffer[255];
    fgets(buffer, 255, file);
    printf("File content: %s\n", buffer);
    fclose(file);
}

void test_binary_file_handling() {
    FILE *file;
    int numbers[5] = {1, 2, 3, 4, 5};
    file = fopen("numbers.bin", "wb");
    fwrite(numbers, sizeof(int), 5, file);
    fclose(file);

    int read_numbers[5];
    file = fopen("numbers.bin", "rb");
    fread(read_numbers, sizeof(int), 5, file);
    for (int i = 0; i < 5; i++) {
        printf("Number %d: %d\n", i, read_numbers[i]);
    }
    fclose(file);
}

void test_command_line_arguments(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }
}

int main(int argc, char *argv[]) {
    test_file_operations();
    test_binary_file_handling();
    test_command_line_arguments(argc, argv);
    return 0;
}