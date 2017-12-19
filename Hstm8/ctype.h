/*	CHARACTER TYPES HEADER
 *	Copyright (c) 2006 by COSMIC Software
 */

#ifndef __CTYPE
#define __CTYPE	1

/*	function declarations
 */
char isalnum(char c);
char isalpha(char c);
char iscntrl(char c);
char isdigit(char c);
char isgraph(char c);
char islower(char c);
char isprint(char c);
char ispunct(char c);
char isspace(char c);
char isupper(char c);
char isxdigit(char c);
char tolower(char c);
char toupper(char c);

/*	macro definitions
 */
#define isdigit(c)	((c) >= '0' && (c) <= '9')
#define islower(c)	((c) >= 'a' && (c) <= 'z')
#define isupper(c)	((c) >= 'A' && (c) <= 'Z')

#endif
