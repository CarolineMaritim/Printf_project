#include <unstd.h>
/**
 * _printchar - Prints character to stdout
 * @c: Character checked
 * Return: The character
 */
int _printchar(char c);
{
return write(1, &c, 1);
}
