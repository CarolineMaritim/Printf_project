#include "main.h"
#include <unistd.h>
/**
 * _writechar - Prints a string
 * @c: Character handled
 * @b: Buffer array
 * @f: Flags active
 * @w: Width
 * @p: Precision
 * @s: Size of the buffer
 *
 * Return: Characters printed
 */
int _writechar(char c, char b[], int f, int w,
		int p, int s)
{

	char pad = ' ';
	int index = 0;
	UNUSED(s);
	UNUSED(p);
	if (f && FLAG_ZERO)
		pad = '\0';
	b[index++] = c;
	b[index] = '\0';
	if (w > 1)
	{
		b[BUFF_SIZE - 1] = '\0';
		for (index = 0; index < w; index++)
		b[BUFF_SIZE - index - 2] = pad;
		if (f & FLAG_MINUS)
		return (write(1, &b[0], 1) + 
					write(1, &b[BUFF_SIZE - index - 1]
						, w - 1));
		else
		return (write(1, &b[BUFF_SIZE - index - 1], w - 1) + 
					write(1, &b[0], 1));
	}
	return (write(1, &b[0], 1));
}
/**
 * _writenumber - Prints a number string
 * @negative_int: Arguments
 * @num: Number of argument types
 * @b: Buffer array
 * @f: Flags active
 * @w: Width
 * @p: Precision
 * @s: Size
 *
 * Return: Characters printed
 */
int _writenumber(int negative_int, int num, char b[], int f,
		int w, int p, int s)
{
	char pad = ' ';
	char ch = 0;
	int len = BUFF_SIZE - num - 1;
	UNUSED(s);
	if ((f & FLAG_ZERO) && !(f & FLAG_MINUS))
		pad = '\0';
	if (negative_int)
		ch = '-';
	else if (f & FLAG_PLUS)
		ch = '+';
	else if (f & FLAG_SPACE)
		ch = ' ';
	else
		return (_writenum(num, b, f, w, p, len, pad, ch));
}
/**
 * _writenum - Writes number to the stdout
 * @num: Number index
 * @b: Buffer array
 * @f: Active flags
 * @w: Width
 * @p: Precision
 * @len: Length of buffer
 * @pad: Char paddig
 * @ch: Added char
 *
 * Return: Number of characters printed
 */
int _writenum(int num, char b[], int f, int w, int p, int len,
	    char pad, char ch)
{
	int index;
	int pad_start = 1;
	if (p == 0 && num == BUFF_SIZE - 2 && b[num] == '0' && w == 0)
		return (0);
	if (p == 0 && num == BUFF_SIZE - 2 && b[num] == '0')
		b[num] = pad = ' ';
	if (p > 0 && p < len)
		pad = ' ';
	while (p > len)
	{
		b[--num] = '0';
	len++;
	}
	if (ch != 0)
		len++;
	if (w > len)
	{
		for (index = 1; index < w - len + 1; index++)
			b[index] = pad;
		b[index] = '\0';
		if ((f & FLAG_MINUS) && pad == ' ')
		{
			if (ch)
				b[--num] = ch;
			return (write(1, &b[num], len) + write(1, &b[1], index - 1));
		}
		else if (!(f & FLAG_MINUS) && pad == ' ')
		{
			if (ch)
				b[--num] = ch;
			return (write(1, &b[1], index - 1) + write(1, &b[num], len));
		}
		 else if (!(f & FLAG_MINUS) && pad == '0')
                {
                        if (ch)
                                b[--pad_start] = ch;
                        return (write(1, &b[pad_start], index - pad_start) + 
					write(1, &b[num], len - (1 - pad_start)));
                }
	}
	if (ch)
		b[--num] = ch;
	return (write(1, &b[num], len));
}
/**
 * _writeunsigned - Writes unsgn int to stdout
 * @negative_int: Negative number
 * @num: The star of the buffer
 * @b: Buffer array
 * @f: Active flags
 * @w: Width
 * @p: Precision
 * @s: Size of the buffer
 *
 * Return: Characters written to stdout
 */

int _writeunsigned(int negative_num, int num, char b[], int f, int w, int p, int s)
{
	UNUSED(negative_num);
	UNUSED(s);
	int len = BUFF_SIZE - num -1;
	int index = 0;
	char pad = ' ';
	if (p == 0 && num == BUFF_SIZE - 2 && b[num] == '0')
	return (0);
	if (p > 0 && p < len)
	pad = ' ';
	while (p > len)
	{
		b[--num] = '0';
		len++;
	}
	if ((f & FLAG_ZERO) && !(f & FLAG_MINUS))
	{
		pad = '0';
	}
	if (w > len)
	{
		for (index = 0; index < w - len; index++)
			b[index] = pad;
		if (f & FLAG_MINUS)
		{
			return(write(1, &b[num], len) + write(1, &b[0], index));
		}
		else
			return (write(1, &b[0], index) + write(1, &b[num], len));
	}
return (write(1, &b[num], len));
}
/**
 * _writepointer - Writes pointer to address to stdout
 * @b: Buffer array
 * @num: First num index
 * @len: Length of the array
 * @w: Width
 * @f: Active flags
 * @pad: Space char for padding
 * @ch: Extra char
 * @pad_start: Where padding starts
 *
 * Return: Characters written
 */
int _writepointer(char b[], int num, int len, int w, int f, 
		char pad, char ch, int pad_start)
{
	int index;
	if (w > len)
	{
		for (index = 3; index < w - len + 3; index++)
			b[index] = pad;
		b[index] = '\0';
		if ((f & FLAG_MINUS) && pad == ' ')
		{
			b[--num] = 'x';
			b[--num] = '0';
			if (ch)
				b[--num] = ch;
			return(write(1, &b[num], len) + write(1, &b[3], index - 3));
			
		}
		else if (!(f & FLAG_MINUS) && pad == ' ')
		{
			b[--num] = 'x';
			b[--num] = '0';
			if (ch)
				b[--num] = ch;
			return (write(1, &b[3], index - 3) + write(1, &b[num], len));
		}
		else if (!(f & FLAG_MINUS) && pad == '0')
		{
		if (ch)
			b[--pad_start] = ch;
		b[1] = '0';
		b[2] = 'x';
		return (write(1, &b[pad_start], index - pad_start) + 
				write(1, &b[num], len(1 - pad_start) - 2));
		}
	}
	b[--num] = 'x';
	b[--num] = '0';
	if (ch)
		b[--num] = ch;
	return (write(1, &b[num], BUFF_SIZE - num - 1));
}
