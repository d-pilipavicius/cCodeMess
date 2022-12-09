#include <stdio.h>
#include <math.h>
main()
{
    char fromWhatSys = ' ', toWhatSys = ' ';
    int part = 1;
    unsigned long int scannedVal, valToPrint = 0;

    while(part !=3)
    {
        switch(part)
        {
        case 1:
            printf("Iveskite is kokios sistemos vyks konvertacija (b - binary, d - decimal, h - hexdecimal): ");
            scanf("%c",&fromWhatSys);
            if(fromWhatSys == 'b' || fromWhatSys == 'd' || fromWhatSys == 'h')
            {
                part++;
                while(getchar() != '\n')
                {
                    ;
                }
            }
            else
            {
                printf("Netinkama reiksme!\n");
                while(getchar() != '\n')
                {
                    ;
                }
            }
            break;
        case 2:
            printf("Iveskite i kokia sistema vyks konvertacija (b - binary, d - decimal, h - hexdecimal): ");
            scanf("%c",&toWhatSys);
            if(toWhatSys == 'b' || toWhatSys == 'd' || toWhatSys == 'h')
            {
                if(fromWhatSys != toWhatSys)
                {
                    part++;
                    while(getchar() != '\n')
                    {
                        ;
                    }
                }
                else
                {
                    printf("Sistemos negali sutapti!\n");
                    while(getchar() != '\n')
                    {
                        ;
                    }
                }
            }
            else
            {
                printf("Netinkama reiksme!\n");
                while(getchar() != '\n')
                {
                    ;
                }
            }
            break;
        }
    }

    printf("Irasykite skaiciu: ");

    switch(fromWhatSys)
    {
    case 'b':
        scanf("%d",&scannedVal);
        int lngOfBin=1;
        while(scannedVal/pow(10,lngOfBin)!=0) lngOfBin++;
        for(int i = 0; i<lngOfBin; i++)
        {
            int temp_10 = pow(10,i);
            int temp_2 = pow(2,i);
            if(scannedVal/temp_10%10 == 1) valToPrint += temp_2;
        }
        break;
    case 'd':
        scanf("%d",&scannedVal);
        break;
    case 'h':
        scanf("%x",&scannedVal);
        break;
    }
    printf("Reiksme pasirinkta sistema: ");
    int tempCase_1 = 0;
    switch(toWhatSys)
    {
    case 'b':

        while(scannedVal!= 0)
        {
            valToPrint += scannedVal%2*pow(10,tempCase_1);
            scannedVal /= 2;
            tempCase_1++;
        }
        printf("%d",valToPrint);
        break;
    case 'd':
        if(fromWhatSys != 'b') valToPrint = scannedVal;
        printf("%d",valToPrint);
        break;
    case 'h':
        if(fromWhatSys != 'b') valToPrint = scannedVal;
        printf("%x",valToPrint);
        break;
    }
}


