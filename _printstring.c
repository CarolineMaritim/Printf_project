#include "main.h"
/**
 * _printstring - prints a string to stdout
 * @str: pointer to the string
 */
void _printstring(char *str)
{
	int i = 0;

	while (str[i])
	{
		_printchar(str[i]);
		i++;
	}
	_printchar("\n");
}
