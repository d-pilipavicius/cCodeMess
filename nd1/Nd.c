//Autorius: Domantas Pilipavičius, PS 4 grupė, 2 pogrupis.
//Programos paskirtis: vartotojo įvestuose duomenyse, kurie sveikųjų skaičių intervale [-1000,1000], ieškoti trijų iš eilės išrikiuotų nulinių reikšmių.
//Jei nieko nerandama, išvedama, kad nieko nerandama.
//Jei randamas atitikmuo - parašoma kiek tokių atitikmenų rasta ir įvardijamos jų įrašytos pozicijos.
//Seka prasideda nuo reikšmės 1 kaip skaičiuojant objektus realybėje, ne nuo 0 kaip masyve.

#include <stdio.h>

int main(){
    double scanEnteredText;
    int elements=0, threeZeroValues = 0;
    int arrayOfEnteredValues[1000]={0},zeroValues[998];

    printf("Sioje programoje reikes ivesti sveiku skaiciu eilute, taciau kiekviena reiksme vedama individualiai.\n"
           "Programa priima tik sveikus skaicius intervale [-1000,1000] ir nustoja rinkti skaicius, jei paskutine ivesta sveika reiksme nepriklauso siam intervalui.\n"
           "Kai bus ivesta reiksme, nepriklausanti intervalui [-1000,1000], programa isves kiek rado triju is eiles isrikiuotu nuliniu reiksmiu eiluteje.\n"
           "Taip pat, programa isves kuriose pozicijose, intervale [1,1000], nulines reiksmes stovejo.\n\n");

    while(elements==0 || arrayOfEnteredValues[elements-1]>=-1000 && arrayOfEnteredValues[elements-1]<=1000)
    {
        printf("Iveskite %d potencialia reiksme: ",elements+1);

        if((scanf("%lf",&scanEnteredText) == 1) && getchar()=='\n'){ //Korektiška įvestis
            if(scanEnteredText!=(int)scanEnteredText){ //Nekorektiška įvestis
                printf("Netinkama reiksme, skaiciu su reiksmemis po kableliu vesti negalima! Veskite sveika skaiciu intervale [-1000,1000].\n");
            }

            else{
                arrayOfEnteredValues[elements++]=scanEnteredText;
            }

        }

        else{
            while(getchar()!='\n'){ //Nekorektiška įvestis
                ;
            }
            printf("Netinkama reiksme, simboliu vesti negalima! Veskite sveika skaiciu intervale [-1000,1000].\n");

        }

    }

    for(int i = 2; i<elements; i++){ //Ieškojimas trijų nulinių reikšmių iš eilės
        if(arrayOfEnteredValues[i]==0 && arrayOfEnteredValues[i-1]==0 && arrayOfEnteredValues[i-2]==0){
            zeroValues[threeZeroValues++]=i+1;
        }

    }

    if(threeZeroValues != 0){
        printf("Eileje buvo %d seka/os/u, turejusios tris is eiles einancias nulines reiksmes.\n\nPozicijos, kuriose buvo tokios sekos:",threeZeroValues);
        for(int i = 0; i<threeZeroValues; i++){
            printf("\n%d %d %d",zeroValues[i]-2,zeroValues[i]-1,zeroValues[i]);
        }

    }

    else
        printf("Sekoje nebuvo triju is eiles einanciu nuliniu reiksmiu.");

    return 0;
}
