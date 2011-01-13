/*
 * debug.h
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifndef DEBUG_H_
#define DEBUG_H_

//#define DEBUG

#ifdef DEBUG
#include <stdio.h>
#include <stdarg.h>

#define debug_where() \
        printf("\n###FILE: %s ###LINE: %d ###FUC: %s\n", \
                                        __FILE__, __LINE__, __FUNCTION__)
static inline void debug_p(const char * format, ...)
{                                                                               
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
}

#else
#define debug_where() do { } while (0)

static inline void debug_p(const char * format, ...)
{
}

#endif


#endif /* DEBUG_H_ */
