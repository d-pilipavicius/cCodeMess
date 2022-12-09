#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b);

int main()
{
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
