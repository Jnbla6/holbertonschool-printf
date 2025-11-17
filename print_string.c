#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int print_string(char *s)
{
int len;

if (!s)
s = "(null)";
len = strlen(s);
write(1, s, len);
return (len);
}