//
// Created by Xenoth on 19/12/2017.
//

#include "ErrorHandler.h"

void initErrorHandler()
{
    Error_Stack.init();
}

bool errorHappened()
{
    return Error_Stack.size >= 0;
}

error_type getLastError()
{
    error_type res = Error_Stack.top();
    Error_Stack.pop();
    return res;
}

int setLastError(error_type error)
{
    return Error_Stack.push(error);
}

void printErrorStack(FILE *file)
{
    error_type current = Error_Stack.top();
    while(current != ERR_NO_ERROR)
    {
        fprintf(file, "%s\n", error_typeToString(current));
        Error_Stack.pop();
        current = Error_Stack.top();
    }
}

struct _error_handler Error_Handler = {
        .errorHappened = errorHappened,
        .getLastError = getLastError,
        .setLastError = setLastError,
        .printErrorStack = printErrorStack,
};