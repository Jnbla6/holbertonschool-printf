#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int _printf(const char *format, ...);

/* Print functions */
int print_string(char *s);
int print_int(va_list args, int flags, int length);
int print_binary(unsigned int n);
int print_unsigned(va_list args, int flags, int length);
int print_octal(va_list args, int flags, int length);
int print_hex(va_list args, int uppercase, int flags, int length);
int print_unsigned_number(unsigned long n);
int print_octal_number(unsigned int n);
int print_hex_number(unsigned int n, int uppercase);
int print_string_escaped(va_list args);
int print_pointer(va_list args);

/* Helpers */
int _putchar(char c);
int print_number(long n);

/*buffer handel*/
void flush(void);
int buffer_char(char c);

/* Length modifier constants */
#define LENGTH_NONE 0
#define LENGTH_L 1
#define LENGTH_H 2

#endif
