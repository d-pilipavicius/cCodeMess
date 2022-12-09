#include <stdio.h>

int main()
{
    FILE *fr;
    int hasNotBeenRead = 1;
    int year,month,day;
    int calcYear=1000,calcMonth=1,whatDayOfWeek = 2; // whatDayOfWeek nustatytas i 2, nes 1000-01-01 data buvo treciadienis, o 2 masyvo elementas atitinka treciadieni.
    char dayOfWeek[7][100];

    printf("Si programa nuskaito vartotojo ivesta data formatu YYYY-MM-DD ir isveda kuri savaites diena tai yra.\n"
           "Visi nuskaityti skaiciai turi buti sveiki ir teigiami.\n"
           "Savaites dienu pavadinimus programa randa faile \"week.txt\".\n\n");
    while(hasNotBeenRead)
    {
        printf("Iveskite data, kurios savaites diena norite suzinoti, pavidalu YYYY-MM-DD: ");
        if(scanf("%d-%d-%d",&year,&month,&day) == 3 && getchar() == '\n')
        {
            if(year<1000 || year>9999)
            {
                printf("Tokie metai egzistuoti negali! Metu intervalas yra [1000,9999].\n");
            }
            else if(month < 1 || month >12)
            {
                printf("Toks menuo egzistuoti negali! Menesio intervalas yra [1,12].\n");
            }
            else if(day>31 || day<1)
            {
                printf("Tokia diena egzistuoti negali! Dienos intervalas yra [1,31] (kartais [1,30] arba [1,29] arba [1,28]).\n");
            }
            else if(((month%2==1 && month>8) || (month%2==0 && month<7 && month != 2)) && day >30)
            {
                printf("Tokia kombinacija egzistuoti negali! %d menesi dienu intervalas yra [1,30].\n",month);
            }
            else if((year%4!=0 || year%100==0 && year%400!=0) && month == 2 && day>28)
            {
                printf("Tokia kombinacija egzistuoti negali! 2 menesi dienu intervalas %d metais yra [1,28].\n",year);
            }
            else if((year%4==0 && year%100 != 0 || year%400 == 0) && month == 2 && day>29)
            {
                printf("Tokia kombinacija egzistuoti negali! 2 menesi dienu intervalas %d metais yra [1,29].\n",year);
            }
            else
            {
                printf("Sekmingai priimta data. Ieskomas \"week.txt\" failas.\n");
                hasNotBeenRead = 0;
            }
        }
        else
        {
            printf("Netinkamas datos formatas!\n");
        }
    }

    fr = fopen("week.txt","r");
    if(fr)
    {
        for(int i = 0; i<7; i++)
        {
            fscanf(fr,"%s\n",&dayOfWeek[i]);
        }
        printf("Failas nuskaitytas.\n\n");
        fclose(fr);
    }
    else
    {
        printf("\"week.txt\" nebuvo rasta! Prasome sukurti faila \"week.txt\" ir pradeti programa is naujo.\n");
        return 0;
    }
    while(calcYear!=year)
    {
        if(calcYear%4==0 && calcYear%100!=0 || calcYear%400 == 0)
            whatDayOfWeek += 2; // 2, nes 366%7 = 2.
        else
            whatDayOfWeek++; //++, nes 365%7 = 1.
        calcYear++;
        whatDayOfWeek%=7;
    }
    while(calcMonth!=month)
    {
        if((calcMonth%2==1 && calcMonth>8) || (calcMonth%2==0 && calcMonth<7 && calcMonth != 2))
        {
            whatDayOfWeek += 2; // 2, nes 30%7 = 2.
        }
        else if((calcMonth%2==1 && calcMonth<8) || (calcMonth%2==0 && calcMonth>7))
        {
            whatDayOfWeek += 3; // 3, nes 31%7 = 3.
        }
        else if((calcYear%4==0 && calcYear%100!=0 || calcYear%400 == 0) && calcMonth == 2)
        {
            whatDayOfWeek++; // 1, nes 29%7 = 1.
        } //Nereikia atsižvelgti į Vasarius, kurie turi 28 dienas, nes 28%7 = 0.
        calcMonth++;
        whatDayOfWeek%=7;
    }
    whatDayOfWeek = (whatDayOfWeek + day - 1)%7;
    printf("%d-%d-%d yra %s\n",year,month,day,dayOfWeek[whatDayOfWeek]);
    return 0;
}
