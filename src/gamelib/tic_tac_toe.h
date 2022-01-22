#pragma once

typedef struct board Board;

Board* board_new(int row_size, int row_count);
void board_free(Board* b);
int get_row_count(Board* b);
int get_row_size(Board* b);

// sample function
int get_one();

