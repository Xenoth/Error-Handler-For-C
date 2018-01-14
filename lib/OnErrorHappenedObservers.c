//
// Created by xenoth on 14/01/18.
//

#include <printf.h>
#include <stdio.h>
#include "OnErrorHappenedObservers.h"

void initObservers()
{
    OnErrorHappenedObservers.size = 0;
}

int registerObserver(callbackError ptr_reg_callback_error)
{
    if(OnErrorHappenedObservers.size <= OBSERVERS_MAX)
    {
        OnErrorHappenedObservers.observers[OnErrorHappenedObservers.size] = ptr_reg_callback_error;
        OnErrorHappenedObservers.size++;
    }
    else
        return -1;

    return 0;
}

void notifyObservers(error_type error)
{
    for(int i = 0; i < OnErrorHappenedObservers.size; i++)
    {
        (*OnErrorHappenedObservers.observers[i])(error);
    }
}

struct _on_error_happened_observers OnErrorHappenedObservers = {
        .init = initObservers,
        .registerObserver = registerObserver,
        .notifyObservers = notifyObservers,
};