#include <stdlib.h>
#include <string.h>
#include <assert.h>

int lengthStr(char *text)
{
    int i = 0;
    while(text[i++] != '\0')
    {
        ;
    }
    return i-1;
}

int main()
{
    assert(lengthStr("Hello ") == 6);
    assert(strlen("Hello") == lengthStr("Hello"));
    assert(lengthStr("") == 0);
    return 0;
}
