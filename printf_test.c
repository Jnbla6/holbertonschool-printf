#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
 * _printf - produces output
 * @format: format string
 * Return: chars printed
 */
int _printf(const char *format, ...)
{
va_list cart;
int i, len, count = 0;
char *s;

va_start(cart, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
if (format[i] == '\0')
return (-1);
if (format[i] == 'c')
{
char c = va_arg(cart, int);
write(1, &c, 1);
count++;
}
else if (format[i] == 's')
{
s = va_arg(cart, char *);
if (s == NULL)
s = "(null)";
len = strlen(s);
write(1, s, len);
count += len;
}
else if (format[i] == '%')
{
write(1, "%", 1);
count++;
}
else
{
write(1, "%", 1);
write(1, &format[i], 1);
count += 2;
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

int print_string(char *s)
{
int len;
if (s == NULL)
s = "(null)";
len = strlen(s);
write(1, s, len);
return (len);
}