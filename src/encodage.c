#include "../include/encodage.h"

p_encodage create_encodage()
{
	p_encodage enc = (p_encodage)malloc(sizeof(p_encodage));
	enc->s_enc = (char *)malloc(sizeof(char));
	enc->s_enc[0] = '\0';
	return enc;
}

char *s_encodage(p_encodage enc)
{
	return enc->s_enc;
}

int cursor(p_encodage enc)
{
	return sizeof s_encodage(enc);
}

char charAt_encodage(int i, p_encodage enc)
{
	const char c = s_encodage(enc)[i];
	return c;
}

void append_encodage(char *chaine, p_encodage enc)
{
	// Point d'amélioration, utiliser une allocation dynamique de mémoire et utiliser memcpy pour ajouter des éléments
	int length_enc = strlen(s_encodage(enc) - 1);
	int length = strlen(chaine);

	// Créer un nouvel espace mémoire qui peut contenir toutes les chaines
	char *s_new_encodage = (char *)malloc(length_enc + length);
	memcpy(s_new_encodage, s_encodage(enc), length_enc);
	memcpy(s_new_encodage, chaine, length);

	free(enc->s_enc);
	enc->s_enc = s_new_encodage;
}

void print_encodage(p_encodage enc)
{
	int length = strlen(enc->s_enc);

	for (int i = 0; i < length; i++)
	{
		printf("%c", charAt_encodage(i, enc));
	}
}

// void create_code(Arbre a, int i, p_encodage enc)
// {
// 	if (!est_feuille(a))
// 	{
// 		enc->s_enc[i] = 0;
// 		create_code(fils_gauche(a), i + 1, enc);
// 		enc->s_enc[i] = 1;
// 		create_code(fils_droit(a), i + 1, enc);
// 	}
// 	else
// 	{
// 		append_encodage(code_ascii(racine(a)), enc);
// 	}
// }

void binaire(int entier, char s[9])
{
	int pt = 8;
	int puissance;

	/*
	* On passe en revue chaque 2^i pour savoir si un le bit i
	* peut être égal à 0 ou 1. On commence par le bit de poid fort.
	*/
	for (int i = 9 - 1; i >= 0; i--)
	{
		puissance = pow(2, i);

		// Si le résultat de la puissance est >= 0 alors le bit correspondant est égal à 1
		// Car si la différence est positive ou nul alors le résultat de la puissance est comprise
		// dans le reste et donc le nombre à écrire est plus grand ou égal que celle-ci.
		if ((entier - puissance) >= 0)
		{
			s[pt--] = '1';
			entier -= puissance;
		}
		else
		{
			s[pt--] = '0';
		}
	}
}
// char code_ascii(char c)
// {
// 	return ((int)c)
// }

int main()
{
	char c[9];

	binaire(5, c);

	for (int i = 0; i < 9; i++)
	{
		printf("%c", c[i]);
	}

	return 0;
}