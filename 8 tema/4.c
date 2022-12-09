#include <stdio.h>
#include <stdlib.h>
int splitData(double *arrWhole, int arrSize, int firstSize, double **arrOne, double **arrTwo);

int main()
{
    return 0;
}

int splitData(double *arrWhole, int arrSize, int firstSize, double **arrOne, double **arrTwo)
{
    if(arrWhole==NULL || arrSize<1 || firstSize<0 || *arrOne!=NULL || *arrTwo!=NULL || firstSize>arrSize)
    {
        return -1;
    }
    *arrOne = (double*)calloc(firstSize,sizeof(double));
    *arrTwo = (double*)calloc(arrSize-firstSize,sizeof(double));
    for(int i = 0; i<firstSize; ++i)
    {
        **(arrOne+i) = *(arrWhole+i);
    }
    for(int i = firstSize; i<arrSize; ++i)
    {
        **(arrTwo+i-firstSize) = *(arrWhole+i);
    }
    return 0;
}
