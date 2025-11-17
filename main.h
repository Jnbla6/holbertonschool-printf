#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/* Main printf function */
int _printf(const char *format, ...);

/* Helper functions */
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_percent(va_list args);
int print_number(long n);
int handle_specifier(const char *format, int *i, va_list cart);
int print_char(char c);
int print_string(char *s);
int print_int(va_list args, char buffer[], int *buff_ind);
int print_int_recursive(unsigned int num, char buffer[], int *buff_ind);
#endif
