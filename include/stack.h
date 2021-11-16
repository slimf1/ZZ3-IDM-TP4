#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define STACK_MAX_SIZE 5

#define DECLARE_STACK(TYPE) \
typedef struct stack##TYPE { \
    TYPE _values[STACK_MAX_SIZE];\
    int _top;\
} stack##TYPE##_t; \
\
void stack##TYPE##_push(stack##TYPE##_t* stack, TYPE value); \
TYPE stack##TYPE##_pop(stack##TYPE##_t* stack); \
bool stack##TYPE##_isempty(stack##TYPE##_t* stack); \
bool stack##TYPE##_isfull(stack##TYPE##_t* stack); \
TYPE stack##TYPE##_peek(stack##TYPE##_t* stack); \
void stack##TYPE##_initialize(stack##TYPE##_t* stack); \

#define IMPLEMENT_STACK(TYPE) \
void stack##TYPE##_push(stack##TYPE##_t* stack, TYPE value) { \
    if (!stack##TYPE##_isfull(stack)) \
        stack->_values[++stack->_top] = value; \
} \
\
TYPE stack##TYPE##_pop(stack##TYPE##_t* stack) { \
    TYPE ret = 0; \
    if (!stack##TYPE##_isempty(stack)) \
        return stack->_values[stack->_top--]; \
    return ret; \
} \
\
bool stack##TYPE##_isempty(stack##TYPE##_t* stack) { \
    return stack->_top == -1; \
} \
\
bool stack##TYPE##_isfull(stack##TYPE##_t* stack) { \
    return stack->_top == STACK_MAX_SIZE - 1; \
} \
\
TYPE stack##TYPE##_peek(stack##TYPE##_t* stack) { \
    TYPE ret = 0; \
    if (!stack##TYPE##_isempty(stack)) \
        return stack->_values[stack->_top]; \
    return ret; \
} \
\
void stack##TYPE##_initialize(stack##TYPE##_t* stack) { \
    stack->_top = -1; \
} \


#endif // STACK_H
