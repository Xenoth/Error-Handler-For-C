//
// Created by Xenoth on 19/12/2017.
//

#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <stdbool.h>
#include <stdio.h>

#include "ErrorEnum.h"
#include "StackError.h"
#include "OnErrorHappenedObservers.h"

struct _error_handler {


	void (*init)(void);

	bool (*errorHappened)(void);

	error_type (*getLastError)(void);
	int (*setLastError)(error_type);

	void (*printErrorStack)(FILE*);

	void (*addOnErrorHappenedListener)(callbackError);
};

extern struct _error_handler ErrorHandler;

#endif
