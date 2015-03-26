#include <stdlib.h>

char * strnstr(const char * haystack, const char * needle, size_t len)
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