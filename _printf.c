#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
int handle_specifier(const char *format, int *i, va_list cart)
{
    char c;

    (*i)++;
    if (!format[*i]) return (-1);
    if (format[*i] == 'c') { c = va_arg(cart, int); write(1, &c, 1); return (1); }
    if (format[*i] == 's') return (print_string(va_arg(cart, char *)));
    if (format[*i] == 'S') return (print_string_escaped(cart));  // ← ADD THIS LINE
    if (format[*i] == '%') { write(1, "%", 1); return (1); }
    if (format[*i] == 'b') return (print_binary(va_arg(cart, unsigned int)));
    if (format[*i] == 'u') return (print_unsigned(cart));
    if (format[*i] == 'o') return (print_octal(cart));
    if (format[*i] == 'x') return (print_hex(cart, 0));
    if (format[*i] == 'X') return (print_hex(cart, 1));

    write(1, "%", 1);
    write(1, &format[*i], 1);
    return (2);
}
