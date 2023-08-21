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
int _printwidth(const char *format, int *i, va_list list);
int _printprecision(const char *format, int *i, va_list list);
int _printsize(const char *format, int *i);

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
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int _writenumber(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int _writenum(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int _writepointer(char buffer[], int ind, int length, int width,
		int flags, char padd, char extra_c, int padd_start);
int _writeunsigned(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);

/*** Utils ***/
int is_printable(char);
int is_digit(char);
int append_hexa_coder(char, char[], int);
long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);

#endif
