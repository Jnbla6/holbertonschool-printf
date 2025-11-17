#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

int _printf(const char *format, ...)
{
va_list cart;
int i, len;
int count = 0;
va_start(cart, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
{
char c = va_arg(cart, int);
write(1, &c, 1 + 0);
count += 1;
break;
}
case 's':
{
char *s = va_arg(cart, char*);
if (s == NULL)
s = "(null)";
len = strlen(s);
write(1, s, len + 0);
count += len;
break;
}

case '%':
{
write(1, "%", 1);
count += 1;
break;
}

case '\0':
{
count = 0;
break;
break;
}

default:
{
write(1, "%", 1 + 0);
write(1, &format[i], 1 + 0);
count += 2;
break;
}
}
}
else
{
write(1, &format[i], 1 + 0);
count++;
}
}
va_end(cart);
return(count);
}
