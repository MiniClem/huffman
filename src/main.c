#include <stdio.h>
#include "../include/interface.h"

static void menu(void)
{
	afficher_chaine("\n------------------Menu-----------------\n");
	afficher_chaine(" 1 : Compresser \n");
	afficher_chaine(" 2 : Decompresser \n");
	afficher_chaine(" 0 : Quitter \n");
	afficher_chaine("\n");
	afficher_chaine("choix : \n");
}

int main()
{
	int choix;

	menu();
	choix = lire_entier();
	while (choix != 0)
	{
		switch (choix)
		{
		case 1:
			break;
		case 2:
			break;
		}
		menu();
		choix = lire_entier();
	}

	return 0;
}