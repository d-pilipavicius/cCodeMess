#include <stdio.h>
int main()
{
    int nrOfValues = 1, nrOfPrime = 0;
    int arr[1000], arrOfPrime[1000];

    arr[0] = 1;

    while(arr[nrOfValues-2]>0 || nrOfValues == 1)
    {
        printf("Ivestike %d reiksme: ",nrOfValues);
        scanf("%d",&arr[nrOfValues-1]);
        nrOfValues++;
    }
    nrOfValues-=2;
    for(int i = 0; i<nrOfValues; i++)
    {
        if(arr[i]!=1)
        {
            int isItPrimeAndNotUsed = 1;
            for(int j = 2; j<arr[i]; j++)
            {
                if(arr[i]%j==0)
                {
                    isItPrimeAndNotUsed = 0;
                    break;
                }
            }
            if(isItPrimeAndNotUsed)
            {
                for(int j = 0; j<nrOfPrime; j++)
                {
                    if(arrOfPrime[j]==arr[i])
                    {
                        isItPrimeAndNotUsed = 0;
                        break;
                    }
                }
                if(isItPrimeAndNotUsed) arrOfPrime[nrOfPrime++]=arr[i];
            }
        }
    }
    for(int i = 0; i<nrOfPrime; i++)
    {
        printf("%d ",arrOfPrime[i]);
    }
    return 0;
}
