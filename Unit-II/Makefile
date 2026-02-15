# Makefile

CC = gcc
CFLAGS = -Wall -g

# Targets

all: file_operations test_file_operations

file_operations: file_operations.c
	$(CC) $(CFLAGS) -o file_operations file_operations.c

test_file_operations: test_file_operations.c
	$(CC) $(CFLAGS) -o test_file_operations test_file_operations.c

clean:
	rm -f file_operations test_file_operations