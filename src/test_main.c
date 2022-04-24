#include <stdio.h>
#include <stdlib.h>
#include "tests.h"

int main() {
    printf("\nProgram testuje funkcje stosu\n\n");

    testuj_top_of_funstack();
    testuj_put_on_fun_stack();
    testuj_get_from_fun_stack();

    return EXIT_SUCCESS;
}