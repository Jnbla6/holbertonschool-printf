#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				i += _putchar(va_arg(args, int));
			else if (*format == 's')
				i += print_string(va_arg(args, char *));
			else if (*format == '%')
				i += _putchar('%');
			else if (*format == 'd' || *format == 'i')
				i += print_number(va_arg(args, int));
			else if (*format == 'b')
				i += print_binary(va_arg(args, unsigned int));
			else if (*format == 'p')
				i += print_pointer(va_arg(args, void *));
			else if (*format == 'S')
				i += print_custom_string(va_arg(args, char *));
			else
			{
				i += _putchar('%');
				i += _putchar(*format);
			}
		}
		else
			i += _putchar(*format);
		format++;
	}

	va_end(args);
	return (i);
}
