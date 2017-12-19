/*	STANDARD I/O HEADER
 *	Copyright (c) 2006 by COSMIC Software
 */

#ifndef __STDIO__
#define __STDIO__	1

#ifndef __SIZE_T__
#define __SIZE_T__	1
typedef unsigned int size_t;
#endif

/*	function declarations
 */
char getchar(void);
char *gets(char *s);
int printf(char *format, ...);
char putchar(char c);
int puts(char *s);
int scanf(char *format, ...);
int sscanf(char *s, char *format, ...);
int sprintf(char *s, char *format, ...);

/*	system parameters
 */
#define BUFSIZ 	512
#define EOF	-1

#ifndef NULL
#define NULL	(void *)0
#endif

#endif
