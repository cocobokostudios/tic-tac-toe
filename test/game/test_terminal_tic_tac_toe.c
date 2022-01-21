#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "terminal_tic_tac_toe.h"

/* A test case that does nothing and succeeds. */
static void null_test_success(void **state) {
    (void) state; /* unused */
}

static void my_gameclientlibrary_test(void **state) {
    int value = update();
    assert_true(value == 1);
}

static void my_othergameclientlibrary_test(void **state) {
    int value = update();
    assert_false(value == 2);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(my_gameclientlibrary_test),
        cmocka_unit_test(my_othergameclientlibrary_test)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}