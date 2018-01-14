#ifndef STACK_ERROR
#define STACK_ERROR

#include "ErrorEnum.h"

#define STACK_MAX 100

struct _error_stack {

	error_type data[STACK_MAX];
	int size;

	void (*init)(void);
	error_type (*top)(void);
	int (*push)(error_type);
	int (*pop)(void);

};

extern struct _error_stack Error_Stack;

#endif
