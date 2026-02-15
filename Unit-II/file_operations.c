// file_operations.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to write data to a binary file
void writeBinaryFile(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }

    int data[] = {1, 2, 3, 4, 5};
    fwrite(data, sizeof(int), sizeof(data)/sizeof(data[0]), file);
    fclose(file);
}

// Function to read data from a binary file
void readBinaryFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file for reading");
        return;
    }

    int data[5];
    fread(data, sizeof(int), 5, file);
    fclose(file);

    printf("Data read from binary file:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

// Function to demonstrate file positioning
void filePositioning(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file for positioning");
        return;
    }

    fseek(file, 0, SEEK_END); // Move to the end of the file
    long fileSize = ftell(file); // Get the file size
    printf("File size: %ld bytes\n", fileSize);

    fseek(file, 0, SEEK_SET); // Move back to the start
    fclose(file);
}

// Function to check the status of a file
void checkFileStatus(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        printf("File is accessible.\n");
        fclose(file);
    } else {
        perror("File not accessible");
    }
}

// Function to search for a key in a list (simulating database search)
int searchInDatabase(int *data, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (data[i] == key) {
            return i; // Key found at index i
        }
    }
    return -1; // Key not found
}

int main() {
    const char *filename = "data.bin";

    writeBinaryFile(filename);
    readBinaryFile(filename);
    filePositioning(filename);
    checkFileStatus(filename);

    int data[] = {1, 2, 3, 4, 5};
    int key = 3;
    int index = searchInDatabase(data, sizeof(data)/sizeof(data[0]), key);
    if (index != -1) {
        printf("Key %d found at index %d.\n", key, index);
    } else {
        printf("Key %d not found.\n", key);
    }

    return 0;
}