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
 
/**
 * print_binary - converts unsigned int to binary and prints it
 * @n: unsigned integer to convert
 * Return: number of characters printed
 */
    int print_binary(unsigned int n)
{
    int count = 0;
    char buffer[33];
    int i = 0;

    if (n == 0)
        return _putchar('0');

    while (n > 0)
    {
        buffer[i] = (n % 2) + '0';
        n = n / 2;
        i++;
    }

    while (i > 0)
    {
        count += _putchar(buffer[i - 1]);
        i--;
    }

    return count;
}
