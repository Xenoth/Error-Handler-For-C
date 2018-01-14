//
// Created by Xenoth on 19/12/2017.
//

#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <stdbool.h>
#include <stdio.h>

#include "ErrorEnum.h"
#include "StackError.h"

struct _error_handler {


	void (*initErrorHandler)(void);

	bool (*errorHappened)(void);

	error_type (*getLastError)(void);
	int (*setLastError)(error_type);

	void (*printErrorStack)(FILE*);
};

extern struct _error_handler Error_Handler;

#endif
