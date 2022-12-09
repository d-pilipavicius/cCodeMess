#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Iveskite reiksme a: ");
    scanf("%d",&a);
    printf("Iveskite reiksme b: ");
    scanf("%d",&b);
    if(a>=b)
    {
        printf("a turi buti mazesnis uz b!");
        return 0;
    }
    printf("Iveskite reiksme c: ");
    scanf("%d",&c);
    for(int i = a+1; i<=b; i++)
    {
        if(i%c==1) printf("%d\n",i);
    }
    return 0;
}
