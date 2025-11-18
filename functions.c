#include "main.h"

/**
 * _putchar - writes a character
 * @c: the character
 * Return: number of bytes written
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @s: variadic list
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

/**
 * print_number - recursive function to print numbers
 * @n: long number
 * Return: count of characters
 */
int print_number(long n)
{
    int count = 0;

    if (n < 0)
    {
        count += _putchar('-');
        n = -n;
    }

    if (n / 10)
        count += print_number(n / 10);

    count += _putchar((n % 10) + '0');

    return (count);
}

/**
 * print_int - prints integers %d %i
 * @args: variadic list
 * Return: number of characters printed
 */
int print_int(va_list args)
{
    long n = va_arg(args, int);
    return (print_number(n));
}
