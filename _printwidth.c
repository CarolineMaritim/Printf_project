#include "main.h"
/**
 * _printwidth - Returns a width specifier
 * @format: Pointer to the format arg.
 * @num: Pointer to args to be printed
 * @args: Variadic arg.
 *
 * Return: The width specifier.
 */
int _printwidth(const char *format, int *num, va_list args)
{
	int current_index, width = 0;
/*loop through the format arg*/
for (current_index = *num + 1; format[current_index] != '\0'; current_index++)
{
	/*inner for loop to check against the specifiers*/
	if (_isdigit(format[current_index]))
	{
		width = width * 10;
		/*get numeric value*/
		width += format[current_index] - '0';
	}
	else if (format[current_index] == '*')
	{
		current_index++;
		width = va_arg(args, int);
		break;
	}
	else
		break;
}
*num = current_index - 1;
return (width);
}
