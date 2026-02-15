# Makefile for compiling binary_tree.c, bst.c, graph.c, test_trees_graphs.c

# Compilation rules
CC = gcc
CFLAGS = -Wall -Werror -g

# Source files
BIN_TREE_SRC = binary_tree.c
BST_SRC = bst.c
GRAPH_SRC = graph.c
TEST_SRC = test_trees_graphs.c

# Object files
BIN_TREE_OBJ = $(BIN_TREE_SRC:.c=.o)
BST_OBJ = $(BST_SRC:.c=.o)
GRAPH_OBJ = $(GRAPH_SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)

# Target executable
TARGET = test_trees_graphs

# Default target
all: $(TARGET)

$(TARGET): $(BIN_TREE_OBJ) $(BST_OBJ) $(GRAPH_OBJ) $(TEST_OBJ)
\t$(CC) $(CFLAGS) -o $@ $^

# Compile source files
%.o: %.c
\t$(CC) $(CFLAGS) -c $<

# Clean up
clean:
\trm -f $(BIN_TREE_OBJ) $(BST_OBJ) $(GRAPH_OBJ) $(TEST_OBJ) $(TARGET)

# Run the tests
run: $(TARGET)
\t./$(TARGET)