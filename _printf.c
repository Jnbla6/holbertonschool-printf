#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char c;

    if (!format || (format[0] == '%' && format[1] == '\0')) /* handelh for errors*/
        return (-1);

    va_start(args, format);

    for (i = 0; format[i]; i++)
    {
        if (format[i] == '%')
        {
            i++; /* to check the type after %*/
            if (format[i] == 'c')
            {
                c = va_arg(args, int);
                count += write(1, &c, 1); /* to write the char*/
            }
            else if (format[i] == 's')
                count += print_string(args);
            else if (format[i] == '%')
                {
                write(1, "%", 1);
                return (1);
                }

            else if (format[i] == 'd' || format[i] == 'i')
                count += print_int(args);
            else
            {
                count += write(1, "%", 1);
                count += write(1, &format[i], 1);
            }
        }
        else
        {
            count += write(1, &format[i], 1);
        }
    }

    va_end(args);
    return (count);
} 
