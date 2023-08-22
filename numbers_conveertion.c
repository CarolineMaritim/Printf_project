#include "main.h"

unsigned int _converttosignedint(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length);
unsigned int _converttobinary(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length);
unsigned int _converttodecimal(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length);
unsigned int _converttooctal(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length);

/**
 * _converttosignedint - Converts an argument to a signed int.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @length: A lengthgth modifier.
 * @output: A buffer_t struct containing a character array
 * Return: The number of bytes stored to the buffer.
 */
unsigned int _converttosignedint(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length)
{
	long int d, copy;
	unsigned int ret = 0, count = 0;
	char pad, space = ' ', neg = '-', plus = '+';

	if (length == LONG)
		d = va_arg(args, long int);
	else
		d = va_arg(args, int);
	if (length == SHORT)
		d = (short)d;

	/* Handle space flag */
	if (SPACE_FLAG == 1 && d >= 0)
		ret += _memorycopy(output, &space, 1);

	if (prec <= 0 && NEG_FLAG == 0) /* Handle width  */
	{
		if (d == LONG_MIN)
			count += 19;
		else
		{
			for (copy = (d < 0) ? -d : d; copy > 0; copy /= 10)
				count++;
		}
		count += (d == 0) ? 1 : 0;
		count += (d < 0) ? 1 : 0;
		count += (PLUS_FLAG == 1 && d >= 0) ? 1 : 0;
		count += (SPACE_FLAG == 1 && d >= 0) ? 1 : 0;

		/* Handle plus flag when zero flag is active */
		if (ZERO_FLAG == 1 && PLUS_FLAG == 1 && d >= 0)
			ret += _memorycopy(output, &plus, 1);
		/*Print negative sign when zero flag is active */
		if (ZERO_FLAG == 1 && d < 0)
			ret += _memorycopy(output, &neg, 1);

		pad = (ZERO_FLAG == 1) ? '0' : ' ';
		for (wid -= count; wid > 0; wid--)
			ret += _memorycopy(output, &pad, 1);
	}

	/* Print negative sign when zero flag is not active */
	if (ZERO_FLAG == 0 && d < 0)
		ret += _memorycopy(output, &neg, 1);
	/* Handle plus flag when zero flag is not active */
	if (ZERO_FLAG == 0 && (PLUS_FLAG == 1 && d >= 0))
		ret += _memorycopy(output, &plus, 1);

	if (!(d == 0 && prec == 0))
		ret += _convertsignedbase(output, d, "0123456789",
				flags, 0, prec);

	ret += _printnegwidth(output, ret, flags, wid);

	return (ret);
}

/**
 * _converttobinary - Converts an unsigned int argument to binary
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @length: A lengthgth modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int _converttobinary(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	(void)length;

	return (_convertunsignedbase(output, num, "01", flags, wid, prec));
}

/**
 * _converttooctal - Converts an unsigned int to octal and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list poinitng to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @length: A lengthgth modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int _converttooctal(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length)
{
	unsigned long int num;
	unsigned int ret = 0;
	char zero = '0';

	if (length == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (length == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memorycopy(output, &zero, 1);

	if (!(num == 0 && prec == 0))
		ret += _convertunsignedbase(output, num, "01234567",
				flags, wid, prec);

	ret += _printnegwidth(output, ret, flags, wid);

	return (ret);
}

/**
 * _converttodecimal - Converts an unsigned int argument to decimal and
 *               stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @length: A lengthgth modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int _converttodecimal(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char length)
{
	unsigned long int num;
	unsigned int ret = 0;

	if (length == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (length == SHORT)
		num = (unsigned short)num;

	if (!(num == 0 && prec == 0))
		ret += _convertunsignedbase(output, num, "0123456789",
				flags, wid, prec);

	ret += _printnegwidth(output, ret, flags, wid);

	return (ret);
}
