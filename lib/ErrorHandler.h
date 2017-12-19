//
// Created by Xenoth on 19/12/2017.
//

#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <stdbool.h>

#include "ErrorEnum.h"

struct _error_handler {

    error_type last_error;

    bool (*errorHappened)(void);

    error_type (*getLastError)(void);
    void (*setLastError)(error_type);

};

extern struct _error_handler Error_Handler;

#endif
