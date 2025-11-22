#include "main.h"
#include <limits.h>

/**
 * print_string - prints a string with field width
 * @s: string to print
 * @width: field width
 * Return: number of characters printed
 */
int print_string(char *s, int width)
{
	int len = 0;
	int i;
	int count = 0;

	if (!s)
		s = "(null)";

	for (len = 0; s[len] != '\0'; len++)
		;

	while (width > len)
	{
		count += _putchar(' ');
		width--;
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		count += _putchar(s[i]);
	}
	return (count);
}

/**
 * print_number - iterative function to print numbers (legacy helper)
 * @n: long number
 * Return: count of characters
 */
int print_number(long n)
{
	int count = 0;
	char buffer[21];
	int i = 0;
	unsigned long num;

	if (n < 0)
	{
		count += _putchar('-');
		if (n == LONG_MIN)
			num = (unsigned long)LONG_MAX + 1;
		else
			num = (unsigned long)(-n);
	}
	else
	{
		num = (unsigned long)n;
	}

	if (num == 0)
		return count + _putchar('0');

	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}

	while (i > 0)
		count += _putchar(buffer[--i]);

	return count;
}

/**
 * print_int - prints integers %d %i with width
 * @args: variadic list
 * @flags: flags
 * @length: length modifier
 * @width: field width
 * Return: number of characters printed
 */
int print_int(va_list args, int flags, int length, int width)
{
	long n;
	unsigned long num;
	int count = 0;
	int len = 0;
	int sign_char = 0; /* 0: none, 1: +, 2: space, 3: - */
	unsigned long temp;

	/* Handle different length modifiers */
	if (length == LENGTH_L)
		n = va_arg(args, long);
	else if (length == LENGTH_H)
		n = (short)va_arg(args, int);
	else
		n = va_arg(args, int);

	/* Determine sign and absolute value */
	if (n < 0)
	{
		sign_char = 3;
		num = (n == LONG_MIN) ? ((unsigned long)LONG_MAX + 1) : (unsigned long)(-n);
	}
	else
	{
		num = (unsigned long)n;
		if (flags & 1) sign_char = 1;
		else if (flags & 2) sign_char = 2;
	}

	/* Calculate number length */
	temp = num;
	len = (temp == 0) ? 1 : 0;
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}

	/* Add sign length */
	if (sign_char != 0)
		len++;

	/* Print padding */
	while (width > len)
	{
		count += _putchar(' ');
		width--;
	}

	/* Print sign */
	if (sign_char == 3) count += _putchar('-');
	else if (sign_char == 1) count += _putchar('+');
	else if (sign_char == 2) count += _putchar(' ');

	/* Print number */
	count += print_unsigned_number(num);

	return (count);
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
 * print_unsigned - prints unsigned integers with width
 * @args: variadic list
 * @flags: format flags
 * @length: length modifier
 * @width: field width
 * Return: number of characters printed
 */
int print_unsigned(va_list args, int flags, int length, int width)
{
	unsigned long n;
	unsigned long temp;
	int len = 0;
	int count = 0;

	if (length == LENGTH_L)
		n = va_arg(args, unsigned long);
	else if (length == LENGTH_H)
		n = (unsigned short)va_arg(args, unsigned int);
	else
		n = va_arg(args, unsigned int);

	(void)flags;

	/* Calculate length */
	temp = n;
	len = (temp == 0) ? 1 : 0;
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}

	/* Print padding */
	while (width > len)
	{
		count += _putchar(' ');
		width--;
	}

	count += print_unsigned_number(n);
	return (count);
}

/**
 * print_octal - prints octal numbers with width
 * @args: variadic list
 * @flags: format flags
 * @length: length modifier
 * @width: field width
 * Return: number of characters printed
 */
int print_octal(va_list args, int flags, int length, int width)
{
	unsigned long n;
	unsigned long temp;
	int len = 0;
	int count = 0;
	int prefix = 0;

	if (length == LENGTH_L)
		n = va_arg(args, unsigned long);
	else if (length == LENGTH_H)
		n = (unsigned short)va_arg(args, unsigned int);
	else
		n = va_arg(args, unsigned int);

	/* Check for prefix (# flag) */
	if ((flags & 4) && n != 0)
		prefix = 1;

	/* Calculate length */
	temp = n;
	len = (temp == 0) ? 1 : 0;
	while (temp > 0)
	{
		temp /= 8;
		len++;
	}
	len += prefix;

	/* Print padding */
	while (width > len)
	{
		count += _putchar(' ');
		width--;
	}

	if (prefix)
		count += _putchar('0');

	count += print_octal_number(n);
	return (count);
}

