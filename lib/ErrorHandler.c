//
// Created by Xenoth on 19/12/2017.
//

#include "ErrorHandler.h"

void initErrorHandler()
{
    ErrorStack.init();
    OnErrorHappenedObservers.init();
}

bool errorHappened()
{
    return ErrorStack.size >= 0;
}

error_type getLastError()
{
    error_type res = ErrorStack.top();
    ErrorStack.pop();
    return res;
}

int setLastError(error_type error)
{
    OnErrorHappenedObservers.notifyObservers(error);
    return ErrorStack.push(error);
}

void printErrorStack(FILE *file)
{
    error_type current = ErrorStack.top();
    while(current != ERR_NO_ERROR)
    {
        fprintf(file, "%s\n", error_typeToString(current));
        ErrorStack.pop();
        current = ErrorStack.top();
    }
}

void addOnErrorHappenedListener(callbackError ptr_callback_error)
{
    OnErrorHappenedObservers.registerObserver(ptr_callback_error);
}

struct _error_handler ErrorHandler = {
        .init = initErrorHandler,
        .errorHappened = errorHappened,
        .getLastError = getLastError,
        .setLastError = setLastError,
        .printErrorStack = printErrorStack,
        .addOnErrorHappenedListener = addOnErrorHappenedListener
};