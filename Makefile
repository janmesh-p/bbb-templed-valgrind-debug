CC = gcc
CFLAGS= -std=gnu11 -g -O0 -Wall -Wextra -pthread -Iinclude
CROSS_COMPILE= arm-linux-gnueabihf-
CC_BBB= $(CROSS_COMPILE)gcc

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

TARGET = bbbdebug
TEST_TARGET=test_runner
TESTS= tests/test_linked_list.o tests/test_state_machine.o tests/test_led_controller.o tests/test_runner.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TESTS) $(filter-out src/main.o, $(OBJ))
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $^
	@echo "=== Running tests under VALGRIND==="
	valgrind --leak-check=full --show-leak-kinds=all ./$(TEST_TARGET)

bbb: CC=$(CC_BBB)
bbb: clean $(OBJ)
	$(CC) $(CFLAGS) -o bbb_debug $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET) $(TEST_TARGET) src/test_runner.o

.PHONY: all clean test

