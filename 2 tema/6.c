#include <stdio.h>
double retVal(double a, double b, char c);
main()
{
    char what;
    double a, b, c;
    double bVal;
    printf("Iveskite pirma reiksme: ");
    scanf("%lf",&a);
    printf("Iveskite antra reiksme: ");
    scanf("%lf",&b);
    printf("Iveskite trecia reiksme: ");
    scanf("%lf",&c);
    while(getchar() != '\n')
    {
        ;
    }
    while(what != 'm' && what != 'd')
    {
        printf("Iveskite kokio skaiciaus ieskoti (didziausio - d, maziausio - m): ");
        scanf("%c",&what);
        switch(what)
        {
        default:
            printf("Netinkama reiksme!\n");
            while(getchar() != '\n')
            {
                ;
            }
            break;
        case 'm':
        case 'd':
            break;
        }
    }
    bVal = retVal(a,b, what);
    bVal = retVal(bVal,c, what);
    printf("Maziausia arba didziausia reiksme (Atitinkamai pagal pradini pasirinkima): %f",bVal);
}

double retVal(double a, double b, char c)
{
    return (c == 'd') ? ((a>b) ? a : b) : ((a<b) ? a : b);
}
