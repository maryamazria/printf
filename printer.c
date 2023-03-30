#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
/**
 * printer - print to stdout
 * @c: character to check
 * @ptr: fromwe can get value to print
 * Return: length of string
 */
int printer(char c, va_list ptr)
{
	int sum = 0;
	char buf[32];
	unsigned int base = 2;
	unsigned int number;
	char *conv;

	switch (c)
	{
		case '%':
			_putchar('%'), sum++;
		break;
		case 'c':
			_putchar(va_arg(ptr, int)), sum++;
		break;
		case 's':
			sum += print_str(va_arg(ptr, char *));
		break;
		case 'i':
		case 'd':
			sum += print_str(_tostring(va_arg(ptr, int), buf));
		break;
		case 'b':
			number = va_arg(ptr, int);
			conv = _convert(number, base);
			sum += print_str(conv);
		break;
		default:
			_putchar('%'), _putchar(c), sum += 2;
		break;
	}
	return (sum);
}
