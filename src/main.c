#include <stdio.h>
#include <stdlib.h>
#include "../include/interface.h"
#include "../include/menu_action.h"

static char path[256];
static void menu()
{
	afficher_chaine("\n------------------Menu-----------------\n");
	printf(" 1 : Choisir un chemin ver le fichier à compresser/decompresser\n\tActuel : %s\n", path);
	afficher_chaine(" 2 : Compresser \n");
	afficher_chaine(" 3 : Decompresser \n");
	afficher_chaine(" 0 : Quitter \n");
	afficher_chaine("\n");
	afficher_chaine("choix : \n");
}

int main()
{
	int err = 0;
	int choix;

	menu();
	choix = lire_entier();
	while (choix != 0 && err == 0)
	{
		switch (choix)
		{
		case 1:
			err = choose_path(path);
			break;

		case 2:
			// compress(path);
			break;

		case 3:
			// uncompress(path);
			break;
		}
		menu();
		choix = lire_entier();
	}

	return 0;
}