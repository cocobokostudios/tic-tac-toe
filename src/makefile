BIN_DIR = ../bin
OBJ_DIR = ../obj

all:
	cd gamelib ; make all
	cd game ; make all


.PHONY: clean
clean:
	cd game ; make clean
	cd gamelib ; make clean
	rm -rf $(OBJ_DIR) $(BIN_DIR)