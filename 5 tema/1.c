#include <stdio.h>
int main()
{
    int checkForOutOfBounds = 1;
    int x, y;
    int arr[] = {0,0,0,0,0,0,0,0,0,0};
    for(int i = 0; i<10; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    arr[0] = 1;
    arr[3] = 2;
    arr[9] = 3;
    for(int i = 2; i<9; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[9] = 0;
    for(int i = 8; i>5; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[6] = 4;
    for(int i = 0; i<10; i++)
    {
        printf("%d ",arr[i]);
    }
    while(checkForOutOfBounds)
    {
        printf("\nIveskite du skaicius: ");
        scanf("%d %d",&x,&y);
        (x>10 || x<1) ? printf("Skaicius x turi priklausyti intervalui [1,10]!") : (checkForOutOfBounds=0);
    }
    arr[x-1] = y;
    checkForOutOfBounds = 1;
    while(checkForOutOfBounds)
    {
        printf("Iveskite skaiciu: ");
        scanf("%d",&x);
        (x>10||x<1) ? printf("Skaicius x turi priklausyti intervalui [1,10]!") : (checkForOutOfBounds=0);
    }
    for(int i = x-1; i<9; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[9] = 0;
    checkForOutOfBounds = 1;
    while(checkForOutOfBounds)
    {
        printf("\nIveskite du skaicius: ");
        scanf("%d %d",&x,&y);
        (x>10||x<1) ? printf("Skaicius x turi priklausyti intervalui [1,10]!") : (checkForOutOfBounds=0);
    }
    for(int i = 8; i>x-2; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[x-1] = y;
    for(int i = 0; i<10; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
