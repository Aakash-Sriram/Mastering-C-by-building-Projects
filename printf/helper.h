#ifndef __HELPER_H_
#define __HELPER_H_

#include <unistd.h>
#include <stdarg.h>

#define my_putchar(x) write(1,chardup(x),1)

#define Wait4Char 1

#define Wait4Fmt  2

#endif

typedef unsigned char State;

unsigned int my_strlen(const char *str);
int puts(const  char *str);
char *chardup(const char ch);
