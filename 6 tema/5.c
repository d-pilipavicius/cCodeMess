#include <stdio.h>

int main()
{
    FILE *fa;
    int atSymbolLocation = -1, dotLocation = -1;
    char email[200] = {NULL}, emailDomain[200]={NULL};
    printf("Sioje programoje reikia ivesti el pasto adresa, kuris turi tik viena '@' simboli ir po jo einanti bent viena '.' simboli.\n"
           "Teisingai irasytas el. pasto adresas issaugojamas \"emails.txt\" dokumente.\n\n");
    printf("Iveskite el. pasto adresa: ");
    scanf("%s",email);
    for(int i = 0; email[i]!='\0'; i++)
    {
        if(email[i] == '@')
        {
            if(atSymbolLocation == -1)
                atSymbolLocation = i;
            else
            {
                printf("El. pastas netinkamas.");
                return 0;
            }
        }
        else if(email[i] == '.' && atSymbolLocation != -1)
            dotLocation = i;
    }
    if(atSymbolLocation==dotLocation+1 || atSymbolLocation == 0 || email[dotLocation+1]=='\0' || atSymbolLocation == -1 || dotLocation == -1)
        printf("El. pastas netinkamas.");
    else
    {
        printf("El. pastas tinkamas.\n");
        for(int i = 0; email[i+atSymbolLocation+1]!='\0'; i++)
        {
            emailDomain[i]=email[i+atSymbolLocation+1];
        }
        fa = fopen("emails.txt","a");
        fprintf(fa,"%s\n",emailDomain);
        printf("El. pasto domenas irasytas i \"emails.txt\".");
    }
    return 0;
}
