#include "main.h"
#include <limits.h>

/**
 * print_string - prints a string with width and precision
 * @s: string to print
 * @width: field width
 * @precision: max characters to print (-1 for unlimited)
 * @left_justify: whether to left justify
 * Return: number of characters printed
 */
int print_string(char *s, int width, int precision, int left_justify)
{
	int len = 0;
	int i;
	int count = 0;
	int padding;

	if (!s)
		s = "(null)";

	for (len = 0; s[len] != '\0'; len++)
		;

	if (precision >= 0 && precision < len)
		len = precision;

	padding = width - len;

	/* LEFT JUSTIFICATION: content first, then padding */
	if (left_justify)
	{
		/* Print content first */
		for (i = 0; i < len; i++)
		{
			count += _putchar(s[i]);
		}
		/* Then padding */
		while (padding > 0)
		{
			count += _putchar(' ');
			padding--;
		}
	}
	else
	{
		/* RIGHT JUSTIFICATION: padding first, then content */
		while (padding > 0)
		{
			count += _putchar(' ');
			padding--;
		}
		/* Then content */
		for (i = 0; i < len; i++)
		{
			count += _putchar(s[i]);
		}
	}
	return (count);
}

/**
 * print_number - iterative function to print numbers
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
 * print_int - prints integers with width and precision
 * @args: arguments
 * @flags: flags
 * @length: length modifier
 * @width: field width
 * @precision: min digits to print
 * @left_justify: whether to left justify
 * Return: number of characters printed
 */
int print_int(va_list args, int flags, int length, int width, int precision, int left_justify)
{
	long n;
	unsigned long num;
	int count = 0, len = 0, zeros = 0, total_len = 0;
	int sign = 0; /* 0: none, 1: +, 2: space, 3: - */
	unsigned long temp;
	int padding;

	if (length == LENGTH_L) n = va_arg(args, long);
	else if (length == LENGTH_H) n = (short)va_arg(args, int);
	else n = va_arg(args, int);

	if (n < 0)
	{
		sign = 3;
		num = (n == LONG_MIN) ? ((unsigned long)LONG_MAX + 1) : (unsigned long)(-n);
	}
	else
	{
		num = (unsigned long)n;
		if (flags & 1) sign = 1;
		else if (flags & 2) sign = 2;
	}

	if (num == 0 && precision == 0)
		len = 0; /* Special case: print nothing */
	else
	{
		temp = num;
		len = (temp == 0) ? 1 : 0;
		while (temp > 0) { temp /= 10; len++; }
	}

	if (precision > len)
		zeros = precision - len;

	total_len = len + zeros + (sign ? 1 : 0);
	padding = width - total_len;

	/* LEFT JUSTIFICATION: content first, then padding */
	if (left_justify)
	{
		/* Print sign */
		if (sign == 3) count += _putchar('-');
		else if (sign == 1) count += _putchar('+');
		else if (sign == 2) count += _putchar(' ');

		/* Precision zeros */
		while (zeros > 0)
		{
			count += _putchar('0');
			zeros--;
		}

		/* Print the number */
		if (len > 0)
			count += print_unsigned_number(num);

		/* Padding at the end */
		while (padding > 0)
		{
			count += _putchar(' ');
			padding--;
		}
	}
	else
	{
		/* RIGHT JUSTIFICATION: padding first, then content */
		while (padding > 0)
		{
			count += _putchar(' ');
			padding--;
		}
		
		/* Then sign */
		if (sign == 3) count += _putchar('-');
		else if (sign == 1) count += _putchar('+');
		else if (sign == 2) count += _putchar(' ');

		/* Precision zeros */
		while (zeros > 0)
		{
			count += _putchar('0');
			zeros--;
		}

		/* Print the number */
		if (len > 0)
			count += print_unsigned_number(num);
	}

	return (count);
}

/**
 * print_binary - converts unsigned int to binary
 * @n: number
 * Return: count
 */
int print_binary(unsigned int n)
{
	int count = 0;
	char buffer[33];
	int i = 0;

	if (n == 0) return _putchar('0');

	while (n > 0)
	{
		buffer[i++] = (n % 2) + '0';
		n /= 2;
	}
	while (i > 0) count += _putchar(buffer[--i]);
	return count;
}

/**
 * print_unsigned - prints unsigned int with width/precision
 */
