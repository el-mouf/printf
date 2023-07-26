#include "main.h"

/**
 * puts_character - handles characters
 * @ch: the character
 * Return: returns 1
 */

int puts_character(char ch)
{
	putchar(ch);
	return (1);
}

/**
 * puts_string - handles strings
 * @str: the string
 * Return: string's count
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
 * handles_character - handles conversion specifier
 * Return: character output
 */

int handles_character(va_list args)
{
	int ch = va_arg(args, int);
	
	return (puts_character(ch));
}

/** 
 * handles_string - handles conversion specifier str
 * Return: string output
 */

int handles_string(va_list args)
{
	char *str = va_arg(args, char*);

	return (puts_string(str));
}
