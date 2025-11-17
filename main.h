#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
int handle_specifier(const char *format, int *i, va_list cart);
int print_char(char c);
int print_string(char *s);

#endif