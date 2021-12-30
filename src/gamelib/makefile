CC=gcc
CFLAGS= -Wall -std=c17

DEP_FILES = tic_tac_toe.h

OBJ_DIR = obj
OBJ_FILES = tic_tac_toe.o
OBJS = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

BIN_DIR = bin
TARGET = $(BIN_DIR)/libtictactoe.a

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(OBJ_DIR): 
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c $(DEP_FILES) | $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

all: gamelib

gamelib: $(OBJS) | $(BIN_DIR)
	ar -crs $(TARGET) $(OBJS)

.PHONY: clean

clean:
	rm -f $(OBJS) $(TARGET)
	rm -rf $(OBJ_DIR) $(BIN_DIR)