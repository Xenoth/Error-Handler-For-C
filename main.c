#include <stdio.h>

#include "lib/ErrorHandler.h"

const char *openReading = "r";

float divide(int arg1, int arg2)
{
    if(arg2 == 0) {
        Error_Handler.setLastError(ERR_DIVIDE_BY_ZERO);
        return -1;
    }

    return arg1 / arg2;
}

FILE* openFileToRead(const char *pathfile)
{
    FILE *file = fopen(pathfile, openReading);
    if (file == NULL)
        Error_Handler.setLastError(ERR_FILE_NOT_FOUND);

    return file;
}

char *pathfile = "plop.txt";

int main() {

    printf("Attempting to open \"%s\"...\n", pathfile);
    FILE *file = openFileToRead(pathfile);

    printf("Attempting to divide 4 by 0...\n");
    float res = divide(4, 0);

    if(Error_Handler.errorHappened)
        Error_Handler.printErrorStack(stderr);

}