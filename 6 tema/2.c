#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE *fr;
    int fileNotReadYet = 1;
    char number[1000] = {0};
    int numberFromChar[2];
    int filteredNumber = 0;
    printf("Si programa paima realu skaiciu is dokumento \"in.txt\" ir isveda jo ilgi.\n"
           "Skaicius turi priklausyti intervalui [10,1000] ir negali tureti daugiau 3 skaitmenu po kablelio.\n"
           "Skaiciaus kablelis zymimas ne simboliu '.', o simboliu ','.\n"
           "Jei dokumente \"in.txt\" neranda tinkamos reiksmes, programa praso kito tinkamo failo, kol randa tinkama reiksme.\n\n");
    printf("Bandomas atidaryti failas \"in.txt\".\n");
    fr = fopen("in.txt","r");
    if(fr)
        printf("Failas sekmingai atidarytas.\n");
    else
    {
        while(!fr)
        {
            char newFileName[100];
            printf("Failas nepasiekiamas! Prasome ivesti kita faila, kuris butu atidaromas: ");
            scanf("%s",newFileName);
            while(getchar() != '\n')
                {
                    ;
                }
            fr = fopen(newFileName,"r");
            if(fr)
                printf("\"%s\" sekmingai atidarytas.",newFileName);
        }
    }
    while(fileNotReadYet)
    {
        int errorWhileReading = 0;
        int writtenToChar = 0,endOfNumbers1 = -1, endOfNumbers2 = -1;
        char nrBehindDecimal[1000]= {0},nrInFrontOfDecimal[1000]= {0};
        numberFromChar[0] = 0;
        numberFromChar[1] = 0;
        printf("Nuskaitomi failo duomenys.\n");
        fscanf(fr,"%c",&number[writtenToChar++]);
        while(number[writtenToChar-1]!=EOF)
        {
            number[writtenToChar++] = fgetc(fr);
        }
        for(int i = 0; i<writtenToChar; i++)
        {
            if(number[i] > '9' || number[i]<'0' && number[i]!=',' && number[i]!=EOF)
            {
                fclose(fr);
                errorWhileReading = 1;
                break;
            }
            else if(endOfNumbers1 == -1 && (number[i] == EOF || number[i] == ','))
            {
                endOfNumbers1 = i;
                if(number[i] == EOF)
                    break;
            }
            else if(endOfNumbers1 != -1 && number[i] == EOF)
            {
                endOfNumbers2 = i;
                break;
            }
        }
        if(!errorWhileReading)
        {
            for(int i = 0; i<endOfNumbers1; i++)
            {
                nrBehindDecimal[i] = number[i];
            }
            numberFromChar[0] = atoi(nrBehindDecimal);
            for(int i = endOfNumbers1+1; i<endOfNumbers2; i++)
            {
                nrInFrontOfDecimal[i-endOfNumbers1-1] = number[i];
            }
            numberFromChar[1] = atoi(nrInFrontOfDecimal);

            while(numberFromChar[1]%10==0 && numberFromChar[1]!=0)
            {
                numberFromChar[1]%=10;
            }
        }
        if(numberFromChar[0]>1000 || numberFromChar[1]>999)
        {
            fclose(fr);
            errorWhileReading = 1;
        }
        if(!errorWhileReading)
        {
            fileNotReadYet = 0;
        }
        else
        {
            while(errorWhileReading)
            {
                char newFileName[100];
                printf("Faile yra netinkamu reiksmiu!\n"
                       "Patikrinkite, ar ivestas skaicius priklauso intervalui [10,1000].\n"
                       "Patikrintike, ar ivesti duomenys neturi simboliu tarp ju.\n"
                       "Patikrinkite, ar yra iki 3 skaiciu po kablelio.\n"
                       "Prasome ivesti kita faila, kuriame yra tinkamos reiksmes: ");
                scanf("%s",newFileName);
                while(getchar() != '\n')
                {
                    ;
                }
                fr = fopen(newFileName,"r");
                if(fr)
                {
                    printf("\"%s\" sekmingai atidarytas.\n",newFileName);
                    errorWhileReading = 0;
                }
            }
        }
    }
    printf("Duomenys atitiko visus reikalavimus.\n");
    printf("Ivesto skaiciaus ilgis: %d",(numberFromChar[1]==0) ? ((numberFromChar[0]==0) ? 1 : (int) log10(numberFromChar[0])+1) : ((numberFromChar[0] == 0) ? (int) log10(numberFromChar[1])+2 : (int) log10(numberFromChar[0]*numberFromChar[1])+2));
    return 0;
}
