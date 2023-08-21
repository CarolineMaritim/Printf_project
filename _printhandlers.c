#include "main.h"
/**
 * _printhandlers - Prints arg based on provided specifier
 * @format: Pointer to format arg
 * @args: List of args
 * @num: Pointer to current position
 * @buff: Array to store printed chars
 * @flags: Gets active flags
 * @width: Calculates width
 * @precision: Gets precision
 * @size: Size of the buffer
 *
 * Return: Printed_chars
 */
int _printhandlers(const char *format, int *num, va_list args,
		char buff[], int flags, int width, int precision, int size)
{
int index;
int len = 0;
int charprinted = -1;
/*specifiers and their crrsponding funcs*/
format_t format_array[] = {
	{'c', _printchar}, {'s', _printstring}, {'i', _printint},
	{'d', _printint}, {'%', _printpercent}, {'u', _printunsigned},
	{'b', _printbinary}, {'x', _printhexadecimal}, {'o', _printoctal},
	{'p', _printpointer}, {'X', _printhexaupper}, {'r', _printreverse},
	{'S', _print_nonprintable}, {'\0', NULL}, {'R', _printrot13string}
};
for (index = 0; format_array[index] != '\0'; index++)
{
	/*inner loop to find match*/
	if (format[*num] == format_array[index].format)
		return (format_array[index].fn(args, buff, flags, width, precision, size));
	if (format_array[index].format == '\0')
	{
		if (format[*num] == '\0')
			return (-1);
		len = len + write(1, "%%", 1);
		if (format[*num - 1] == ' ')
			len = len + write(1, " ", 1);
		else if (width)
		{
			for (--(*num); format[*num] != ' ' && format[*num] != '%'; --(*num))
				if (format[*num] == ' ')
					--(*num);
			return (1);
		}
		len = len + write(1, &format[*num], 1);
		return (len);
	}
}
return (charprinted);
}
