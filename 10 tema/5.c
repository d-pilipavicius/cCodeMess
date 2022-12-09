#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void copyMemory(void *destination, void *source, int nrOfBytes)
{
    for(int i = 0; i < nrOfBytes; ++i)
        *((char*)destination+i) = *((char*)source+i);
}

int main()
{
    int a[4] = {0,1,2,3};
    int b[6] = {32,43,54,65,99,243};
    int c[4] = {0,1,2,3};
    int d[6] = {32,43,54,65,99,243};
    memcpy(a, b, 3*sizeof(int));
    copyMemory(c, d, 3*sizeof(int));
    for(int i = 0; i < 4; ++i)
    {
        assert(a[i] == c[i]);
    }
    memcpy(a, b, 3);
    copyMemory(c, d, 3);
    for(int i = 0; i < 4; ++i)
    {
        assert(a[i] == c[i]);
    }
    memcpy(a, b, 0);
    copyMemory(c, d, 0);
    for(int i = 0; i < 4; ++i)
    {
        assert(a[i] == c[i]);
    }
    return 0;
}
