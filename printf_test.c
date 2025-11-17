#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

int _printf(const char *format, ...)
{
int leng = strlen(format);
const char *str = format;
write(1, str, leng + 1);
return(leng);
}
