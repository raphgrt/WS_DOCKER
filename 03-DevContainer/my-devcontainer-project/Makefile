CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
SRC = src/main.c
OBJ = $(SRC:.c=.o)
EXEC = myapp

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean