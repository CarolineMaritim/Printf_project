#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
/* Flag  Macros */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)
/* Length Macros */
#define SHORT 1
#define LONG 2
/**
 * struct buffer_s - A new type defining a buffer struct.
 * @buffer: A pointer to a character array.
 * @start: A pointer to the start of buffer.
 * @len: The length of the string stored in buffer.
 */
typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_t;
/**
 * struct converter_s - A new type defining a converter struct.
 * @specifier: A character representing a conversion specifier.
 * @func: A pointer to a conversion function corresponding to specifier.
 */
typedef struct converter_s
{
	unsigned char specifier;
	unsigned int (*func)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);
} converter_t;
/**
 * struct flag_s - A new type defining a flags struct.
 * @flag: A character representing a flag.
 * @value: The integer value of the flag.
 */
typedef struct flag_s
{
	unsigned char flag;
	unsigned char value;
} flag_t;
int _printf(const char *format, ...);
/* Conversion Specifier Functions */
unsigned int _convertchar(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int_converttostring(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int _converttosignedint(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int _convertpercent(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int _converttobinary(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int _converttodecimal(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int _converttooctal(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int _convertunsignedtohex(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int _convertunsignedtoupperhex(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int_converttostrn(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int _convertpointertohex(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int _converttorev(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int_converttoRot13(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
/* Handlers */
unsigned char _handleflags(const char *flags, char *index);
unsigned char _handlelen(const char *modifier, char *index);
int _handlewidth(va_list args, const char *modifier, char *index);
int _handleprecision(va_list args, const char *modifier, char *index);
unsigned int (*_handlespecifiers(const char *specifier))(va_list, buffer_t *,
		unsigned char, int, int, unsigned char);
/* Modifiers */
unsigned int _printwidth(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);
unsigned int _printstrnwidth(buffer_t *output,
		unsigned char flags, int wid, int prec, int size);
unsigned int _printnegwidth(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);
/* Memory management */
buffer_t *init_buffer(void);
void free_buffer(buffer_t *output);
unsigned int _memorycopy(buffer_t *output, const char *src, unsigned int n);
unsigned int _convertsignedbase(buffer_t *output, long int num, char *base,
		unsigned char flags, int wid, int prec);
unsigned int _convertunsignedbase(buffer_t *output, unsigned long int num, char *base,
		unsigned char flags, int wid, int prec);
#endif /* MAIN_H */

