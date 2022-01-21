#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "tic_tac_toe.h"

/* A test case that does nothing and succeeds. */
static void null_test_success(void **state) {
    (void) state; /* unused */
}

static void can_initialize_board(void **state) {
    struct Board* myTestBoard = malloc(sizeof(struct Board));
    struct Board* myUpdatedBoard = board_new(myTestBoard, 3, 3);
    
    assert_non_null(myUpdatedBoard);
    assert_ptr_equal(myUpdatedBoard, myTestBoard);
    assert_true(myUpdatedBoard->row_count == 3);
    assert_true(myUpdatedBoard->row_size == 3);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(can_initialize_board)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}