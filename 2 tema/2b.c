#include <stdio.h>
main()
{
    char whatSys = ' ';
    int scanned;
	while(whatSys != 'd' && whatSys != 'h')
	{
		printf("Is kokios sistemos versti (h - hex, kuri bus verciama i dec, d - dec,kuri bus verciama i hex): ");
		scanf("%c", &whatSys);
		if(whatSys == 'd' || whatSys == 'h')
		{
			;
		}
		else
		{
			printf("Netinkama reiksme!\n");
			while(getchar() != '\n')
			{
				;
			}
		}
    }
	while(getchar() != '\n')
	{
		;
	}
	printf("Iveskite skaitine reiksme: ");
	(whatSys == 'd') ? scanf("%d",&scanned) : scanf("%x",&scanned);
	(whatSys == 'd') ? printf("Reiksme hex sistemoje: %x",scanned) : printf("Reiksme dec sistemoje: %d",scanned);
}
