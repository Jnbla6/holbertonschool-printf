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

int _printf(const char *format, ...)
{
va_list cart;
int i, count = 0;

if (!format || (format[0] == '%' && format[1] == '\0'))
return (-1);

if (!format || (format[0] == '%' && format[1] == ' ' && format[2] == '\0'))
return (-1);

va_start(cart, format);

for (i = 0; format[i]; i++)
{
if (format[i] == '%')
{
count += handle_specifier(format, &i, cart);
continue;
}

if (i > 0 && format[i] == ' ' && format[i - 1] == '%')
continue;

count += _putchar(format[i]);
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
int flags = 0;
int length = LENGTH_NONE;

(*i)++;
if (!format[*i])
return (-1);

while (format[*i] == '+' || format[*i] == ' ' || format[*i] == '#')
{
if (format[*i] == '+') flags |= 1; /* flag for plus case*/
if (format[*i] == ' ') flags |= 2; /* flag for space case*/
if (format[*i] == '#') flags |= 4; /* flag for Hash case*/
(*i)++;
if (!format[*i])
break;
} 

/* Parse length modifiers */

if (format[*i] == 'l' || format[*i] == 'h')
{
    length = (format[*i] == 'l') ? LENGTH_L : LENGTH_H;
    (*i)++;
    if (!format[*i])
    {
        count_chars += _putchar('%');
        if (flags & 1) count_chars += _putchar('+');
        if (flags & 2) count_chars += _putchar(' ');
        if (flags & 4) count_chars += _putchar('#');
        return count_chars;
    }
}

if (!format[*i] && flags)  
{
    count_chars += _putchar('%');
    if (flags & 1) count_chars += _putchar('+');
    if (flags & 2) count_chars += _putchar(' ');
    if (flags & 4) count_chars += _putchar('#');
    (*i)--;
    return count_chars;
}

if ((flags & 1) && (flags & 2)) /* if plus flag and space flag combine*/
{
/* + take plus over space */
flags &= ~2;  /* and this for remove space flag */
}

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
if (flags & 2)
count_chars += _putchar(' ');
return (count_chars);
} 
 if (format[*i] == 'd' || format[*i] == 'i')
        return (print_int(cart, flags, length));
if (format[*i] == 'b') 
        return (print_binary(va_arg(cart, unsigned int)));
 if (format[*i] == 'u')
        return (print_unsigned(cart, flags, length));
    if (format[*i] == 'o')
        return (print_octal(cart, flags ,length));
    if (format[*i] == 'x')
        return (print_hex(cart, 0, flags, length));
    if (format[*i] == 'X')
        return (print_hex(cart, 1, flags, length));
    if (format[*i] == 'S')
    return (print_string_escaped(cart));
    if (format[*i] == 'p')
    return (print_pointer(cart));

if (flags & 1)
count_chars += _putchar('+');
if (flags & 2)
count_chars += _putchar(' ');
if (flags & 4)
count_chars += _putchar('#');
count_chars += _putchar(format[*i]);
return (count_chars);
}
