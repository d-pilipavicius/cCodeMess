#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *createArray(int size, int low, int high);

int main()
{
    return 0;
}

int *createArray(int size, int low, int high)
{
    int *arr = (int *) calloc(size,sizeof(int));
    if(low>high || size<1)
    {
        return NULL;
    }
    srand(time(NULL));
    for(int i = 0; i<size; i++)
    {
        *(arr+i) = rand()%(high-low+1)+low;
    }
    return arr;
}
