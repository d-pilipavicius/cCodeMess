//Autorius: Domantas Pilipavičius, PS 4 grupė, 2 pogrupis.
//Ši užduotis nuskaito parametruose esančius failų pavadinimus, juos atidaro iš kurių pirmas yra skaitomasis, antras rašomasis.
//Pirmame faile visi buvę žodžiai apverčiami ir patalpinami arba į antrą failą, arba į ekraną, atitinkamai kaip vartotojas įvedė parametrus.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_FILE_NAME_SIZE 100
#define MAX_WORD_LENGHT 256

typedef struct Flags{
    char write; //Flag, skirtas patikrinti ar write failas įvardintas
    char read; //Flag, skirtas patikrinti ar read failas įvardintas
    char firstTimeRescan; //Flag, skirtas patikrinti, ar failo pavadiniminas pirmą kartą perskaitomas iš naujo

}Flags;

Flags flag; //Globalūs indikatoriai

void checkParameters(int argv){  //Atitinkamų indikatorių įjungimas
    switch(argv){
    default:
        flag.read = 1;
        flag.write = 1;
        break;
    case 1:
        flag.read = 0;
        flag.write = 0;
        break;
    case 2:
        flag.read = 1;
        flag.write = 0;
        break;
    }
    flag.firstTimeRescan = 1;
}

void initBuffer(char **buffer, int sizeOfBuffer){  //Kintamo dydžio bufferio inicializacija
    *buffer = (char*) malloc(sizeOfBuffer);

    for(int i = 0; i < sizeOfBuffer; ++i){
        (*buffer)[i] = 0;
    }
}

char *scanWithMessage(char *textMsg){  //Įvedimas iš ekrano į kintamąjį su žinute
    char *a;

    initBuffer(&a, MAX_FILE_NAME_SIZE);
    printf("%s", textMsg);
    scanf("%s", a);

    while(getchar() != '\n'){
        ;
    }

    return a;
}

void openReadFile(FILE **fr){  //Bandymas iš naujo atidaryti skaitymo failą, kuris klaidingai įvestas

    while(!*fr || flag.firstTimeRescan){
        flag.firstTimeRescan = 0;
        *fr = fopen(scanWithMessage("Nerastas skaitymo failas! Iveskite skaitymo failo pavadinima: "), "r");
    }

    flag.firstTimeRescan = 1;
}

void validateByFlags(FILE **fr, FILE **fw, char **argc){  //Funkcija, kuri pagal indikatorius vykdo skirtingus įvedimo/išvedimo būdus
    if(flag.write && flag.read){
        *fr = fopen(argc[1], "r");
        *fw = fopen(argc[2], "w");
    }
    else if(!flag.read){
        openReadFile(fr);
        *fw = NULL;
    }
    else if(!flag.write){
        *fr = fopen(argc[1], "r");
        *fw = NULL;
    }
}

void closeWriteFile(FILE *fr, FILE **fw){     //Rašymo uždarymo funkcija, jei skaitymo failas uždarytas
    if(!fr && *fw != NULL){
        fclose(*fw);
        *fw = NULL;
    }
}

int readFile(FILE **fr, char **readBuffer){  //Failo skaitymo funkcija
    int amountRead;

    amountRead = fread(*readBuffer, sizeof(char), BUFFER_SIZE-1, *fr);

    if(amountRead != BUFFER_SIZE-1){
        fclose(*fr);
        *fr = NULL;
    }
    return amountRead;
}

void writeFile(FILE **fw, char *writeBuffer, int amountWrite, FILE *fr){ //Failo rašymo funkcija
    fwrite(writeBuffer, sizeof(char), amountWrite, *fw);
    closeWriteFile(fr, fw);
}

int isThisaLetter(char let)
{
    if(let >= 'a' && let <= 'z' || let >= 'A' && let <= 'Z')
        return 1;
    return 0;
}

void checkSetBack(char *readBuffer, int *readSize, FILE **fr){   //Atitraukimo funkcija, jei nuskaityta dalis žodžio, kurio nebus įmanoma apversti
    if(*readSize == BUFFER_SIZE-1 && isThisaLetter(readBuffer[BUFFER_SIZE-1])){
        int setBack = 0;
        while(isThisaLetter(readBuffer[BUFFER_SIZE-1]) && *readSize-setBack-1 >= 0)
            ++setBack;

        if(*readSize-setBack-1 > 0){
            *readSize -= --setBack;
            fseek(*fr, SEEK_CUR, -setBack);
        }
    }
}

void printForLast(char **buffer, int amountRead){  //Išspausdinimo funkcija, kuri uždeda '\0' ant galo
    (*buffer)[amountRead] = '\0';
    printf("%s", *buffer);
}

void flipWords(char **buffer, int sizeOfBuffer){ //Žodžių eilutėje apsukimo funkcija
    int foundEndOfWord = 0;
    char *flipped;

    initBuffer(&flipped, MAX_WORD_LENGHT);
    for(int i = 0; i < sizeOfBuffer; ++i){

        if(!isThisaLetter((*buffer)[i]) && !isThisaLetter((*buffer)[i-1]) )
            foundEndOfWord++;
        else if(!isThisaLetter((*buffer)[i])){
            strncpy(flipped, *(buffer)+foundEndOfWord, i-foundEndOfWord);
            flipped[i-foundEndOfWord] = '\0';
            strrev(flipped);
            strncpy(*(buffer)+foundEndOfWord, flipped, i-foundEndOfWord);
            foundEndOfWord = i+1;
        }
        else if(sizeOfBuffer-1 == i){
            strncpy(flipped, *(buffer)+foundEndOfWord, i-foundEndOfWord+1);
            flipped[i-foundEndOfWord+1] = '\0';
            strrev(flipped);
            strncpy(*(buffer)+foundEndOfWord, flipped, i-foundEndOfWord+1);
        }
    }
}

int main(int argv, char **argc){
    char *readBuffer;
    FILE *fr, *fw;

    checkParameters(argv);
    validateByFlags(&fr, &fw, argc);
    closeWriteFile(fr, &fw);
    initBuffer(&readBuffer, BUFFER_SIZE);

    while(1){
        int amountRead;
        if(!fr && !fw)
            break;
        else if(flag.write){
            amountRead = readFile(&fr, &readBuffer);
            checkSetBack(readBuffer, &amountRead, &fr);
            flipWords(&readBuffer, amountRead);
            writeFile(&fw, readBuffer, amountRead, fr);
        }
        else if(!flag.write){
            amountRead = readFile(&fr, &readBuffer);
            checkSetBack(readBuffer, &amountRead, &fr);
            flipWords(&readBuffer, amountRead);
            printForLast(&readBuffer, amountRead);
        }
    }
    printf("\nPrograma darba baige.");
    return 0;
}
