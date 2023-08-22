#include "main.h"

unsigned int _convertsignedbase(buffer_t *output, long int num, char *base,
		unsigned char flags, int wid, int prec);
unsigned int _convertunsignedbase(buffer_t *output,
		unsigned long int num, char *base,
		unsigned char flags, int wid, int prec);

/**
 * _convertsignedbase - Converts a signed long to an inputted base and stores
 *                 the result to a buffer contained in a struct.
 * @output: A buffer_t struct containing a character array.
 * @num: A signed long to be converted.
 * @base: A pointer to a string containing the base to convert to.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int _convertsignedbase(buffer_t *output, long int num, char *base,
		unsigned char flags, int wid, int prec)
{
	int size;
	char digit, pad = '0';
	unsigned int ret = 1;

	for (size = 0; *(base + size);)
		size++;

	if (num >= size || num <= -size)
		ret += _convertsignedbase(output, num / size, base,
				flags, wid - 1, prec - 1);

	else
	{
		for (; prec > 1; prec--, wid--) /* Handle precision */
			ret += _memorycopy(output, &pad, 1);

		if (NEG_FLAG == 0) /* Handle width */
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				ret += _memorycopy(output, &pad, 1);
		}
	}

	digit = base[(num < 0 ? -1 : 1) * (num % size)];
	_memorycopy(output, &digit, 1);

	return (ret);
}

/**
 * _convertunsignedbase - Converts an unsigned long to an inputted base and
 *                 stores the result to a buffer contained in a struct.
 * @output: A buffer_t struct containing a character array.
 * @num: An unsigned long to be converted.
 * @base: A pointer to a string containing the base to convert to.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int _convertunsignedbase(buffer_t *output, unsigned long int num,
		char *base, unsigned char flags, int wid, int prec)
{
	unsigned int size, ret = 1;
	char digit, pad = '0', *lead = "0x";

	for (size = 0; *(base + size);)
		size++;

	if (num >= size)
		ret += _convertunsignedbase(output, num / size, base,
				flags, wid - 1, prec - 1);

	else
	{
		if (((flags >> 5) & 1) == 1) /* Printing a ptr address */
		{
			wid -= 2;
			prec -= 2;
		}
		for (; prec > 1; prec--, wid--) /* Handle precision */
			ret += _memorycopy(output, &pad, 1);

		if (NEG_FLAG == 0) /* Handle width */
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				ret += _memorycopy(output, &pad, 1);
		}
		if (((flags >> 5) & 1) == 1) /* Print 0x for ptr address */
			ret += _memorycopy(output, lead, 2);
	}

	digit = base[(num % size)];
	_memorycopy(output, &digit, 1);

	return (ret);
}
