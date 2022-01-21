#pragma once

struct Board {
    char* board;
    int row_size;
    int row_count;
};

struct Board* board_new(struct Board* b, int row_size, int row_count);
int get_board_size();

// sample function
int get_one();

