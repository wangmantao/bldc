/*	PROGRAM ASSERTION HEADER
 *	Copyright (c) 2006 by COSMIC Software
 */
#undef assert
#ifndef NDEBUG
#define assert(expr) \
	{ \
	if (!(expr)) \
		{ \
		printf("\nassert error at %s:%d\n", \
			__FILE__, __LINE__), \
		exit(0); \
		} \
	}
#else
#define assert(expr)
#endif
