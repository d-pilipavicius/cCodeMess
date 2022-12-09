#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define ARR_SIZE 1000

void copyString(char *destination, char *textToCopy)
{
    for(int i = 0; i < strlen(textToCopy)+1; ++i)
        destination[i] = textToCopy[i];
}

int main()
{
    char a[ARR_SIZE];
    char b[ARR_SIZE];
    strcpy(a, "hello");
    copyString(b, "hello");
    assert(strcmp(a, b) == 0);
    assert(strcmp(b, "hello") == 0);
    strcpy(a, "");
    copyString(b, "");
    assert(strcmp(a, b) == 0);
    assert(strcmp(b, "") == 0);
    return 0;
}
