# Output binary name
ALL = print

# Source files
SRC = Main.c printf.c helper.c

# Object files (replace .c with .o)
OBJ = $(SRC:.c=.o)

# Compiler
CC = gcc

# Flags (change -O0 to -O2 or -Wall if you want)
CFLAGS = -O0

# Default target
all: $(ALL)

# Link step: build the final binary
$(ALL): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(ALL) *.o

