#include <stdio.h>
#include <stdarg.h>

int puts_integer(int num)
{
	int count = 0;
	int divisor = 1;

	if (num < 0)
	{
		putchar('-');
		num = -num;
		count++;
	}
	while (num / divisor > 9)
	{
		divisor *= 10;
	}
	while (divisor > 0)
	{
		putchar ('0' + num /divisor);
		num %= divisor;
		divisor /= 10;
		count++;
	}
	return (count);
}

int handles_integer(va_list args)
{
	int num = va_arg(args, int);
	
	return (puts_integer(num));
}
