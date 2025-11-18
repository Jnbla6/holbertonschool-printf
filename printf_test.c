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
write(1, &format[i], 1);
count++;
}
}
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
(*i)++;
if (!format[*i])
return (-1);
if (format[*i] == 'c')
return (print_char(cart));
if (format[*i] == 's')
return (print_string(cart));
if (format[*i] == '%')
return (print_percent(cart));
if (format[*i] == 'd' || format[*i] == 'i')
return (print_int(cart));
write(1, "%", 1);
write(1, &format[*i], 1);
return (2);
}
