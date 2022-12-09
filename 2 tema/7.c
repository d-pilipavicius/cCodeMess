#include <stdio.h>
main()
{
    char howToSort;
    unsigned long int sk, skTemp;
    unsigned long int skDyd = 0, decTemp = 10;
    while(howToSort != 'm' && howToSort != 'd')
    {
        printf("Pasirinkite kaip isrikiuoti skaiciu (m - mazejanciai, d - didejanciai): ");
        scanf("%c",&howToSort);
        if(howToSort != 'm' && howToSort != 'd')
        {
            printf("Netinkama reiksme!\n");
            while(getchar() != '\n')
            {
                ;
            }
        }
    }
    printf("Iveskite skaiciu: ");
    scanf("%d",&sk);
    while(skTemp != sk)
    {
        skTemp = sk%decTemp;
        decTemp *= 10;
        skDyd++;
    }
    for(int i = 0; i<skDyd-1; i++)
    {
        for(int j = i+1; j<skDyd; j++)
        {
            skTemp = pow(10,skDyd-i-1);
            skTemp = sk/skTemp%10;
            decTemp = pow(10,skDyd-j-1);
            decTemp = sk/decTemp%10;
            if(howToSort == 'd')
            {
                if(skTemp>decTemp)
                {
                    int temp;
                    temp = pow(10,skDyd - i - 1);
                    sk = sk + temp*(decTemp - skTemp);
                    temp = pow(10,skDyd - j - 1);
                    sk = sk + temp*(skTemp - decTemp);
                }
            }
            else
            {
                if(skTemp<decTemp)
                {
                    int temp;
                    temp = pow(10,skDyd - i - 1);
                    sk = sk + temp*(decTemp - skTemp);
                    temp = pow(10,skDyd - j - 1);
                    sk = sk + temp*(skTemp - decTemp);
                }
            }
        }
    }
    printf("%d",sk);
}
