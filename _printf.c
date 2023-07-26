#include "main.h"

/**
 * puts_character - defines character
 * @ch: the character
 * Return: returns 1
 */

int puts_character(char ch)
{
	putchar(ch);
	return (1);
}

/**
 * puts_string - gives a string
 * @str: the string
 * Return: string count
 */

int puts_string(const char *str)
{
	int count = 0;

	while (*str)
	{
		putchar(*str);
		str++;
		count++;
	}
	return (count);
}

/**
 * _printf - produces output according
 * to a format
 * @format: character string
 * Return: number of character printed
 */

int _printf(const char *format, ...)
{
	int num = 0;

	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						int ch = va_arg(args, int);
						num += puts_character(ch);
						break;
					}
				case 's':
					{
						char *str = va_arg(args, char*);
						num += puts_string(str);
						break;
					}
				case '%':
					{
						num += puts_character('%');
						break;
					}
				default:
					break;
			}
		}
		else
		{
			num += puts_character(*format);
		}
		format++;
	}
	va_end(args);
	return (num);
}
