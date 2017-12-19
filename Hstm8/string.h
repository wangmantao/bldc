/*	STRING TYPES HEADER
 *	Copyright (c) 2006 by COSMIC Software
 */

#ifndef __STRING__
#define __STRING__	1

#ifndef NULL
#define NULL	(void *)0
#endif

#ifdef NOINLINE
#define _INLINE
#else
#define _INLINE @inline
#endif

/*	function declarations
 */
char *strcat(char *s1, char *s2);
char *strchr(char *s, char c);
char * _INLINE strcpy(char *s1, char *s2);
char *strncat(char *s1, char *s2, unsigned int n);
char *strncpy(char *s1, char *s2, unsigned int n);
char *strpbrk(char *s1, char *s2);
char *strrchr(char *s, char c);
char *strstr(char *s1, char *s2);
int memcmp(void *s1, void *s2, unsigned int n);
int strcmp(char *s1, char *s2);
int strncmp(char *s1, char *s2, unsigned int n);
unsigned int strcspn(char *s1, char *s2);
_INLINE unsigned int strlen(char *s);
unsigned int strspn(char *s1, char *s2);
void *memchr(void *s, char c, unsigned int n);
void * _INLINE memcpy(void *s1, void *s2, unsigned int n);
void *memmove(void *s1, void *s2, unsigned int n);
void * _INLINE memset(void *s, char c, unsigned int n);

void eepcpy(@eeprom void *s1, void *s2, unsigned int n);
void eepset(@eeprom void *s1, char c, unsigned int n);
#define eepera(s1, n)	(eepset(s1, 0, n))

#endif
