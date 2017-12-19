/*	VARIABLE ARGUMENT LIST HEADER
 *	Copyright (c) 2006 by COSMIC Software
 */

#ifndef __STDARG__
#define __STDARG__	1

/*	type declarations
 */
typedef char *va_list;

/*	macro declarations
 */
#define va_start(ap, arg) ((ap) = (@near char *)&(arg) + sizeof(arg))
#define va_arg(ap, ty) ((ap) += sizeof @(ty), *(ty *)((ap) - sizeof(ty)))
#define va_end(ap) ap

/*	io functions using va_list
 */
int vprintf(char *format, va_list ap);
int vsprintf(char *s, char *format, va_list ap);

#endif
