#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "tic_tac_toe.h"

static void can_initialize_board(void **state) {
    Board* myTestBoard = board_new(3, 3);
    
    assert_non_null(myTestBoard);
}

static void can_set_row_size_and_row_count_on_init(void **state) {
    // given an initialized board
    Board* myTestBoard = board_new(3, 3);
    
    // then the row_count and row_size are set
    assert_int_equal(get_row_size(myTestBoard), 3);
    assert_int_equal(get_row_count(myTestBoard), 3);
}

static void can_free_board(void **state) {
    // given an initialized board
    Board* myTestBoard = board_new(3, 3);
    assert_non_null(myTestBoard);

    // when we free() it
    board_free(myTestBoard);

    // that's it-- we don't want errors and we want the function to exist so if it executes then it means it passed
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(can_initialize_board),
        cmocka_unit_test(can_free_board),
        cmocka_unit_test(can_set_row_size_and_row_count_on_init)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}