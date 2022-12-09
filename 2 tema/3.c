#include <stdio.h>
main()
{
    int scannedVar;
    printf("Iveskite skaiciu: ");
    scanf("%d", &scannedVar);
    printf("%d yra %s.", scannedVar, (scannedVar%2==0) ? "lyginis" : "nelyginis");
}
