#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
 * _printf - produces output according to a format
 * @format: format string
 * @i: pointer to current index in format string
 * @cart: va_list of arguments
 * Return: number of characters printed
 */
int handle_specifier(const char *format, int *i, va_list cart);
void flush(void);
int _get_total_count(void);

int _printf(const char *format, ...)
{
va_list cart;
int i, count = 0;

if (!format || (format[0] == '%' && format[1] == '\0'))
return (-1);

va_start(cart, format);

for (i = 0; format[i]; i++)
{
if (format[i] == '%')
count += handle_specifier(format, &i, cart);
else
{
count += _putchar(format[i]);
}
}
flush();
va_end(cart);
return (count);
}
/**
 * handle_specifier - handles format specifiers
 * @format: format string
 * @i: pointer to current index in format string
 * @cart: va_list of arguments
 * Return: number of characters printed for the specifier
 */

int handle_specifier(const char *format, int *i, va_list cart)
{
char c;
int count_chars =0;

(*i)++;
if (!format[*i])
return (-1);
if (format[*i] == 'c')
{
c = va_arg(cart, int);
count_chars += _putchar(c);
return (count_chars);
}
if (format[*i] == 's')
return (print_string(va_arg(cart, char *)));
if (format[*i] == '%')
{
count_chars += _putchar('%');
return (count_chars);
} 
if (format[*i] == 'b') 
        return (print_binary(va_arg(cart, unsigned int)));
 if (format[*i] == 'u')
        return (print_unsigned(cart));
    if (format[*i] == 'o')
        return (print_octal(cart));
    if (format[*i] == 'x')
        return (print_hex(cart, 0));
    if (format[*i] == 'X')
        return (print_hex(cart, 1));

_putchar('%');
_putchar(format[*i]);
return (2);
} 

