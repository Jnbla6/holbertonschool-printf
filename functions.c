#include "main.h"

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int print_string(char *str)
{
	int c = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		c += _putchar(*str);
		str++;
	}
	return (c);
}

int print_number(int n)
{
	int c = 0;
	unsigned int num;

	if (n < 0)
	{
		c += _putchar('-');
		num = -n;
	}
	else
		num = n;

	if (num / 10)
		c += print_number(num / 10);
	c += _putchar(num % 10 + '0');

	return (c);
}

int print_binary(unsigned int n)
{
	int c = 0;

	if (n > 1)
		c += print_binary(n / 2);

	c += _putchar((n % 2) + '0');
	return (c);
}

int print_pointer(void *ptr)
{
	unsigned long address = (unsigned long)ptr;
	int count = 0;
	int digit, i = 0;
	char buffer[20];

	if (ptr == NULL)
		return (print_string("(nil)"));

	if (address == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (address > 0)
		{
			digit = address % 16;
			buffer[i++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
			address /= 16;
		}
	}

	count += _putchar('0');
	count += _putchar('x');

	while (i > 0)
		count += _putchar(buffer[--i]);

	return (count);
}

int print_custom_string(char *str)
{
	int count = 0;
	unsigned char current;

	if (!str)
		return (print_string("(null)"));

	while (*str)
	{
		current = (unsigned char)*str;
		
		if ((current > 0 && current < 32) || current >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += _putchar("0123456789ABCDEF"[current / 16]);
			count += _putchar("0123456789ABCDEF"[current % 16]);
		}
		else
		{
			count += _putchar(current);
		}
		str++;
	}

	return (count);
}
