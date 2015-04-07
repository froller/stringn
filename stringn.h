#ifndef __STRINGN_H__
#define __STRINGN_H__

#include <stdlib.h>

char * strnstr(const char * haystack, const char * needle, size_t len);
wchar_t * wcsnstr(const wchar_t * haystack, const wchar_t * needle, size_t len);

char * itoa(int, char *, int);
char * ltoa(long, char *, int);
wchar_t * itow(int, wchar_t *, int);
wchar_t * ltow(long, wchar_t *, int);

#endif
