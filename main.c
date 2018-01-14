#include <stdio.h>
#include <unistd.h>

#include "lib/ErrorHandler.h"

const char *openReading = "r";

//Divide or throw an error
float divide(int arg1, int arg2)
{
    if(arg2 == 0) {
        ErrorHandler.setLastError(ERR_DIVIDE_BY_ZERO);
        return -1;
    }

    return arg1 / arg2;
}

//Open file or throw an error
FILE* openFileToRead(const char *pathfile)
{
    FILE *file = fopen(pathfile, openReading);
    if (file == NULL)
        ErrorHandler.setLastError(ERR_FILE_NOT_FOUND);

    return file;
}

void onErrorHappenedListener(error_type error)
{
    fprintf(stderr, "An error happened; CODE = %d | MESSAGE = %s\n", error, error_typeToString(error));
}

char *pathfile = "plop.txt";

int main() {

    // Initializing ErrorHandler and register our callbackError
    ErrorHandler.init();
    ErrorHandler.addOnErrorHappenedListener(onErrorHappenedListener);

    printf("Attempting to open \"%s\"...\n", pathfile);
    FILE *file = openFileToRead(pathfile);

    printf("Attempting to divide 4 by 0...\n");
    float res = divide(4, 0);



    sleep(1);
    printf("\nReading ErrorStack...\n");
    ErrorHandler.printErrorStack(stderr);

}