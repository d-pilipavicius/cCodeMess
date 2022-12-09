#include <stdio.h>
#include <math.h>


int main()
{
     int a, b, c;
     double det;
     printf("Iveskite reiksme a: ");
     scanf("%d",&a);
     if(a == 0)
     {
         printf("Kvadratine lygtis neegzistuoja! (a negali buti lygus 0)");
         return 0;
     }
     printf("Iveskite reiksme b: ");
     scanf("%d",&b);
     printf("Iveskite reiksme c: ");
     scanf("%d",&c);
     det = b*b-4*a*c;
     if(det<0)
         printf("Lygtis sprendiniu neturi.");
     else if(det == 0)
         printf("Lygtis turi sprendini: %f",-b/2/a);
     else
        printf("Lygtis turi du sprendinius: %f ir %f",-(sqrt(det)+b)/2/a,(sqrt(det)-b)/2/a);
     return 0;
}
