#include "main.h"

/**
 * print_string - prints a string
 * @s: variadic list
 * Return: number of characters printed
 */
int print_string(char *s)
{
int len = 0;
int i;
if (!s)
s = "(null)";
for (i = 0; s[i] != '\0'; i++)
{
len += _putchar(s[i]);
}
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
int print_int(va_list args, int flags)
{
    long n = va_arg(args, int);
    int count = 0;

    /* added this to the function to handle flags to solve task 8*/
    if (n >= 0)
    {
        if (flags & 1)       /* this flag is + flag */
            count += _putchar('+');
        else if (flags & 2)  /* and this a space flag */
            count += _putchar(' ');
    }

    return (count + print_number(n));
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
int print_unsigned(va_list args, int flags)
{
    unsigned int n = va_arg(args, unsigned int);
    (void)flags; /* this becuase flags dosent change on u*/
    return (print_unsigned_number(n));
}

/**
 * print_octal - prints octal numbers
 * @args: variadic list
 * Return: number of characters printed
 */
int print_octal(va_list args, int flags)
{
    unsigned int n = va_arg(args, unsigned int);
    int count = 0;

    /* this to Handle # flag and print 0 if number is not zero */
    if ((flags & 4) && n != 0)
        count += _putchar('0');

    return (count + print_octal_number(n));
}

/**
 * print_hex - prints hexadecimal numbers
 * @args: variadic list
 * @uppercase: 1 for uppercase, 0 for lowercase
 * Return: number of characters printed
 */
int print_hex(va_list args, int uppercase, int flags)
{
    unsigned int n = va_arg(args, unsigned int);
    int count = 0;
    /* and this like the before*/
    if ((flags & 4) && n != 0)
    {
    count += _putchar('0');
    count += _putchar(uppercase ? 'X' : 'x'); /* this to handle the case*/
    }

    return (count + print_hex_number(n, uppercase));
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

/**
 * print_string_escaped - prints string with non-printable chars in hex
 * @args: variadic arguments
 * Return: number of characters printed
 */
int print_string_escaped(va_list args)
{
    char *s = va_arg(args, char *);
    int count = 0, i;
    char hex_digits[] = "0123456789ABCDEF";

    if (!s)
        s = "(null)";

    for (i = 0; s[i]; i++)
    {
        /* Check if character is non-printable */
        if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
        {
            count += _putchar('\\');
            count += _putchar('x');
            count += _putchar(hex_digits[(unsigned char)s[i] / 16]);
            count += _putchar(hex_digits[(unsigned char)s[i] % 16]);
        }
        else
        {
            count += _putchar(s[i]);
        }
    }
    return (count);
}

/**
 * print_pointer - prints pointer address
 * @args: variadic arguments
 * Return: number of characters printed
 */
int print_pointer(va_list args)
{
    void *ptr = va_arg(args, void *);
    unsigned long address;
    char buffer[20];
    int i = 0, count = 0;
    char hex_digits[] = "0123456789abcdef";

    if (ptr == NULL)
    {
        count += _putchar('(');
        count += _putchar('n');
        count += _putchar('i');
        count += _putchar('l');
        count += _putchar(')');
        return (count);
    }

    address = (unsigned long)ptr;

    /* Print "0x" prefix using _putchar */
    count += _putchar('0');
    count += _putchar('x');

    /* Handle zero address */
    if (address == 0)
    {
        count += _putchar('0');
        return (count);
    }

    /* Build hexadecimal string in reverse */
    while (address > 0)
    {
        buffer[i++] = hex_digits[address % 16];
        address /= 16;
    }

    /* Print in correct order (reverse) using _putchar */
    while (i > 0)
    {
        count += _putchar(buffer[--i]);
    }

    return (count);
}