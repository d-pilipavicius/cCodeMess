#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define sizeOfArray //PAPILDYTI IR NURODYTI KOKIO DYDZIO MASYVAS
void generateArray(int data[], int size, int low, int high);

int main()
{
    int arr[sizeOfArray];
    generateArray(arr,sizeOfArray,,);
    for(int i = 0; i<sizeOfArray; ++i) //Kiekvieno elemento patikrinimui
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}

void generateArray(int data[], int size, int low, int high)
{
    if(low<=high)
    {
        srand(time(NULL));
        for(int i = 0; i<size; ++i)
        {
            data[i] = rand()%(high-low+1)+low;
        }
    }
    else
    {
        printf("Klaidingai ivesti parametrai, maziausia reiksme negali virsyti didziausios.\n");
    }
}
