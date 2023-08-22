#include "main.h"

unsigned int _convertunsignedtohex(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length);
unsigned int _convertunsignedtohex(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length);

/**
 * _convertunsignedtohex - Converts an unsigned int argument to hex
 * using abcdef and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @length: A lengthgth modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int _convertunsignedtohex(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length)
{
	unsigned long int num;
	unsigned int ret = 0;
	char *lead = "0x";

	if (length == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (length == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memorycopy(output, lead, 2);

	if (!(num == 0 && prec == 0))
		ret += _convertunsignedbase(output, num, "0123456789abcdef",
				flags, wid, prec);

	ret += _printnegwidth(output, ret, flags, wid);

	return (ret);
}

/**
 * _convertunsignedtoupperhex - Converts an unsigned int argument to hex
  * using ABCDEF and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @length: A lengthgth modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int _convertunsignedtoupperhex(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length)
{
	unsigned long int num;
	unsigned int ret = 0;
	char *lead = "0X";

	if (length == LONG)
		num = va_arg(args, unsigned long);
	else
		num = va_arg(args, unsigned int);
	if (length == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memorycopy(output, lead, 2);

	if (!(num == 0 && prec == 0))
		ret += _convertunsignedbase(output, num, "0123456789ABCDEF",
				flags, wid, prec);

	ret += _printnegwidth(output, ret, flags, wid);

	return (ret);
}
