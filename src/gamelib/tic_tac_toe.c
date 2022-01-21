#include <stdlib.h>
#include "tic_tac_toe.h"

struct Board* board_new(struct Board* b, int row_size, int row_count) {
    b->board = malloc(sizeof(char) * (row_size * row_count));
    b->row_size = row_size;
    b->row_count = row_count;
    
    if(!b->board) {
        return NULL;
    }
    else {
        return b;
    }
}

int get_one() {
    return 1;
}

int get_board_size() {
    return -1;
}