#include "main.h"
unsigned int_converttostring(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int_converttostrn(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int _converttorev(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int_converttoRot13(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
/**
 *_converttostring - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int_converttostring(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
char *str, *null = "(null)";
int size;
unsigned int ret = 0;
(void)flags;
(void)len;
str = va_arg(args, char *);
if (str == NULL)
return (_memorycopy(output, null, 6));
for (size = 0; *(str + size);)
size++;
ret += _printstrnwidth(output, flags, wid, prec, size);
prec = (prec == -1) ? size : prec;
while (*str != '\0' && prec > 0)
{
ret += _memorycopy(output, str, 1);
prec--;
str++;
}
ret += _printnegwidth(output, ret, flags, wid);
return (ret);
}
/**
 *_converttostrn - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 *
 * Description: Non-printable characteres (ASCII values < 32 or >= 127)
 *              are stored as \x followed by the ASCII code value in hex.
 */
unsigned int_converttostrn(va_list args, buffer_t *output,
unsigned char flags, int wid, int prec, unsigned char len)
{
char *str, *null = "(null)", *hex = "\\x", zero = '0';
int size, index;
unsigned int ret = 0;
(void)len;
str = va_arg(args, char *);
if (str == NULL)
return (_memorycopy(output, null, 6));
for (size = 0; str[size];)
size++;
ret += _printstrnwidth(output, flags, wid, prec, size);
prec = (prec == -1) ? size : prec;
for (index = 0; *(str + index) != '\0' && index < prec; index++)
{
if (*(str + index) < 32 || *(str + index) >= 127)
{
ret += _memorycopy(output, hex, 2);
if (*(str + index) < 16)
ret += _memorycopy(output, &zero, 1);
ret += _convertunsignedbase(output, *(str + index),
"0123456789ABCDEF", flags, 0, 0);
continue;
}
ret += _memorycopy(output, (str + index), 1);
}
ret += _printnegwidth(output, ret, flags, wid);
return (ret);
}
/**
 * _converttorev - Reverses a string and stores it
 *             to a buffer contained in a struct.
 * @args: A va_list pointing to the string to be reversed.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int _converttorev(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
char *str, *null = "(null)";
int size, end, i;
unsigned int ret = 0;
(void)flags;
(void)len;
str = va_arg(args, char *);
if (str == NULL)
return (_memorycopy(output, null, 6));
for (size = 0; *(str + size);)
size++;
ret += _printstrnwidth(output, flags, wid, prec, size);
end = size - 1;
prec = (prec == -1) ? size : prec;
for (i = 0; end >= 0 && i < prec; i++)
{
ret += _memorycopy(output, (str + end), 1);
end--;
}
ret += _printnegwidth(output, ret, flags, wid);
return (ret);
}
/**
 *_converttoRot13 - Converts a string to ROT13 and stores
 *             it to a buffer contained in a struct.
 * @args: A va_list pointing to the string to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A lenth modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int_converttoRot13(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
char *str, *null = "(null)";
int i, j, size;
unsigned int ret = 0;
(void)flags;
(void)len;
str = va_arg(args, char *);
if (str == NULL)
return (_memorycopy(output, null, 6));
for (size = 0; *(str + size);)
size++;
ret += _printstrnwidth(output, flags, wid, prec, size);
prec = (prec == -1) ? size : prec;
for (i = 0; *(str + i) != '\0' && i < prec; i++)
{
for (j = 0; j < 52; j++)
{
if (*(str + i) == *(alpha + j))
{
ret += _memorycopy(output, (rot13 + j), 1);
break;
}
}
if (j == 52)
ret += _memorycopy(output, (str + i), 1);
}
ret += _printstrnwidth(output, flags, wid, prec, size);
return (ret);
}

