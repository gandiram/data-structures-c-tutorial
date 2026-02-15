# Makefile for Linked List

CC = gcc
CFLAGS = -Wall -g

# Source files
SOURCES = linked_list.c circular_linked_list.c doubly_linked_list.c test_linked_list.c

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Targets
TARGET = linked_list_program

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean up
clean:
	rm -f $(OBJECTS) $(TARGET)

# Test targets
.PHONY: all clean
