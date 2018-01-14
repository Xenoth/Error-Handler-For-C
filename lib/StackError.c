//
// Created by xenoth on 14/01/18.
//

#include "StackError.h"

void init()
{
    Error_Stack.size = 0;
}

error_type top()
{
    if (Error_Stack.size == 0)
    {
        return ERR_NO_ERROR;
    }

    return Error_Stack.data[Error_Stack.size-1];
}

int push(error_type error)
{
    if (Error_Stack.size < STACK_MAX)
    {
        Error_Stack.data[Error_Stack.size++] = error;
        return 0;
    }
    return -1;
}

int pop()
{
    if (Error_Stack.size == 0)
        return -1;
    Error_Stack.size--;
    return 0;
}

struct _error_stack Error_Stack = {
        .init = init,
        .top = top,
        .push = push,
        .pop = pop,
};