int print_unsigned(va_list args, int flags, int length, int width, int precision, int left_justify)
{
	unsigned long n, temp;
	int len = 0, zeros = 0, count = 0, total_len;
	int padding;

	if (length == LENGTH_L) n = va_arg(args, unsigned long);
	else if (length == LENGTH_H) n = (unsigned short)va_arg(args, unsigned int);
	else n = va_arg(args, unsigned int);

	(void)flags;

	if (n == 0 && precision == 0) len = 0;
	else
	{
		temp = n;
		len = (temp == 0) ? 1 : 0;
		while (temp > 0) { temp /= 10; len++; }
	}

	if (precision > len) zeros = precision - len;
	total_len = len + zeros;
	padding = width - total_len;

	/* LEFT JUSTIFICATION: content first, then padding */
	if (left_justify)
	{
		/* Precision zeros */
		while (zeros > 0)
		{
			count += _putchar('0');
			zeros--;
		}

		/* Print the number */
		if (len > 0)
			count += print_unsigned_number(n);

		/* Padding at the end */
		while (padding > 0)
		{
			count += _putchar(' ');
			padding--;
		}
	}
	else
	{
		/* RIGHT JUSTIFICATION: padding first, then content */
		while (padding > 0)
		{
			count += _putchar(' ');
			padding--;
		}

		/* Precision zeros */
		while (zeros > 0)
		{
			count += _putchar('0');
			zeros--;
		}

		/* Print the number */
		if (len > 0)
			count += print_unsigned_number(n);
	}
	return (count);
}

/**
 * print_octal - prints octal with width/precision
 */
int print_octal(va_list args, int flags, int length, int width, int precision, int left_justify)
{
	unsigned long n, temp;
	int len = 0, zeros = 0, count = 0, total_len, prefix = 0;
	int padding;

	if (length == LENGTH_L) n = va_arg(args, unsigned long);
	else if (length == LENGTH_H) n = (unsigned short)va_arg(args, unsigned int);
	else n = va_arg(args, unsigned int);

	if ((flags & 4) && n != 0) prefix = 1; /* # flag adds 0 */

	if (n == 0 && precision == 0) len = 0;
	else
	{
		temp = n;
		len = (temp == 0) ? 1 : 0;
		while (temp > 0) { temp /= 8; len++; }
	}

	if (precision > len) zeros = precision - len;
	
	/* # flag for octal guarantees a leading zero. 
	 * If precision already added zeros, we don't add another one.
	 * If prefix needed and no zeros added by precision, we add 1 to length (or zeros)
	 */
	if (prefix && zeros == 0) zeros = 1;

	total_len = len + zeros;
	padding = width - total_len;

	/* LEFT JUSTIFICATION: content first, then padding */
	if (left_justify)
	{
		/* Precision zeros */
		while (zeros > 0)
		{
			count += _putchar('0');
			zeros--;
		}

		/* Print the number */
		if (len > 0)
			count += print_octal_number(n);

		/* Padding at the end */
		while (padding > 0)
		{
			count += _putchar(' ');
			padding--;
		}
	}
	else
	{
		/* RIGHT JUSTIFICATION: padding first, then content */
		while (padding > 0)
		{
			count += _putchar(' ');
			padding--;
		}

		/* Precision zeros */
		while (zeros > 0)
		{
			count += _putchar('0');
			zeros--;
		}

		/* Print the number */
		if (len > 0)
			count += print_octal_number(n);
	}
	return (count);
}

/**
 * print_hex - prints hex with width/precision
 */
