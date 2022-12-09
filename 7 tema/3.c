#include <stdio.h>
int getPositiveNumber(char *msg);

int main()
{
    printf("%d",getPositiveNumber(""));
    return 0;
}

int getPositiveNumber(char *msg)
{
    int notScanned = 1;
    int number;
    while(notScanned)
    {
        printf("%s",msg);
        if(scanf("%ds",&number)== 1 && getchar() == '\n')
        {
            return number;
        }
        else
        {
            while(getchar()!='\n')
            {
                ;
            }
            printf("Ivesta klaidinga reiksme.\n");
        }
    }
}
