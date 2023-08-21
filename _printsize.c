#include "main.h"
/**
 * _printsize - Defines the size of var argument.
 * @format: Pointer to the format arg.
 * @num: Arguments to be printed
 *
 * Return: Size of the argument
 */
int _printsize(const char *format, int *num)
{
	int size = 0;
	int current_index = *num + 1;
/*loop through current index of format arg*/
for (; format[current_index] != '\0'; current_index++)
{
	if (format[current_index] == 'l')
	{
		size = SIZE_LONG;
	}
	else if (format[current_index] == 'h')
	{
		size = SIZE_SHORT;
	}
}
if (size == 0)
	*num = current_index - 1;
	else
	*num = current_index;
	return (size);
}
