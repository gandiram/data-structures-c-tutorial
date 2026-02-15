# Makefile

# Variables
CC = gcc
CFLAGS = -Wall

# Targets
all: build

build: unit1 unit2 unit3
	$(CC) $(CFLAGS) unit1.c -o unit1
	$(CC) $(CFLAGS) unit2.c -o unit2
	$(CC) $(CFLAGS) unit3.c -o unit3

run_tests: test1 test2
	./test1
	./test2

.PHONY: all build run_tests