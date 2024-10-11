CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c11
SRC = src
BUILD = build
OBJ = $(BUILD)/objects
BIN = $(BUILD)/executables

SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(SOURCES:$(SRC)/%.c=$(OBJ)/%.o)

all: directories $(BIN)/text_parser run

directories:
	@mkdir -p $(BUILD) $(OBJ) $(BIN)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN)/text_parser: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(BUILD)

run:
	./$(BIN)/text_parser

.PHONY: all directories clean run
