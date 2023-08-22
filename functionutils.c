#include "main.h"
unsigned int _printwidth(buffer_t *output, unsigned int printed,
unsigned char flags, int wid);
unsigned int _printstrnwidth(buffer_t *output,
unsigned char flags, int wid, int prec, int size);
unsigned int _printnegwidth(buffer_t *output, unsigned int printed,
unsigned char flags, int wid);
/**
 * _printwidth - Stores leading spaces to a buffer for a width modifier.
 * @output: A buffer_t struct containing a character array.
 * @printed: The current number of characters already printed to output
 *           for a given number specifier.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int _printwidth(buffer_t *output, unsigned int printed,
unsigned char flags, int wid)
{
unsigned int ret = 0;
char width = ' ';
if (NEG_FLAG == 0)
{
for (wid -= printed; wid > 0;)
ret += _memorycopy(output, &width, 1);
}
return (ret);
}
/**
 * _printstrnwidth - Stores leading spaces to a buffer for a width modifier.
 * @output: A buffer_t struct containing a character array.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @size: The size of the string.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int _printstrnwidth(buffer_t *output,
		unsigned char flags, int wid, int prec, int size)
{
unsigned int ret = 0;
char width = ' ';
if (NEG_FLAG == 0)
{
wid -= (prec == -1) ? size : prec;
for (; wid > 0; wid--)
ret += _memorycopy(output, &width, 1);
}
return (ret);
}
/**
 * _printnegwidth - Stores trailing spaces to a buffer for a '-' flag.
 * @output: A buffer_t struct containing a character array.
 * @printed: The current number of bytes already stored to output
 *           for a given specifier.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int _printnegwidth(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
unsigned int ret = 0;
char width = ' ';
if (NEG_FLAG == 1)
{
for (wid -= printed; wid > 0; wid--)
ret += _memorycopy(output, &width, 1);
}
return (ret);
}

