#include <stdio.h>
#include <stdlib.h>
char *largFile(int argc, char**argv);

int main(int argc, char **argv)
{
    return 0;
}

char *largFile(int argc, char**argv)
{
    long maxFileSize = -1;
    int maxFileIndex = -1;
    long fileSize;
    for(int i = 1; i<argc; ++i)
    {
        FILE *fr;
        fr = fopen(*(argv+i),"r");
        fseek(fr,0,SEEK_END);
        fileSize = ftell(fr);
        if(fileSize>maxFileSize)
        {
            maxFileIndex = i;
            maxFileSize = fileSize;
        }
        fclose(fr);
    }
    if(maxFileIndex==-1) return NULL;
    return *(argv+maxFileIndex);
}
