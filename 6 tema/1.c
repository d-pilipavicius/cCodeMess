#include <stdio.h>

int main()
{
    FILE * fp;
    double nr;
    long int factorial = 1;
    int textUnread = 1;
    while(textUnread)
    {
        printf("Iveskite teigiama sveika skaiciu, kurio faktoriala norite apskaiciuoti: ");
        if(scanf("%lf",&nr)==1 && getchar()=='\n')
        {
            if(nr<=0)
            {
                printf("Skaicius negali buti neteigiamas!\n");
            }
            if(nr!=(int)nr)
            {
                printf("Skaicius negali tureti skaitmenu po kablelio!\n");
            }
            else if(nr>0)
            {
                textUnread = 0;
                break;
            }
        }
        else
        {
            printf("Negalima ivesti simbolio reiksmes!\n");
            while(getchar()!='\n')
            {
                ;
            }
        }
    }
    fp = fopen("out.txt","w");
    while(nr!=1)
    {
        factorial *= nr--;
    }
    printf("Irasyto sk faktorialas: %d",factorial);
    fprintf(fp,"%d",factorial);
    return 0;
}
