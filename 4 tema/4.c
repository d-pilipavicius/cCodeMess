#include <stdio.h>
int main()
{
    int a, b, c;
    int dbd,mbk;
    int biggest, smallest;
    printf("Iveskite a reiksme: ");
    scanf("%d",&a);
    printf("Iveskite b reiksme: ");
    scanf("%d",&b);
    printf("Iveskite c reiksme: ");
    scanf("%d",&c);
    biggest = (a>=b && a>=c) ? a : ((b>a && b>=c) ? b : c);
    smallest = (a<=b && a<=c) ? a : ((b<a && b<=c) ? b : c);
    mbk = a*b*c;
    for(int i = 1; i<=smallest; i++)
    {
        if(a%i==0 && b%i== 0 && c%i ==0) dbd = i;
    }
    for(int i = biggest; i<=mbk; i++)
    {
        if(i%a==0 && i%b==0 && i%c==0)
        {
            mbk = i;
            break;
        }
    }
    printf("DBD: %d\nMBK: %d",dbd,mbk);
    return 0;
}
