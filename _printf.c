#include "main.h"

void _printbuffer(char buffer[], int *buff_ind);

/**
  * _printf - prints a function
  * @format: format
  * Return: printed characters
  */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				_printbuffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			_printbuffer(buffer, &buff_ind);
			flags = _getflags(format, &i);
			width = _printwidth(format, &i, list);
			precision = _printprecision(format, &i, list);
			size = _printsize(format, &i);
			++i;
			printed = _printhandlers(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	_printbuffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * _printbuffer - Prints contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void _printbuffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
