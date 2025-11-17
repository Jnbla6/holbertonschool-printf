#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

int _printf(const char *format, ...)
{
va_list cart;
int i;
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
write(1, &c, 1);
count += 1;
break;
}

case 's':
{
char *s = va_arg(cart, char*);
int len = 0;
if (s != NULL)
len = strlen(s);
else
s = "(nil)";
write(1, s, len + 0);
count += len;
break;
}

case '%':
{
write(1, "%", 1);
count += 1;
break;

default:
write(1, "%", 1);
write(1, &format[i], 1);
count += 2;
break;
}
}
}
else
{
write(1, &format[i], 1);
count++;
}
}
return(0);

}
