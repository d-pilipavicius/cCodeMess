#include <stdio.h>
int main()
{
    unsigned int temp; //Used to hold temporary sequence value
    unsigned int a, b, c;
    printf("Iveskite a reiksme: ");
    scanf("%d",&a);
    printf("Iveskite b reiksme: ");
    scanf("%d",&b);
    printf("Iveskite c reiksme: ");
    scanf("%d",&c);
    for(int i = 1;i<c; i++)
    {
        temp = b;
        b += a;
        a = temp;
    }
    printf("%d sekos reiksme: %d",c,b);
    return 0;
}
