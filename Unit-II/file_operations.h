// file_operations.h

#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

// Function prototypes for file operations
void openFile(const char *filename);
void closeFile();
void readFile(const char *filename);
void writeFile(const char *filename, const char *data);

// Function prototypes for binary file handling
void openBinaryFile(const char *filename);
void closeBinaryFile();
void readBinaryFile(const char *filename);
void writeBinaryFile(const char *filename, const void *data, size_t dataSize);

// Function prototypes for database operations
void connectToDatabase(const char *databaseName);
void closeDatabaseConnection();
void executeQuery(const char *query);
void fetchResults();

#endif // FILE_OPERATIONS_H
