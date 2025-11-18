#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024
int _printf(const char *format, ...);


/* Print functions */
int print_string(char *s);
int print_int(va_list args);
int print_binary(unsigned int n);

/* Conversion handlers */
int handle_conversion(const char **format, va_list args);
int handle_long(const char **format, va_list args);
int handle_short(const char **format, va_list args);

int print_char(va_list args);
int print_percent(va_list args);
int print_unsigned(va_list args, int base, int uppercase);





/* Helpers */
int _putchar(char c);
int print_number(long n);
int print_number_base(unsigned long n, int base, int uppercase);
#endif 
