#include <stdio.h>
int main()
{
    int amountOfCorrectAns = 0;
    int checkIfNoMistake = 1;
    int s, n;
    int arr[1000];
    while(checkIfNoMistake)
    {
        printf("Iveskite dvi reiksmes: ");
        scanf("%d %d",&s,&n);
        (s<0 || s>1000000 || n<1 || n>1000) ? printf("Netinkama reiksme! Pirma reiksme gali priklausyti intervalui [0,10^6], antra [1,1000].\n") : (checkIfNoMistake = 0);
    }
    for(int i = 0; i<n; i++)
    {
        checkIfNoMistake=1;
        while(checkIfNoMistake)
        {
            printf("Iveskite %d reiksme: ",i+1);
            scanf("%d",&arr[i]);
            (arr[i]<1) ? printf("Netinkama reiksme!\n") : (checkIfNoMistake = 0);
        }
    }
    for(int i = 0; i<n-1; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(arr[i]*arr[j]==s)
            {
                printf("%d nariu pora: %d %d\n",++amountOfCorrectAns,arr[i],arr[j]);
            }
        }
    }
    if(amountOfCorrectAns==0)printf("Tokiu nariu nera!");
    return 0;
}
