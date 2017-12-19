# Error Handler For C
## Description
This tiny little lib is designed to help managing errors for my C codes.

It has a little main example.
## Requirements
* cmake
* gcc
## How to Use
First Edit ErrorEnum.h enumeration, you must not edit ERR_SUCCESS as it's used by Error_Handler.

1. Your functions can set the last error_type using "Error_Handler.setLastError(error_type)"
2. You can check if something is wrong by using "Error_Handler.errorHappened()"
3. If so you can get the last error_type with "Error_Handler.getLastError()"

## Improvements
Using a Stack of error_type instead of a single error_type

# Authors
* BAILLEUX Pol (Xenoth) 
