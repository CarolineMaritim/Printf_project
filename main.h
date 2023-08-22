#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/* Sizes */
#define SIZE_SHORT 1
#define SIZE_LONG 2

/* Flags */
#define FLAG_PLUS 2
#define FLAG_MINUS 1
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/**
  * struct format - struct op
  * @fmt: format
  * @fn: function associated
  */
struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
  * typedef struct fmt fmt_t - Struct op
  * @fm_t: associated function
  */
typedef struct format format_t;

int _printf(const char *format, ...);
int _printhandlers(const char *format, int *i, va_list,
		char buffer[], int flags, int width, int precision, int size);

/*** Functions ***/

/* print number functions */
int _printint(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int _printbinary(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int _printunsigned(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int _printoctal(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int _printhexadecimal(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int _printhexaupper(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int _printhexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size);

/* print char and string functions */
int _printchar(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _printstring(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _printpercent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* functions to handle other specifiers */
int _getflags(const char *format, int *i);
int _printwidth(const char *format, int *num, va_list args);
int _printprecision(const char *format, int *num, va_list args);
int _printsize(const char *format, int *num);

/* function for printing non printable chars */
int _print_nonprintable(va_list types, char buffer[], int flags,
			int width, int precision, int size);

/* printing memory address function */
int _printpointer(va_list types, char buffer[], int flags,
	int width, int precision, int size);

/* function to print string in rot 13 */
int _printrot13string(va_list types, char buffer[], int flags,
	int width, int precision, int size);
/* function to print string in reverse */
int _printreverse(va_list types, char buffer[], int flags,
	int width, int precision, int size);

/* width handler */
int _writechar(char c, char b[], int f, int w,
                int p, int s);
int _writenumber(int negative_int, int num, char b[],
	int f, int w, int p, int s);
int _writenum(int num, char b[], int f, int w, int p,
	int len, char pad, char ch);
int _writepointer(char b[], int num, int len, int w,
		int f, char pad, char ch, int pad_start);
int _writeunsigned(int negative_num, int num, char b[],
		int f, int w, int p, int s);

/*** Utils ***/
int _isprintable(char c);
int _isdigit(char c);
int _gethexacode(char ac, char buffer[], int index);
long int _convertnumsize(long int n, int size);
long int _convertunsignednum(unsigned long int num, int size);

#endif
