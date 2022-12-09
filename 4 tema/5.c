#include <stdio.h>
int main()
{
    double sum = 0;
    double biggest, smallest;
    unsigned int n;
    printf("Iveskite kiek reiksmiu bus vedama: ");
    scanf("%d",&n);
    double num[n];
    for(int i = 0; i<n; i++)
    {
        printf("%d reiksme: ",i+1);
        scanf("%lf",&num[i]);
        if(i == 0 || num[i]>biggest)biggest=num[i];
        if(i == 0 || num[i]<smallest)smallest=num[i];
        sum += num[i];
    }
    printf("\n\n\n\nSuma: %f\nVidurkis: %f\nDidziausia: %f\nMaziausia: %f",sum,sum/n,biggest,smallest);
    return 0;
}
