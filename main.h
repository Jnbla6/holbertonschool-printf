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
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args, int uppercase);
int print_unsigned_number(unsigned int n);
int print_octal_number(unsigned int n);
int print_hex_number(unsigned int n, int uppercase);
/* Helpers */
int _putchar(char c);
int print_number(long n);

int _buffer_char(char c, char *buffer, int *buf_index, int *total_count);
void _flush_buffer(char *buffer, int *buf_index, int *total_count);
#endif 
