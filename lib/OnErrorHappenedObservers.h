//
// Created by xenoth on 14/01/18.
//

#ifndef ONERRORHAPPENEDOBSERVERS_H
#define ONERRORHAPPENEDOBSERVERS_H

#include "ErrorEnum.h"

#define OBSERVERS_MAX 100

typedef void (*callbackError)(error_type);

struct _on_error_happened_observers {

    callbackError observers[OBSERVERS_MAX];
    int size;

    void (*init)(void);
    int (*registerObserver)(callbackError);
    void (*notifyObservers)(error_type);
};

extern struct _on_error_happened_observers OnErrorHappenedObservers;

#endif
