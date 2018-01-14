//
// Created by xenoth on 14/01/18.
//

#include "ErrorEnum.h"

char* error_typeToString(error_type error) {
    switch (error) {
        case ERR_NO_ERROR:
            return "No Error.";

            //EDIT MESSAGES HERE
        case ERR_FILE_NOT_FOUND:
            return "Error file not found.";
        case ERR_DIVIDE_BY_ZERO:
            return "Error Attempting to divide by zero.";

            // IF NO MESSAGE DEFINED
        default:
            return "Error Unknown.";
    }
}