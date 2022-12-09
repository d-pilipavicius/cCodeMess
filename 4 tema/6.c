#include <stdio.h>
#include <math.h>

int main()
{
    int i = 0, savedVal = 0;
    double temp, biggest;
    double num[99999];
    num[i] = 999999;
    while(num[i]>0)
    {
        printf("Reiksme %d: ",i+1);
        scanf("%lf",&num[i]);
        if(num[i]<=0) break;
        num[++i] = 9999999;
    }
    i = 0;
    temp = num[i];
    while((temp-floor(temp)!=0))temp*=10;
    biggest = temp;
    while(num[++i]>0)
    {
        temp = num[i];
        while(temp-floor(temp)!=0){printf("%f\n",temp-floor(temp)); temp*=10;}
        if(temp > biggest)
        {
            biggest = temp;
            savedVal = i;
        }
    }
    printf("Daugiausia skaitmenu turi: %f",num[savedVal]);
    return 0;
}
