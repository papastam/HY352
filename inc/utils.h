#include <stdio.h>
#include <stdarg.h>

#pragma once

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

struct TermColors{
    const char* reset = "\033[0m";
    const char* red = "\033[0;31m";
    const char* green = "\033[0;32m";
    const char* yellow = "\033[0;33m";
    const char* blue = "\033[0;34m";
    const char* magenta = "\033[0;35m";
    const char* cyan = "\033[0;36m";
    const char* white = "\033[0;37m";
    const char* bold_red = "\033[1;31m";
    const char* bold_green = "\033[1;32m";
    const char* bold_yellow = "\033[1;33m";
    const char* bold_blue = "\033[1;34m";
    const char* bold_magenta = "\033[1;35m";
    const char* bold_cyan = "\033[1;36m";
    const char* bold_white = "\033[1;37m";
    const char* bg_red = "\033[41m";
    const char* bg_green = "\033[42m";
    const char* bg_yellow = "\033[43m";
    const char* bg_blue = "\033[44m";
    const char* bg_magenta = "\033[45m";
    const char* bg_cyan = "\033[46m";
    const char* bg_white = "\033[47m";
    const char* bold = "\033[1m";
    const char* dark = "\033[2m";
    const char* italic = "\033[3m";
    const char* underline = "\033[4m";
    const char* blink = "\033[5m";
    const char* reverse = "\033[7m";
    const char* concealed = "\033[8m";
} Colors;