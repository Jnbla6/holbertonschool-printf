#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);


/* Print functions */
int print_string(char *s);
int print_int(va_list args);
int print_binary(unsigned int n);

/* Helpers */
int _putchar(char c);
int print_number(long n);
#endif 
