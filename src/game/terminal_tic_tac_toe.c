#include <stdio.h>

#include "tic_tac_toe.h"
#include "terminal_tic_tac_toe.h"

int update() {
    int funcValue = get_one();
    printf("You got a value of %d from a library.\n\n", funcValue);
    return 1;
}