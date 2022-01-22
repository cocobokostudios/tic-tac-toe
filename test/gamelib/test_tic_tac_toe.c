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

static void set_board_pointe_to_null_after_free(void **state) {
    // given an initialized board
    Board* myTestBoard = board_new(3, 3);
    assert_non_null(myTestBoard);

    // when it is freed
    board_free(myTestBoard);

    // then the pointer is NULL
    assert_null(myTestBoard);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(can_initialize_board),
        cmocka_unit_test(set_board_pointe_to_null_after_free),
        cmocka_unit_test(can_set_row_size_and_row_count_on_init)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}