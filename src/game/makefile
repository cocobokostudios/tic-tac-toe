CC=gcc
CFLAGS= -Wall -std=c11

DEP_FILES= tic_tac_toe.h

GAMELIB_HOME = ../gamelib
GAMELIB_BIN = $(addprefix $(GAMELIB_HOME),/bin)

OBJ_DIR = obj
OBJ_FILES = main.o
OBJS = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

LIB_DIRS = -L$(GAMELIB_BIN)
LIBS = -ltictactoe


TARGET_DIR= bin
TARGET=$(TARGET_DIR)/game

$(TARGET_DIR):
	mkdir $(TARGET_DIR)

$(OBJ_DIR): 
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) -c $^ -o $@  $(CFLAGS) -I $(GAMELIB_HOME)

all: game

game: $(OBJS) | $(TARGET_DIR)
	$(CC) $^ -o $(TARGET) $(CFLAGS) $(LIB_DIRS) $(LIBS)

.PHONY: clean

clean:
	rm -rf $(OBJ_DIR) $(TARGET_DIR)