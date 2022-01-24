#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "tic_tac_toe.h"

static void can_initialize_board(void **state) {
    Board* myTestBoard = board_new(3, 3);
    assert_non_null(myTestBoard);
    assert_int_equal(board_get_row_count(myTestBoard), 3);
    assert_int_equal(board_get_row_size(myTestBoard), 3);
}

static void can_initialize_board_with_existing_board_data(void **state) {
    // when we initialize a board with an existing state
    char initialBoardState[] = {'X','O','\0','\0','\0','\0','\0','\0','\0'};
    Board* myTestBoard = board_new_from_state(3, 3, initialBoardState);
    assert_non_null(myTestBoard);

    // when we get the state of the board
    const char* returnedBoard = board_get_grid(myTestBoard);

    // then it matches our initial board state
    for(int i = 0; i < 9; i++) {
        assert_true(initialBoardState[i] == returnedBoard[i]);
    }
}

static void can_free_board(void **state) {
    // given an initialized board
    Board* myTestBoard = board_new(3, 3);
    assert_non_null(myTestBoard);

    // when we free() it
    board_free(myTestBoard);

    // that's it-- we don't want errors and we want the function to exist so if it executes then it means it passed
}

static void can_get_board_grid(void **state) {
    // given an initialized board
    Board* myTestBoard = board_new(3, 3);
    assert_non_null(myTestBoard);

    // when we request the board
    const char* myTestBoardArray = board_get_grid(myTestBoard);

    // then we have a board
    assert_non_null(myTestBoardArray);
}

static void can_get_board_row_size(void **state) {
    // given an initialized board
    int expected_size = 3, row_count = 3;
    Board* myTestBoard = board_new(expected_size, row_count);
    assert_non_null(myTestBoard);

    // when we get the square count
    int actual_size = board_get_row_size(myTestBoard);

    // then it equals row_size * row_count
    assert_int_equal(expected_size, actual_size);
}

static void can_get_board_row_count(void **state) {
    // given an initialized board
    int row_size = 3, expected_count = 3;
    Board* myTestBoard = board_new(row_size, expected_count);
    assert_non_null(myTestBoard);

    // when we get the square count
    int actual_count = board_get_row_count(myTestBoard);

    // then it equals row_size * row_count
    assert_int_equal(expected_count, actual_count);
}

static void can_get_board_square_count(void **state) {
    // given an initialized board
    int row_size = 3, row_count = 3;
    Board* myTestBoard = board_new(row_size, row_count);
    assert_non_null(myTestBoard);

    // when we get the square count
    int square_count = board_get_square_count(myTestBoard);

    // then it equals row_size * row_count
    assert_int_equal(row_count * row_size, square_count);
}

static void can_get_character_on_a_square(void **state) {
    // when we initialize a board with an existing state
    char initialBoardState[] = {'X','O','\0','X','\0','\0','\0','O','\0'};
    Board* myTestBoard = board_new_from_state(3, 3, initialBoardState);
    assert_non_null(myTestBoard);

    // when get a character from a square
    char char00 = board_get_square(myTestBoard, 0, 0);
    char char01 = board_get_square(myTestBoard, 0, 1);
    char char10 = board_get_square(myTestBoard, 1, 0);
    char char21 = board_get_square(myTestBoard, 2, 1);

    // then the character appears on the board
    const char* board = board_get_grid(myTestBoard);
    assert_true(char00 == board[0]);
    assert_true(char01 == board[1]);
    assert_true(char10 == board[3]);
    assert_true(char21 == board[7]);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(can_initialize_board),
        cmocka_unit_test(can_initialize_board_with_existing_board_data),
        cmocka_unit_test(can_free_board),
        cmocka_unit_test(can_get_board_row_count),
        cmocka_unit_test(can_get_board_row_size),
        cmocka_unit_test(can_get_board_grid),
        cmocka_unit_test(can_get_board_square_count),
        cmocka_unit_test(can_get_character_on_a_square)
        
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}