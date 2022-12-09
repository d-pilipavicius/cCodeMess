#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ***create2DArray(int row, int col); //a užd
void writeToArray(char ****arr, int i, int j, char *insText); //b užd
char *arrValue(char ***arr, int i, int j); //c užd
void freeMemory(char ****arr); //d užd

int main()
{
    return 0;
}

char ***create2DArray(int row, int col)
{
    char ***arr;
    arr = (char***) calloc(row,sizeof(char**));
    for(int i = 0; i<row; ++i)
    {
        *(arr+i) = (char**) calloc(col,sizeof(char*));
        for(int j = 0; j<col; ++j)
        {
            *(*(arr+i)+j) = 0;
        }
    }
    return arr;
}

void writeToArray(char ****arr, int i, int j, char *insText)
{
    int lengthOfChar = 0;
    while(1)
    {
        if(*(insText+lengthOfChar)=='\0')
            break;
        ++lengthOfChar;
    }
    *(*(*arr+i)+j) = (char*) calloc(lengthOfChar+1,sizeof(char));
    strcpy(*(*(*arr+i)+j),insText);
}

char *arrValue(char ***arr, int i, int j)
{
    return *(*(arr+i)+j);
}

void freeMemory(char ****arr)
{
    free(arr);
}

