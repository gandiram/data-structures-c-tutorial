# Makefile

CC = gcc
CFLAGS = -Wall -g

# Target for compiling structures
structures: structures.o test_structures.o
	$(CC) -o structures structures.o test_structures.o

# Target for compiling the structures object file
structures.o: structures.c
	$(CC) $(CFLAGS) -c structures.c

# Target for compiling the test_structures object file
 test_structures.o: test_structures.c
	$(CC) $(CFLAGS) -c test_structures.c

# Clean up the compiled files
clean:
	rm -f structures *.o
