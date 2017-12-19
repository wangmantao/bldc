/*	SHORT STACK MODEL FOR STM8 COMPILER
 *	Copyright (c) 2006 by COSMIC Software
 */
#pragma space () @far
#pragma space [] @tiny
#pragma space auto [] @near
#pragma space * @near
#pragma space * () @far
#pragma space const @near

#define __MODS__	1
