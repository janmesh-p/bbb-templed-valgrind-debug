CC = gcc
CFLAGS= -std=gnu11 -g -O0 -Wall -Wextra -pthread -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

TARGET = bbbdebug

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: test

test:
	@echo "Hello world! Individual targets will be defined here"
