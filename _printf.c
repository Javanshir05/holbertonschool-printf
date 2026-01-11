#include "main.h"

static int _putchar(char c)
{
	return (write(1, &c, 1));
}

static int _print_string(char *s)
{
	int count;

	count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		count += _putchar(*s);
		s++;
	}

	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: format string (supports %c, %s, %%)
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;
	int i;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	count = 0;
	i = 0;

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			i++;
			continue;
		}

		i++;
		if (format[i] == '\0')
		{
			va_end(args);
			return (-1);
		}

		if (format[i] == 'c')
			count += _putchar((char)va_arg(args, int));
		else if (format[i] == 's')
			count += _print_string(va_arg(args, char *));
		else if (format[i] == '%')
			count += _putchar('%');
		else
		{
			count += _putchar('%');
			count += _putchar(format[i]);
		}

		i++;
	}

	va_end(args);
	return (count);
}
