#pragma once

typedef struct board Board;

Board* board_new(int row_size, int row_count);
Board* board_new_from_state(int row_size, int row_count, char* boardState);
void board_free(Board* b);
const char* board_get_grid(const Board* b);
int board_get_row_count(const Board* b);
int board_get_row_size(const Board* b);
int board_get_square_count(const Board* b);
char board_get_square(const Board* b, int row, int column);

// sample function
int get_one();

