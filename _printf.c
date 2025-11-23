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
int handle_specifier(const char *format, int *i, va_list cart); /* handle specifier function to handle wih each specify*/
void flush(void); /*flush function to clean buffer*/

int _printf(const char *format, ...)
{
va_list cart; /* our list named cart to handle vardic function*/
int i, count = 0;

if (!format || (format[0] == '%' && format[1] == '\0')) /*condition to handle if theres no specify*/
    return (-1);

if (!format || (format[0] == '%' && format[1] == ' ' && format[2] == '\0')) /*condition to handle if theres no specify*/
    return (-1);


va_start(cart, format); /* start list*/

for (i = 0; format[i]; i++) /* loop to take each index*/
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
int field_width = 0;
int precision = -1;
int left_justify = 0;  /* ADD THIS LINE */

(*i)++;
if (!format[*i])
    return (-1);

/* ADD '-' TO FLAG DETECTION */
while (format[*i] == '+' || format[*i] == ' ' || format[*i] == '#' || format[*i] == '-' || format[*i] == '0')
{
if (format[*i] == '+') flags |= 1; /* flag for plus case*/
if (format[*i] == ' ') flags |= 2; /* flag for space case*/
if (format[*i] == '#') flags |= 4; /* flag for Hash case*/
if (format[*i] == '0') flags |= 8;
if (format[*i] == '-') left_justify = 1;  /* ADD THIS LINE */
(*i)++;
if (!format[*i])
break;
} 
/* Parse field width */
if (format[*i] == '*')
{
field_width = va_arg(cart, int);
if (field_width < 0)
{
field_width = -field_width;
left_justify = 1;
}
(*i)++;
}
else
{
while (format[*i] >= '0' && format[*i] <= '9')
{
field_width = field_width * 10 + (format[*i] - '0');
(*i)++;
if (!format[*i])
break;
}
}

if (format[*i] == '.')
{
precision = 0;
(*i)++;
if (format[*i] == '*')
{
precision = va_arg(cart, int);
(*i)++;
}
else
{
while (format[*i] >= '0' && format[*i] <= '9')
{
precision = precision * 10 + (format[*i] - '0');
(*i)++;
}
}
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
if (flags & 8) count_chars += _putchar('0');
if (left_justify) count_chars += _putchar('-');
return count_chars;
}
}

if (!format[*i] && flags)  
{
count_chars += _putchar('%');
if (flags & 1) count_chars += _putchar('+');
if (flags & 2) count_chars += _putchar(' ');
if (flags & 4) count_chars += _putchar('#');
if (flags & 8) count_chars += _putchar('0');
if (left_justify) count_chars += _putchar('-');
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
if (left_justify)
{
count_chars += _putchar(c);
while (field_width > 1)
{
count_chars += _putchar(' ');
field_width--;
}
}
else
{
while (field_width > 1)
{
count_chars += _putchar(' ');
field_width--;
}
count_chars += _putchar(c);
}
return (count_chars);
}
if (format[*i] == 's')
return (print_string(va_arg(cart, char*), field_width, precision, left_justify));  /* ADD left_justify */
if (format[*i] == '%')
{
count_chars += _putchar('%');
if (flags & 2)
count_chars += _putchar(' ');
return (count_chars);
} 
if (format[*i] == 'd' || format[*i] == 'i')
return (print_int(cart, flags, length, field_width, precision, left_justify));  /* ADD left_justify */
if (format[*i] == 'b') 
return (print_binary(va_arg(cart, unsigned int)));
if (format[*i] == 'u')
return (print_unsigned(cart, flags, length, field_width, precision, left_justify));  /* ADD left_justify */
if (format[*i] == 'o')
return (print_octal(cart, flags ,length, field_width, precision, left_justify));  /* ADD left_justify */
if (format[*i] == 'x')
return (print_hex(cart, 0, flags, length, field_width, precision, left_justify));  /* ADD left_justify */
if (format[*i] == 'X')
return (print_hex(cart, 1, flags, length, field_width, precision, left_justify));  /* ADD left_justify */
if (format[*i] == 'S')
return (print_string_escaped(cart));
if (format[*i] == 'p')
return (print_pointer(cart, field_width, left_justify));
if (format[*i] == 'r')
return (print_rev(cart));
if (format[*i] == 'R')
return (print_rot13(cart));

if (flags & 1)
count_chars += _putchar('+');
if (flags & 2)
count_chars += _putchar(' ');
if (flags & 4)
count_chars += _putchar('#');

count_chars += _putchar('%'); /* حل المشاكل*/
count_chars += _putchar(format[*i]);
return (count_chars);
}
