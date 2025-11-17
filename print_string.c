#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
 * print_string - prints a string to stdout
 * @s: string to be printed
 * Return: number of characters printed
 */
int print_string(char *s)
{
int len;

if (!s)
s = "(null)";
len = strlen(s);
write(1, s, len);
return (len);
}
