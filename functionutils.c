#include "main.h"
/**
 * _isprintable - Checks if character is printable
 * @c: character being checked
 *
 * Return: 1 if true, else 0
 */
int _isprintable(char c)
{
	if (c >= 32 && c < 127)
		/*loops to check the printable chars*/
		return (1);
	else
		return (0);
}
/**
 * _isdigit - Checks if character is a digit
 * @c: Character to be checked
 *
 * Return: 1 if true. else 0
 */
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/**
 * _gethexacode - Gets hexa code from ascii
 * @buffer: Array of characters
 * @index: Index
 * @ac: ASCII CODE
 *
 * Return: 3 always
 */
int _gethexacode(char ac, char buffer[], int index)
{
	char hexvalues[] = "0123456789ABCDEF";
	if (ac < 0)

	ac = ac * -1;

	buffer[index++] = '\\';

	buffer[index++] = 'x';

	buffer[index++] = hexvalues[ac / 16];

	buffer[index] = hexvalue[ac % 16];

	return (3);
}
/**
 * _convertunsignednum - Converts num to a particular size
 * @n: Number checked
 * @size: Size of the number
 *
 * Return: The result number
 */
long int _convertunsignednum(unsigned long int n, int size)
{
	if (size == SIZE_LONG)
		return (n);
	else if (size == SIZE_SHORT)
		return ((unsigned int)n);
	else
		return ((unsigned int)n);
}
/**
 * _convertnumsize - Sets number to specific size
 * @n: Number being checked
 * @size: Size of the Number checked
 *
 * Return: Number n
 */
long int _convertnumsize(long int n, int size)
{
	if (size == SIZE_LONG)
		return (n);
	else if (size == SIZE_SHORT)
		return ((short)n);
	else
		return ((int)n);
}

