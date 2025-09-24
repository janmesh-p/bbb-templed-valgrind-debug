CC = gcc
CFLAGS= -std=gnu11 -g -O0 -Wall -Wextra -pthread -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

TARGET = bbbdebug
TEST_TARGET=test_runner

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: src/test_runner.o $(filter-out src/main.o, $(OBJ))
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $^
	@echo "=== Running tests under VALGRIND==="
	valgrind --leak-check=full --show-leak-kinds=all ./$(TEST_TARGET)

clean:
	rm -f $(OBJ) $(TARGET) $(TEST_TARGET) src/test_runner.o

.PHONY: all clean test

