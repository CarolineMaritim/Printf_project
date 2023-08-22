#include "main.h"

unsigned int _convertchar(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length);
unsigned int _convertpercent(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length);
unsigned int _convertpointertohex(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length);

/**
 * _convertchar - Converts an argument to an unsigned char and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @length: A lengthgth modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int _convertchar(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length)
{
	char c;
	unsigned int ret = 0;

	(void)prec;
	(void)length;

	c = va_arg(args, int);

	ret += _printwidth(output, ret, flags, wid);
	ret += _memorycopy(output, &c, 1);
	ret += _printnegwidth(output, ret, flags, wid);

	return (ret);
}

/**
 * _convertpercent - Stores a percent sign to a
 *                   buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @length: A lengthgth modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer (always 1).
 */
unsigned int _convertpercent(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length)
{
	char percent = '%';
	unsigned int ret = 0;

	(void)args;
	(void)prec;
	(void)length;

	ret += _printwidth(output, ret, flags, wid);
	ret += _memorycopy(output, &percent, 1);
	ret += _printnegwidth(output, ret, flags, wid);

	return (ret);
}

/**
 * _convertpointertohex - Converts the address of an argument to hex and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @length: A lengthgth modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int _convertpointertohex(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length)
{
	char *null = "(nil)";
	unsigned long int address;
	unsigned int ret = 0;

	(void)length;

	address = va_arg(args, unsigned long int);
	if (address == '\0')
		return (_memorycopy(output, null, 5));

	flags |= 32;
	ret += _convertunsignedbase(output, address, "0123456789abcdef",
			flags, wid, prec);
	ret += _printnegwidth(output, ret, flags, wid);

	return (ret);
}
