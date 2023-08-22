#include "main.h"

void cleanup(va_list args, buffer_t *output);
int _runprintf(const char *format, va_list args, buffer_t *output);
int _printf(const char *format, ...);

/**
 * cleanup - Peforms cleanup operations for _printf.
 * @args: A va_list of arguments provided to _printf.
 * @output: A buffer_t struct.
 */
void cleanup(va_list args, buffer_t *output)
{
	va_end(args);
	write(1, output->start, output->length);
	free_buffer(output);
}

/**
 * _runprintf - Reads through the format string for _printf.
 * @format: Character string to print - may contain directives.
 * @output: A buffer_t struct containing a buffer.
 * @args: A va_list of arguments.
 *
 * Return: The number of characters stored to output.
 */
int _runprintf(const char *format, va_list args, buffer_t *output)
{
	int i, wid, prec, ret = 0;
	char tmp;
	unsigned char flags, length;
	unsigned int (*f)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);

	for (i = 0; *(format + i); i++)
	{
		length = 0;
		if (*(format + i) == '%')
		{
			tmp = 0;
			flags = _handleflags(format + i + 1, &tmp);
			wid = _handlewidth(args, format + i + tmp + 1, &tmp);
			prec = _handleprecision(args, format + i + tmp + 1,
					&tmp);
			length = _handlelen(format + i + tmp + 1, &tmp);

			f = _handlespecifiers(format + i + tmp + 1);
			if (f != NULL)
			{
				i += tmp + 1;
				ret += f(args, output, flags, wid, prec, length);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += _memorycopy(output, (format + i), 1);
		i += (length != 0) ? 1 : 0;
	}
	cleanup(args, output);
	return (ret);
}

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int ret;

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);

	ret = _runprintf(format, args, output);

	return (ret);
}
