//Autorius: Domantas Pilipavičius, PS 4 grupė, 2 pogrupis.
//Ši programa sukuria vartotojo pasirinkto dydžio kvadratinę matricą, kurią vartotojas ir užpildo.
//Užpildytą matricą programa išanalizuoja ir pateikia jos balno taškus. (2 užd)
#include <stdio.h>
#define ARR_SIZE 100
int validationAndRead(char *txtMsg, int valNr, int minSize, int maxSize);

int main()
{
    short N;
    int nrOfSaddles = 0;
    short matrix[ARR_SIZE][ARR_SIZE];
    short
        maxRowMatrixSaddle[ARR_SIZE],
        minRowMatrixSaddle[ARR_SIZE],
        maxColumnMatrixSaddle[ARR_SIZE],
        minColumnMatrixSaddle[ARR_SIZE];
    //Kintamieji, skirti įvardinti, ar kažkurioje matricos eilutėje kartojasi reikšmės
    char rowHigh[ARR_SIZE]={0}, rowLow[ARR_SIZE]={0}, columnHigh[ARR_SIZE]={0}, columnLow[ARR_SIZE]={0};
    printf(
        "Si programa praso ivesti kvadratines matricos dydi (sveika teigiama skaiciu), kuria sukuria.\n"
        "Tada, programa praso uzpildyti matrica sveiku skaiciu reiksmemis, kurios naudojamos matricos balnu taskams apskaiciuoti.\n\n"
    );
    N = validationAndRead("Iveskite matricos dydi: ",1,1,ARR_SIZE);
    for(short i = 0; i<N; ++i){
        for(short j = 0; j<N; ++j){
            char textMsg[1000];
            sprintf(textMsg,"Iveskite (%d,%d) matricos reiksme: ",i+1,j+1);
            matrix[i][j] = validationAndRead(textMsg,0,-32768,32767);
        }
    }
    for(short i = 0; i<N; ++i){
        for(short j = 0; j<N; ++j){
            if(j == 0){ //Nustatomos pradinės reikšmės, su kuriomis bus lyginama
                maxRowMatrixSaddle[i] = matrix[i][j];
                minRowMatrixSaddle[i] = matrix[i][j];
            }
            if(i == 0){ //Nustatomos pradinės reikšmės, su kuriomis bus lyginama
                maxColumnMatrixSaddle[j] = matrix[i][j];
                minColumnMatrixSaddle[j] = matrix[i][j];
            }
            if(maxRowMatrixSaddle[i]<matrix[i][j]){
                maxRowMatrixSaddle[i] = matrix[i][j];
                rowHigh[i] = 0;
            }
            else if(maxRowMatrixSaddle[i] == matrix[i][j] && j != 0){
                rowHigh[i] = 1;
            }
            if(maxColumnMatrixSaddle[j]<matrix[i][j]){
                maxColumnMatrixSaddle[j] = matrix[i][j];
                columnHigh[j] = 0;
            }
            else if(maxColumnMatrixSaddle[j] == matrix[i][j] && i != 0){
                columnHigh[j] = 1;
            }
            if(minRowMatrixSaddle[i]>matrix[i][j]){
                minRowMatrixSaddle[i] = matrix[i][j];
                rowLow[i] = 0;
            }
            else if(minRowMatrixSaddle[i] == matrix[i][j] && j != 0){
                rowLow[i] = 1;
            }
            if(minColumnMatrixSaddle[j]>matrix[i][j]){
                minColumnMatrixSaddle[j] = matrix[i][j];
                columnLow[j] = 0;
            }
            else if(minColumnMatrixSaddle[j] == matrix[i][j] && i != 0){
                columnLow[j] = 1;
            }
        }
    }
    for(short i = 0; i<N; ++i){
        for(short j = 0; j<N; ++j){
            if((maxRowMatrixSaddle[i] == minColumnMatrixSaddle[j] && rowHigh[i] == 0 && columnLow[j] == 0 || minRowMatrixSaddle[i] == maxColumnMatrixSaddle[j] && rowLow[i] == 0 && columnHigh[j] == 0) && N!=1){
                printf("(%d,%d) yra matricos balno taskas.\n",i+1,j+1);
                ++nrOfSaddles;
            }
        }
    }
    if(nrOfSaddles==0){
        printf("Sioje matricoje nera balno tasku.\n");
    }
    return 0;
}

int validationAndRead(char *txtMsg, int valNr, int minSize, int maxSize) //Funkcija skirta validacijai ivedinejant
{
    double read;
    while(1){
        printf("%s",txtMsg);
        if(scanf("%lf",&read)==1 && getchar() == '\n'){
            int goodToGo = 1;
            if(read!=(int)read){
                printf("Negalima vesti skaiciu su reiksmemis po kablelio. Galima vesti tik sveikus skaicius.\n");
                goodToGo = 0;
            }
            if(read<1 && valNr){
                printf("Negalima vesti neteigiamus skaicius. Galima vesti tik teigiamus skaicius.\n");
                goodToGo = 0;
            }
            if(minSize>read || maxSize<read)
            {
                printf("Elementas nepateko i ivedimo intervala. Prasome vesti skaiciu intervale [%d,%d].\n",minSize,maxSize);
                goodToGo = 0;
            }
            if(goodToGo){
                printf("Priimtas skaicius.\n");
                return (int)read;
            }
        }
        else{
            while(getchar()!='\n'){
                ;
            }
            printf("Negalima vesti simboliu. Galima vesti tik sveikus, teigiamus skaicius.\n");
        }
    }
}

