#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s)
{
    unsigned int i = 0;

    while (s[i] != '\0')
    {
        i++;
    }

    return i;
}

bool fstring_eq(fixstring s1, fixstring s2)
{
    bool res = true;
    unsigned int i = 0;

    if (fstring_length(s1) != fstring_length(s2))
    {
        return res = false;
    }

    while (s1[i] != '\0' && s2[i] != '\0' && res)
    {
        res = s1[i] == s2[i];
        i++;
    }

    return res;
}

bool fstring_less_eq(fixstring s1, fixstring s2)
{
    bool res = false;
    unsigned int i = 0;

    if (fstring_length(s1) > 0u && fstring_length(s2) > 0u)
    {
        if (fstring_length(s1) < fstring_length(s2) && s1[0] <= s2[0])
        {
            return res = true;
        }

        while (s1[i] != '\0' && s2[i] != '\0')
        {
            if (s1[i] < s2[i] && s1[i] != s2[i])
            {
                return res = true;
            }
            else if (s1[i] > s2[i])
            {
                return res = false;
            }

            i++;
        }
    }

    return res;
}