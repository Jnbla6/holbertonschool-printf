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