int print_hex(va_list args, int uppercase, int flags, int length, int width, int precision, int left_justify)
{
	unsigned long n, temp;
	int len = 0, zeros = 0, count = 0, total_len, prefix = 0;
	int padding;

	if (length == LENGTH_L) n = va_arg(args, unsigned long);
	else if (length == LENGTH_H) n = (unsigned short)va_arg(args, unsigned int);
	else n = va_arg(args, unsigned int);

	if ((flags & 4) && n != 0) prefix = 2; /* 0x */

	if (n == 0 && precision == 0) len = 0;
	else
	{
		temp = n;
		len = (temp == 0) ? 1 : 0;
		while (temp > 0) { temp /= 16; len++; }
	}

	if (precision > len) zeros = precision - len;
	total_len = len + zeros + prefix;
	padding = width - total_len;

	/* LEFT JUSTIFICATION: content first, then padding */
	if (left_justify)
	{
		/* Prefix */
		if (prefix)
		{
			count += _putchar('0');
			count += _putchar(uppercase ? 'X' : 'x');
		}

		/* Precision zeros */
		while (zeros > 0)
		{
			count += _putchar('0');
			zeros--;
		}

		/* Print the number */
		if (len > 0)
			count += print_hex_number(n, uppercase);

		/* Padding at the end */
		while (padding > 0)
		{
			count += _putchar(' ');
			padding--;
		}
	}
	else
	{
		/* RIGHT JUSTIFICATION: padding first, then content */
		while (padding > 0)
		{
			count += _putchar(' ');
			padding--;
		}

		/* Prefix */
		if (prefix)
		{
			count += _putchar('0');
			count += _putchar(uppercase ? 'X' : 'x');
		}

		/* Precision zeros */
		while (zeros > 0)
		{
			count += _putchar('0');
			zeros--;
		}

		/* Print the number */
		if (len > 0)
			count += print_hex_number(n, uppercase);
	}
	return (count);
}

/**
 * print_unsigned_number - prints unsigned long
 */
int print_unsigned_number(unsigned long n)
{
	int count = 0;
	char buffer[21];
	int i = 0;

	if (n == 0) return _putchar('0');

	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i > 0) count += _putchar(buffer[--i]);
	return count;
}

/**
 * print_octal_number - prints octal
 */
int print_octal_number(unsigned long n)
{
	int count = 0;
	char buffer[23];
	int i = 0;

	if (n == 0) return _putchar('0');

	while (n > 0)
	{
		buffer[i++] = (n % 8) + '0';
		n /= 8;
	}
	while (i > 0) count += _putchar(buffer[--i]);
	return count;
}

/**
 * print_hex_number - prints hex
 */
int print_hex_number(unsigned long n, int uppercase)
{
	int count = 0;
	char buffer[17];
	int i = 0;
	char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n == 0) return _putchar('0');

	while (n > 0)
	{
		buffer[i++] = digits[n % 16];
		n /= 16;
	}
	while (i > 0) count += _putchar(buffer[--i]);
	return count;
}

/**
 * print_string_escaped - prints escaped string
 */
int print_string_escaped(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0, i;
	char hex_digits[] = "0123456789ABCDEF";

	if (!s) s = "(null)";

	for (i = 0; s[i]; i++)
	{
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += _putchar(hex_digits[(unsigned char)s[i] / 16]);
			count += _putchar(hex_digits[(unsigned char)s[i] % 16]);
		}
		else count += _putchar(s[i]);
	}
	return (count);
}

/**
 * print_pointer - prints pointer
 */
int print_pointer(va_list args, int width)
{
	void *ptr = va_arg(args, void *);
	unsigned long address;
	char buffer[20];
	int i = 0, count = 0, len = 2; /* 0x */
	char hex_digits[] = "0123456789abcdef";

	if (ptr == NULL) return print_string("(nil)", width, -1, 0);

	address = (unsigned long)ptr;
	
	if (address == 0) len++;
	else
	{
		unsigned long temp = address;
		while (temp > 0) { temp /= 16; len++; }
	}

	while (width > len)
	{
		count += _putchar(' ');
		width--;
	}

	count += _putchar('0');
	count += _putchar('x');

	if (address == 0) count += _putchar('0');
	else
	{
		while (address > 0)
		{
			buffer[i++] = hex_digits[address % 16];
			address /= 16;
		}
		while (i > 0) count += _putchar(buffer[--i]);
	}
	return (count);
}

/**
 * print_rev - prints a string in reverse
 * @args: argument list
 * Return: number of characters printed
 */
int print_rev(va_list args)
{
	char *s = va_arg(args, char *);
	int len = 0;
	int i;
	int count = 0;

	if (!s)
		s = "(null)";

	while (s[len])
		len++;

	for (i = len - 1; i >= 0; i--)
	{
		count += _putchar(s[i]);
	}
	return (count);
}

/**
 * print_rot13 - prints the rot13'ed string
 * @args: arguments
 * Return: count of characters printed
 */
int print_rot13(va_list args)
{

}