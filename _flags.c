#include "main.h"

/**
 * _getflags - Checks current flags
 * @format: Pointer to format string
 * @num: Pointer to the parameter
 *
 * Return: The flags
 */

int _getflags(const char *format, int *num)
{
const char ch_flags[] = {'-', '+', '0', '#', ' ', '\0'};
const int arrayflags[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
int j;
int current_index;
int flags = 0;
/*loop through the format current index*/
for (current_index = *num + 1; format[curent_index]; current_index++)
{
/*inner for loop to check the flag array*/
for (j = 0; ch_flags[j]; current_index++)
/*check current format index with flag array*/
	if (format[current_index] == ch_flags[j])
	{
		/*bitwise operation*/
		flags |= arrayflags[j];
		break;
	}
if (ch_flags[j] == 0)
	break;
}
*num = current_index - 1;
return (flags);
}
