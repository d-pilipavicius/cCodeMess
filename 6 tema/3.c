#include <stdio.h>

int main()
{
    int isNotCorrect = 1, medianVal;
    int nr[3] = {0};
    char createdFileName[100];
    FILE *fr;
    printf("Sioje programoje reikia ivesti tris sveikus skaicius, be tarpu, atskirtus kabliataskiais.\n"
           "Programa tada ras siu skaiciu vidurine reiksme ir isves ja i pasirinka faila.\n"
           "Rasant failo pavadinima isitikintike, kad nurodete ir jo tipa, kuris privalo buti \".txt\".\n\n"
           "Iveskite duomenis: ");
    while(isNotCorrect)
    {
        if(scanf("%d;%d;%d",&nr[0],&nr[1],&nr[2])==3 && getchar()=='\n')
        {
            isNotCorrect = 0;
            printf("Duomenys ivesti teisingai. Prasome ivesti tekstinio dokumento pavadinima: ");
        }
        else
        {
            while(getchar()!='\n')
            {
                ;
            }
            printf("Neteisingai ivesti duomenys! Prasome ivesti juos is naujo: ");

        }

    }
    isNotCorrect = 1;
    while(isNotCorrect)
    {
        int badInput = 1;
        int textLength = 0;
        scanf("%s",createdFileName);
        for(int i = 0; createdFileName[i]!='\0'; i++)
        {
            textLength = i+1;
        }
        for(int i = 0; i<textLength; i++)
        {
            if(textLength-i<4)
            {
                break;
            }
            else if(createdFileName[i]!='.')
            {
                continue;
            }
            else if(createdFileName[i]=='.' && createdFileName[i+1]=='t' && createdFileName[i+2]=='x' && createdFileName[i+3] == 't' && createdFileName[i+4] == '\0')
            {
                badInput = 0;
                break;
            }
            else
                continue;
        }
        if(badInput)
        {
            printf("Neteisingai ivestas failo pavadinimas! Iveskite pavadinima su \".txt\" priedu: ");
        }
        else
        {
            badInput = 0;
            for(int i = 0; createdFileName[i]!='\0'; i++)
            {
                switch(createdFileName[i])
                {
                case '\\':
                case '/':
                case ':':
                case '*':
                case '?':
                case '"':
                case '<':
                case '>':
                case '|':
                    badInput = 1;
                    printf("Failo pavadinime yra simboliu, kuriu buti negali (\\/:*?\"<>|). Iveskite tinkama pavadinima: ");
                    break;
                default:
                    continue;
                }
                break;
            }
            if(!badInput)
            {
                isNotCorrect = 0;
            }
        }
    }
    medianVal = (nr[0]>nr[1]) ? ((nr[0]>nr[2]) ? ((nr[2]>nr[1]) ? nr[2] : nr[1]) : nr[0]) : ((nr[1]>nr[2]) ? ((nr[0]>nr[2]) ? nr[0] : nr[2]) : nr[1]);
    fr = fopen(createdFileName,"w");
    fprintf(fr,"%d\n",medianVal);
    printf("Programa darba baige. Rezultatas patalpintas dokumente \"%s\".",createdFileName);
    return 0;
}
