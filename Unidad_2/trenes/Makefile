TARGET = trenes_app

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

SOURCES = main.c $(wildcard $(SRC_DIR)/*.c)

OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run