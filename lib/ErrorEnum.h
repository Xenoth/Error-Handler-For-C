#ifndef ERRORS_H
#define ERRORS_H

#include <stddef.h>

/* Error type for API */
enum _error
{
    // INTERNAL USE - DON'T EDIT
    ERR_NO_ERROR = 0,

    // EDIT YOUR ERRORS HERE
    ERR_FILE_NOT_FOUND = -1,
    ERR_DIVIDE_BY_ZERO = -2,
};

typedef enum _error error_type;

char* error_typeToString(error_type error);

#endif
