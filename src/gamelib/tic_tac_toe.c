#include <stdlib.h>
#include "tic_tac_toe.h"

struct board {
    char* boardArr;
    int row_size;
    int row_count;
};

Board* board_new(int row_size, int row_count) {
    Board* b = (Board*) malloc(sizeof(Board));

    int arraySize = row_size * row_count;
    b->boardArr = calloc(arraySize, sizeof(char));

    if(b->boardArr) {
        b->row_size = row_size;
        b->row_count = row_count;
    }

    return b;
}

void board_free(Board* b) {
    free(b->boardArr);
    free(b);
}

int get_row_count(Board* b) {
    return b->row_count;
}

int get_row_size(Board* b) {
    return b->row_size;
}

// sample function
int get_one() {
    return 1;
}
