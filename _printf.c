#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 *
 * Return: number of bytes written
 */
static int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_string - prints a string
 * @s: string to print
 *
 * Return: number of characters printed
 */
static int _print_string(char *s)
{
	int count = 0;

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
 * _print_int - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
static int _print_int(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += _print_int(num / 10);

	count += _putchar((num % 10) + '0');

	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
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
		else if (format[i] == 'd' || format[i] == 'i')
			count += _print_int(va_arg(args, int));
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
