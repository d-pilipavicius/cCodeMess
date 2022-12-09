#include <stdio.h>
#define sizeOfMenu 4
int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg);

int main()
{
    char* menuOpt[] = {};
    printf("%d",showMenu("",menuOpt,sizeOfMenu,""));
    return 0;
}

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg)
{
    int inputNumber;
    printf("%s\n",menuTitle);
    for(int i = 0; i<menuSize; ++i)
    {
        printf("%d:%s\n",i,menuOptions[i]);
    }
    printf("%s",inputMsg);
    if(scanf("%d",&inputNumber) == 1 && getchar() == '\n')
    {
        if(inputNumber<0 || inputNumber>=menuSize)
        {
            printf("Reiksme turi patekti i [0,%d] intervala.\n",menuSize-1);
            return showMenu(menuTitle,menuOptions,menuSize,inputMsg);
        }
        return inputNumber;
    }
    else
    {
        while(getchar()!='\n')
        {
            ;
        }
        printf("Klaidingai ivesta reiksme.\n");
        return showMenu(menuTitle,menuOptions,menuSize,inputMsg);
    }
}
