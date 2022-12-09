#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int checkIfNoMistake = 1;
    int a, b, c;
    int arr[1000];
    srand(time(NULL));
    while(checkIfNoMistake)
    {
        printf("Iveskite sugeneruojamu reiksmiu rezius: ");
        scanf("%d %d",&a,&b);
        (a<0 || b <0 || a>b) ? printf("Netinkama reiksme! Reiksmes turi priklausyti intervale [a,b],a<=b.\n") : (checkIfNoMistake = 0);
    }
    checkIfNoMistake = 1;
    while(checkIfNoMistake)
    {
        printf("Iveskite sugeneruojamu reiksmiu kieki: ");
        scanf("%d",&c);
        (c<1 || c>1000) ? printf("Netinkama reiksme! Kiekis turi priklausyti intervalui [1,1000].\n") : (checkIfNoMistake = 0);
    }
    for(int i = 0; i<c; i++)
    {
        arr[i] = rand()%(b-a+1)+a;
    }
    for(int i = 0; i<c; i++)
    {
        printf("%d reiksme: %d\n",i+1,arr[i]);
    }
    return 0;
}
