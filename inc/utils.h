#include <stdio.h>
#include <stdarg.h>

// info print function with variadic arguments
void info(const char* format, ...){
    va_list args;
    va_start(args, format);
    printf("INFO: ");
    vprintf(format, args);
    printf("\n");
    va_end(args);
}

void error(const char* format, ...){
    va_list args;
    va_start(args, format);
    printf("ERROR: ");
    vprintf(format, args);
    printf("\n");
    va_end(args);
}