#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
va_list cart;
int i, len, count = 0;
va_start(cart, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
if (format[i] == '\0')
{
va_end(cart);
return (-1);
}
switch (format[i])
{
case 'c':
{ char c = va_arg(cart, int);
write(1, &c, 1); count++; break; }
case 's':
{ char *s = va_arg(cart, char *);
if (s == NULL) s = "(null)";
len = strlen(s); write(1, s, len); count += len; break; }
case '%':
write(1, "%", 1); count++; break;
default:
write(1, "%", 1); write(1, &format[i], 1); count += 2; break;
}
}
else
{
write(1, &format[i], 1);
count++;
}
}
va_end(cart);
return (count);
}
