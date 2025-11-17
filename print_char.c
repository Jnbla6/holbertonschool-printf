#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int print_char(char c)
{
write(1, &c, 1);
return (1);
}