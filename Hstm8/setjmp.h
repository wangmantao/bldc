/*	SETJMP/LONGJMP HEADER
 *	Copyright (c) 2006 by COSMIC Software
 */

#ifndef __SETJMP__
#define __SETJMP__	1

/*	size of info
 */
#define _JMPSIZ	5

/*	type declaration
 */
typedef char jmp_buf[_JMPSIZ];

/*	function declarations
 */
int setjmp(jmp_buf env);
void longjmp(jmp_buf env, int val);

#endif
