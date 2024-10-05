# Makefile for compiling and linking the C program

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g -I.

# Source files
SRCS = main.c fork.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = forkythready

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Compile the source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean