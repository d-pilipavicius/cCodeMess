#include <stdio.h>
long getFileSize(char *fileName);

int main()
{
    printf("%d",getFileSize("txt.txt"));
    return 0;
}

long getFileSize(char *fileName)
{
    long byteVal;
    FILE *fr;
    fr = fopen(fileName,"rb");
    if(fr)
    {
        fseek(fr,0,SEEK_END);
        byteVal = ftell(fr);
        fclose(fr);
        return byteVal;
    }
    else
    {
        return -1;
    }
}
