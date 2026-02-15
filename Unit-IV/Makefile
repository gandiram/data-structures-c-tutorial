# Makefile

CC = gcc
CFLAGS = -Wall -g

# Source files
SRC = stack.c infix_postfix.c queue.c test_stack_queue.c

# Object files
OBJ = $(SRC:.c=.o)

# Executable file
TARGET = program

# Rule to compile and build the program
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to clean up the files
clean:
	rm -f $(OBJ) $(TARGET)

# Targets for each individual test
test_stack:
	$(CC) $(CFLAGS) -o test_stack stack.c test_stack_queue.c

test_queue:
	$(CC) $(CFLAGS) -o test_queue queue.c test_stack_queue.c

# Pattern rule for compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@