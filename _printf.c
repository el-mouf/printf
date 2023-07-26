#include "main.h"

int puts_character(char ch);
int puts_string(const char *str);
int handles_character(va_list args);
int handles_string(va_list args);

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
						num += handles_character(args);
						break;
					}
				case 's':
					{
						num += handles_string(args);
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
