#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


void copyStringFixed(char *destination, char *textToCopy, int sizeOfCopy)
{
    for(int i = 0; i < sizeOfCopy; ++i)
        destination[i] = textToCopy[i];
}
int main()
{
    char a[2][5];
    char b[2][10];
    strncpy(a[0], "abcd", sizeof(a[0]));
    strncpy(b[0], "123456789", sizeof(b[0]));
    copyStringFixed(a[1], "abcd", sizeof(a[0]));
    copyStringFixed(b[1], "123456789", sizeof(b[0]));
    assert(strncmp(a[0], a[1], sizeof(a[0])) == 0);
    assert(strncmp(b[0], b[1], sizeof(b[0])) == 0);
    strncpy(a[0], "J1jkhj13K", 3);
    strncpy(b[0], "0f1sd", 2);
    copyStringFixed(a[1], "J1jkhj13K", 3);
    copyStringFixed(b[1], "0f1sd", 2);
    assert(strncmp(a[0], a[1], 3) == 0);
    assert(strncmp(b[0], b[1], 2) == 0);
    strncpy(a[0], "J1jkhj13K", 0);
    strncpy(b[0], "0f1sd", 0);
    copyStringFixed(a[1], "J1jkhj13K", 0);
    copyStringFixed(b[1], "0f1sd", 0);
    assert(strncmp(a[0], a[1], 0) == 0);
    assert(strncmp(b[0], b[1], 0) == 0);
    return 0;
}