/**
 * print_hex - prints hexadecimal numbers with width
 * @args: variadic list
 * @uppercase: 1 for uppercase, 0 for lowercase
 * @flags: format flags
 * @length: length modifier
 * @width: field width
 * Return: number of characters printed
 */
int print_hex(va_list args, int uppercase, int flags, int length, int width)
{
	unsigned long n;
	unsigned long temp;
	int len = 0;
	int count = 0;
	int prefix = 0;

	if (length == LENGTH_L)
		n = va_arg(args, unsigned long);
	else if (length == LENGTH_H)
		n = (unsigned short)va_arg(args, unsigned int);
	else
		n = va_arg(args, unsigned int);

	/* Check for prefix (# flag) */
	if ((flags & 4) && n != 0)
		prefix = 2; /* 0x or 0X */

	/* Calculate length */
	temp = n;
	len = (temp == 0) ? 1 : 0;
	while (temp > 0)
	{
		temp /= 16;
		len++;
	}
	len += prefix;

	/* Print padding */
	while (width > len)
	{
		count += _putchar(' ');
		width--;
	}

	if (prefix)
	{
		count += _putchar('0');
		count += _putchar(uppercase ? 'X' : 'x');
	}

	count += print_hex_number(n, uppercase);
	return (count);
}

/**
 * print_unsigned_number - iterative function for unsigned numbers
 * @n: unsigned long number
 * Return: count of characters
 */
int print_unsigned_number(unsigned long n)
{
	int count = 0;
	char buffer[21];
	int i = 0;

	if (n == 0)
		return _putchar('0');

	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}

	while (i > 0)
		count += _putchar(buffer[--i]);

	return count;
}

/**
 * print_octal_number - converts to octal and prints
 * @n: unsigned long integer
 * Return: number of characters printed
 */
int print_octal_number(unsigned long n)
{
	int count = 0;
	char buffer[23];
	int i = 0;

	if (n == 0)
		return _putchar('0');

	while (n > 0)
	{
		buffer[i++] = (n % 8) + '0';
		n = n / 8;
	}

	while (i > 0)
		count += _putchar(buffer[--i]);
	return count;
}

/**
 * print_hex_number - converts to hex and prints
 * @n: unsigned long integer
 * @uppercase: 1 for uppercase, 0 for lowercase
 * Return: number of characters printed
 */
int print_hex_number(unsigned long n, int uppercase)
{
	int count = 0;
	char buffer[17];
	int i = 0;
	char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n == 0)
		return _putchar('0');

	while (n > 0)
	{
		buffer[i++] = digits[n % 16];
		n = n / 16;
	}

	while (i > 0)
		count += _putchar(buffer[--i]);
	return count;
}

/**
 * print_string_escaped - prints string with non-printable chars
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
 * print_pointer - prints pointer address with width
 * @args: variadic arguments
 * @width: field width
 * Return: number of characters printed
 */
int print_pointer(va_list args, int width)
{
	void *ptr = va_arg(args, void *);
	unsigned long address;
	char buffer[20];
	int i = 0, count = 0, len = 0;
	char hex_digits[] = "0123456789abcdef";

	if (ptr == NULL)
	{
		char *s = "(nil)";
		return print_string(s, width);
	}

	address = (unsigned long)ptr;
	
	/* Calculate length */
	len = 2; /* "0x" */
	if (address == 0) len++;
	else
	{
		unsigned long temp = address;
		while (temp > 0)
		{
			temp /= 16;
			len++;
		}
	}

	/* Print padding */
	while (width > len)
	{
		count += _putchar(' ');
		width--;
	}

	count += _putchar('0');
	count += _putchar('x');

	if (address == 0)
	{
		count += _putchar('0');
		return (count);
	}

	while (address > 0)
	{
		buffer[i++] = hex_digits[address % 16];
		address /= 16;
	}

	while (i > 0)
		count += _putchar(buffer[--i]);

	return (count);
}
