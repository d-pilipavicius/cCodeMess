include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

char *stringString(char *str1, char *str2)
{
    for(int i = 0; i < strlen(str1); ++i)
        if(strncmp(str1+i, str2, strlen(str2)) == 0)
            return str1+i;
    return NULL;
}


int main()
{
    assert(strstr("abcd", "bc") == stringString("abcd", "bc"));
    assert(strstr("12345", "bc") == stringString("12345", "bc"));
    assert(strstr("abcd", "12345") == stringString("abcd", "12345"));
    assert(strstr("12345", "234") == stringString("12345", "234"));
    assert(strstr("abcd", "") == stringString("abcd", ""));
    assert(strstr("", "bc") == stringString("", "bc"));
    return 0;
}
