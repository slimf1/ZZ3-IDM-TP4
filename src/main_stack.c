#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

DECLARE_STACK(int)
IMPLEMENT_STACK(int)

DECLARE_STACK(double)
IMPLEMENT_STACK(double)

int main() {
    stackdouble_t stack;
    stackdouble_initialize(&stack);

    stackdouble_push(&stack, 1.1);
    stackdouble_push(&stack, 2.2);
    stackdouble_push(&stack, 3.3);
    stackdouble_push(&stack, 4.4);
    stackdouble_push(&stack, 5.5);
    stackdouble_push(&stack, 6.6);
    stackdouble_pop(&stack);

    printf("%lf \n\n", stackdouble_peek(&stack));

    for(int i = 0; i < STACK_MAX_SIZE; ++i) {
        printf("%lf \n", stack._values[i]);
    }

    return EXIT_SUCCESS;
}
