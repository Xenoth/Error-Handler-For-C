//
// Created by Xenoth on 19/12/2017.
//

#include "ErrorHandler.h"

bool errorHappened()
{
    return Error_Handler.last_error != ERR_SUCCESS;
}

error_type getLastError()
{
    error_type res = Error_Handler.last_error;
    Error_Handler.last_error = ERR_SUCCESS;
    return res;
}

void setLastError(error_type error)
{
    Error_Handler.last_error = error;
}

struct _error_handler Error_Handler = {
        .errorHappened = errorHappened,
        .getLastError = getLastError,
        .setLastError = setLastError,
        .last_error = ERR_SUCCESS,
};