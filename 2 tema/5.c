#include <stdio.h>
#include <math.h>

main()
{
    char task = ' ';
    double x, y, z;
    double ats;
    while(task != 'a' && task != 'b')
    {
        printf("Irasykite uzduoti (a arba b): ");
        scanf("%s", &task);
        if(task != 'a' && task != 'b')
        {
            printf("Netinkama ivestis, pasirinkite a arba b.\n");
            while(getchar() != '\n')
            {
                ;
            }
        }
    }
    printf("Irasykite x: ");
    scanf("%lf", &x);
    printf("Irasykite y: ");
    scanf("%lf", &y);
    printf("Irasykite z: ");
    scanf("%lf", &z);
    ats = (task == 'a') ? x+4*y+z*z*z : (x+sqrt(y))*(z*z*z*z-abs(z)+46.3);
    printf("Atsakymas: %f", ats);
}
