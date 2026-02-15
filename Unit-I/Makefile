# Makefile

# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Werror -g

# Source Files
SRCS = *.c

# Object Files
OBJS = $(SRCS:.c=.o)

# Executable file name
EXEC = program

# Default target
all: $(EXEC)

# Compile the program
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@

# Test target
# You can define your test logic here

# Clean target
clean:
	rm -f $(OBJS) $(EXEC)
