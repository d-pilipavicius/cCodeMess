#include <stdio.h>
long getFileSize(FILE *fr, int index);
int getValue(FILE *fr, int index);
int setValue(FILE *fa, int index, char* value);
int addValue(FILE *fa, int index, char* value);

int main()
{
    FILE *fr;
    fr = fopen("txt.txt","r");
    printf("%d",getValue(fr,1));
    fclose(fr);
    return 0;
}

int getValue(FILE *fr, int index)
{
    int inRange;
    if(index>=0)
    {
        inRange = getFileSize(fr,index);
    }
    else
    {
        printf("Indeksas negali buti neigiamas.\n");
        return -1;
    }
    if(inRange == 0)
    {
        int readVal;
        fseek(fr,index,SEEK_SET);
        if(fscanf(fr,"%d",&readVal) == 1)
        {
            return readVal;
        }
        else
        {
            printf("Toje pozicijoje nera sveiko skaiciaus.\n");
            return -1;
        }
    }
    else
    {
        printf("Indeksas virsija programos rezius!\n");
        return -1;
    }
}

int setValue(FILE *fa, int index, char* value)
{
    int inRange;
    if(index>=0)
    {
        inRange = getFileSize(fa,index);
    }
    else
    {
        printf("Indeksas negali buti neigiamas.\n");
        return -1;
    }
    if(inRange == 0)
    {
        fseek(fa,index,SEEK_SET);
        fprintf(fa,value);
        return 0;
    }
    else
    {
        printf("Indeksas virsija programos rezius!\n");
        return -1;
    }
}

int addValue(FILE *fa, int index, char* value)
{
    int inRange;
    if(index>=0)
    {
        inRange = getFileSize(fa,index);
    }
    else
    {
        printf("Indeksas negali buti neigiamas.\n");
        return -1;
    }
    if(inRange == 0)
    {
        char* readInfo;
        fseek(fa,index,SEEK_SET);
        fscanf(fa,"%s",readInfo);
        fseek(fa,index,SEEK_SET);
        fprintf(fa,"%s%s",value,readInfo);
        return 0;
    }
    else
    {
        printf("Indeksas virsija programos rezius!\n");
        return -1;
    }
}

int remValue(FILE *fa, int index)
{
    int inRange;
    if(index>=0)
    {
        inRange = getFileSize(fr,index);
    }
    else
    {
        printf("Indeksas negali buti neigiamas.\n");
        return -1;
    }
    if(inRange == 0)
    {
        char* readInfo;
        fseek(fa,0,SEEK_SET);
        fscanf(fa,"%s",readInfo);

        fseek(fa,index,SEEK_SET);
        fprintf(fa,"%s",readInfo);
        return 0;
    }
    else
    {
        printf("Indeksas virsija programos rezius!\n");
        return -1;
    }
}

long getFileSize(FILE *f, int index)
{
    long byteVal;
    if(f)
    {
        fseek(f,0,SEEK_END);
        byteVal = ftell(f);
        if(index>=byteVal)
        {
            return -1;
        }
        return 0;
    }
    else
    {
        return -1;
    }
}
