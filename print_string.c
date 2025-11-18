#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * print_string - prints a string to stdout
 * @args: va_list containing the string to be printed
 * Return: number of characters printed
 */
int print_string(va_list args)
{
    char *s = va_arg(args, char *);  /* Extract string from va_list */
    int len;

    if (!s)
        s = "(null)";
    len = strlen(s);
    write(1, s, len);
    return (len);
}
