#include <stdlib.h>
#include <string.h>

#include "tic_tac_toe.h"

struct board {
    char* boardArr;
    int row_size;
    int row_count;
};

Board* board_new(int row_size, int row_count) {
    Board* b = malloc(sizeof(Board));

    if(b) {
        int arraySize = row_size * row_count;
        b->boardArr = malloc(arraySize * sizeof(char));

        if(b->boardArr) {
            b->row_size = row_size;
            b->row_count = row_count;
        }
        else {
            // array malloc failed, so free board and set pointer to NULL
            free(b);
            b = NULL;
        }
    }

    return b;
}

Board* board_new_from_state(int row_size, int row_count, char* boardState) {
    // initialize empty board
    Board* b = board_new(row_size, row_count);

    if(b) {
        memcpy(b->boardArr, boardState, sizeof(char) * row_size * row_count);
    }

    return b;
}

void board_free(Board* b) {
    if(b) {
        // zero out members
        b->row_count = 0;
        b->row_size = 0;
        // free allocated memory
        free(b->boardArr);
    }
    free(b);
}

int board_get_row_count(const Board* b) {
    return b->row_count;
}

int board_get_row_size(const Board* b) {
    return b->row_size;
}

const char* board_get_grid(const Board* b) {
    return b->boardArr;
}

int board_get_square_count(const Board* b) {
    return b->row_count * b->row_size;
}

char board_get_square(const Board* b, int row, int column) {
    int index = row * b->row_size + column;
    return b->boardArr[index];
}

// sample function
int get_one() {
    return 1;
}
