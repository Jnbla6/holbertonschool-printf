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
/**
 * print_unsigned - prints unsigned integers
 * @args: variadic list
 * Return: number of characters printed
 */
int print_unsigned(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    return (print_unsigned_number(n));
}

/**
 * print_octal - prints octal numbers
 * @args: variadic list
 * Return: number of characters printed
 */
int print_octal(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    return (print_octal_number(n));
}

/**
 * print_hex - prints hexadecimal numbers
 * @args: variadic list
 * @uppercase: 1 for uppercase, 0 for lowercase
 * Return: number of characters printed
 */
int print_hex(va_list args, int uppercase)
{
    unsigned int n = va_arg(args, unsigned int);
    return (print_hex_number(n, uppercase));
}

/**
 * print_unsigned_number - recursive function for unsigned numbers
 * @n: unsigned number
 * Return: count of characters
 */
int print_unsigned_number(unsigned int n)
{
    int count = 0;

    if (n / 10)
        count += print_unsigned_number(n / 10);

    count += _putchar((n % 10) + '0');
    return (count);
}

/**
 * print_octal_number - converts to octal and prints
 * @n: unsigned integer
 * Return: number of characters printed
 */
int print_octal_number(unsigned int n)
{
    int count = 0;
    char buffer[12];
    int i = 0;

    if (n == 0)
        return _putchar('0');

    while (n > 0)
    {
        buffer[i] = (n % 8) + '0';
        n = n / 8;
        i++;
    }

    while (i > 0)
    {
        count += _putchar(buffer[i - 1]);
        i--;
    }
    return count;
}

/**
 * print_hex_number - converts to hex and prints
 * @n: unsigned integer
 * @uppercase: 1 for uppercase, 0 for lowercase
 * Return: number of characters printed
 */
int print_hex_number(unsigned int n, int uppercase)
{
    int count = 0;
    char buffer[9];
    int i = 0;
    char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n == 0)
        return _putchar('0');

    while (n > 0)
    {
        buffer[i] = digits[n % 16];
        n = n / 16;
        i++;
    }

    while (i > 0)
    {
        count += _putchar(buffer[i - 1]);
        i--;
    }
    return count;
}
