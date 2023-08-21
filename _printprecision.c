#include "main.h"
/**
 * _printprecision - Gets precision for printing.
 * @format: Pointer to the format string
 * @num: Argument count to be printed
 * @args: Variadic arguments to print
 *
 * Return: The precision
 */
int _printprecision(const char *format, int *num, va_list args)
{
int pres = -1;
int current_index = *num + 1;
/*precision consists of a point followed by an int*/
if (format[current_index] != '.')
	return (pres);
pres = 0;
for (current_index = 1; format[current_index]; current_index++)
{
	if (_isdigit(format[current_index]))
	{
		pres = pres * 10;
		pres += format[current_index] - '0';
	}
	else if (format[current_index] == '*')
	{
		current_index++;
		pres = va_arg(args, int);
		break;
	}
	else
		break;
}
*num = current_index - 1;
return (pres);
}
