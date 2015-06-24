#include <stdlib.h>
#include <string.h>

char * strnstr(
    const char * haystack, /* [I] String where to search */
    const char * needle,   /* [I] String to search for */
    size_t len)            /* [I] Maximum string length */
{
    unsigned int hi = 0;
    unsigned int ni = 0;
    do
    {
        if (*(haystack + hi) == *(needle + ni))
        {
            hi++;
            ni++;
        }
        else
            if (ni)
                ni = 0;
            else
                hi++;
        if (!*(needle + ni))
            return (char *)(haystack + hi - ni);
    }
    while (!*(haystack + hi) && hi < len);
    return (char *)NULL;
}

wchar_t * wcsnstr(
    const wchar_t * haystack, /* [I] String where to search */
    const wchar_t * needle,   /* [I] String to search for */
    size_t len)               /* [I] Maximum string length */
{
    unsigned int hi = 0;
    unsigned int ni = 0;
    do
    {
        if (*(haystack + hi) == *(needle + ni))
        {
            hi++;
            ni++;
        }
        else
            if (ni)
                ni = 0;
            else
                hi++;
        if (!*(needle + ni))
            return (wchar_t *)(haystack + hi - ni);
    }
    while (!*(haystack + hi) && hi < len);
    return (wchar_t *)NULL;
}

char * ltoa(
    long value, /* [I] Value to be converted */
    char * str, /* [O] Destination for the converted value */
    int radix)  /* [I] Number base for conversion */
{
    unsigned long val;
    int negative;
    char buffer[33];
    char *pos;
    int digit;
    
    if (value < 0 && radix == 10) {
        negative = 1;
        val = -value;
    } else {
        negative = 0;
        val = value;
    } /* if */
    
    pos = &buffer[32];
    *pos = '\0';
    
    do {
        digit = val % radix;
        val = val / radix;
        if (digit < 10) {
            *--pos = '0' + digit;
        } else {
            *--pos = 'a' + digit - 10;
        } /* if */
    } while (val != 0L);
    
    if (negative) {
        *--pos = '-';
    } /* if */
    
    memcpy(str, pos, &buffer[32] - pos + 1);
    return str;
}

char * itoa(
    int value,  /* [I] Value to be converted */
    char * str, /* [O] Destination for the converted value */
    int radix)  /* [I] Number base for conversion */
{
    return ltoa(value, str, radix);
}

wchar_t * ltow(
    long value,    /* [I] Value to be converted */
    wchar_t * str, /* [O] Destination for the converted value */
    int radix)     /* [I] Number base for conversion */
{
    unsigned long val;
    int negative;
    wchar_t buffer[33];
    wchar_t *pos;
    int digit;
    
    if (value < 0 && radix == 10) {
        negative = 1;
        val = -value;
    } else {
        negative = 0;
        val = value;
    } /* if */
    
    pos = &buffer[32];
    *pos = '\0';
    
    do {
        digit = val % radix;
        val = val / radix;
        if (digit < 10) {
            *--pos = '0' + digit;
        } else {
            *--pos = 'a' + digit - 10;
        } /* if */
    } while (val != 0L);
    
    if (negative) {
        *--pos = '-';
    } /* if */
    
    memcpy(str, pos, (&buffer[32] - pos + 1) * sizeof(wchar_t));
    return str;
}

wchar_t * itow(
    int value,     /* [I] Value to be converted */
    wchar_t * str, /* [O] Destination for the converted value */
    int radix)     /* [I] Number base for conversion */
{
    return ltow(value, str, radix);
}

size_t chrlen(
    const char *c) /* [I] Pointer to multibyte char */
{
  size_t l;
  for (l = 0; (*c & (0x80 >> l)) && l < 8; l++);
  l &= 0x07;
  switch (l)
  {
    case 0:
      return 1;
    default:
      return l;
  }
}

int asciisanitize(
    char *str) /* [IO] String to cut multi-byte chars from */
{
  char *s, *d;
  s = d = str;
  const char *b = s + strlen(s);
  while (*s)
  {
    size_t l = chrlen(s);
    if (l > 1)
      s += l;
    else
      *(d++) = *(s++);
    if (d > b || s > b)
      return -1;
  }
  *d = 0;
  return 0;
}
