#include "main.h"
/**
 * _printnum - Prints Number
 * @n: Number being checked
 */
void _printnum(int n);
{
if (n < 0)
{
_printchar('-');
n = -n;
}
if (n < 10)
{
_printchar(n + '0');
}
else
_printnum(n / 10);
_printchar((n % 10) + '0');
}
