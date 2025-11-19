/**
 * print_custom_string - prints string with non-printable characters escaped
 * @str: string to print
 *
 * Return: number of characters printed
 */
int print_custom_string(char *str)
{
	int count = 0;
	unsigned char current;

	if (str == NULL)
		return (print_string("(null)"));

	while (*str)
	{
		current = (unsigned char)*str;
		
		/* Check if character is non-printable (0 < ASCII < 32 or >= 127) */
		if ((current > 0 && current < 32) || current >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			/* Always print 2 characters for hex */
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
/**
 * print_string_escaped - prints string with non-printable characters escaped
 * @args: variadic list
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
        /* Check if character is non-printable (0 < ASCII < 32 or >= 127) */
        if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
        {
            count += write(1, "\\x", 2);
            /* Print first hex digit (upper case) */
            count += write(1, &hex_digits[(unsigned char)s[i] / 16], 1);
            /* Print second hex digit (upper case) */
            count += write(1, &hex_digits[(unsigned char)s[i] % 16], 1);
        }
        else
        {
            count += write(1, &s[i], 1);
        }
    }

    return (count);
}
