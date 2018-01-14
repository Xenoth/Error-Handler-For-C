//
// Created by xenoth on 14/01/18.
//

#include "StackError.h"

void initStackError()
{
    ErrorStack.size = 0;
}

error_type top()
{
    if (ErrorStack.size == 0)
    {
        return ERR_NO_ERROR;
    }

    return ErrorStack.data[ErrorStack.size-1];
}

int push(error_type error)
{
    if (ErrorStack.size < STACK_MAX)
    {
        ErrorStack.data[ErrorStack.size++] = error;
        return 0;
    }
    return -1;
}

int pop()
{
    if (ErrorStack.size == 0)
        return -1;
    ErrorStack.size--;
    return 0;
}

struct _error_stack ErrorStack = {
        .init = initStackError,
        .top = top,
        .push = push,
        .pop = pop,
};