#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

int _printf(const char *format, ...)
{ 
const char *str = format;
write(1, str, 5);
return (0);
}
