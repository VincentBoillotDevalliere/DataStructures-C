CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -std=c99 -O2

# Object files
OBJS = main.o hashmap.o

# Binary name
BIN = main

# Default rule
all: $(BIN)

# Compile the binary
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

# Compile the object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleanup
clean:
	rm -f $(BIN) $(OBJS)
