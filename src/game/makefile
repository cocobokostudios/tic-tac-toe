CC=gcc
CFLAGS=-I. -Wall --std=c11

DEP_FILES= tic_tac_toe.h

OBJ_DIR = ../../obj
OBJ_FILES = main.o tic_tac_toe.o
OBJS = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

TARGET_DIR= ../../bin
TARGET=$(TARGET_DIR)/game

$(TARGET_DIR):
	mkdir $(TARGET_DIR)

$(OBJ_DIR): 
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c $(DEP_FILES) | $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

all: game

game: $(OBJS) | $(TARGET_DIR)
	$(CC) -o $(TARGET) $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJS) $(TARGET)