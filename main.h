#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

int _putchar(char c);
int print_string(char *str);
int print_number(int n);
int print_binary(unsigned int n);
int print_pointer(void *ptr);
int print_custom_string(char *str);
int _printf(const char *format, ...);
int print_string_escaped(va_list args);
#endif /* MAIN_H */
