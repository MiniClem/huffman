#include "../include/encodage.h"

p_encodage create_encodage()
{
	p_encodage enc = (p_encodage)malloc(sizeof(p_encodage));
	enc->s_enc = (char *)malloc(sizeof(char));
	enc->s_enc[0] = '\0';
	return enc;
}

void destruct_encodage(p_encodage enc)
{
	if (enc && enc->s_enc)
	{
		free(enc->s_enc);
		enc->s_enc = NULL;
	}

	if (enc)
	{
		free(enc);
	}
}

char *s_encodage(p_encodage enc)
{
	return enc->s_enc;
}

int cursor(p_encodage enc)
{
	return strlen(s_encodage(enc));
}

char charAt_encodage(int i, p_encodage enc)
{
	const char c = s_encodage(enc)[i];
	return c;
}

void append_encodage(char *chaine, p_encodage enc)
{
	// Point d'amélioration, utiliser une allocation dynamique de mémoire et utiliser memcpy pour ajouter des éléments
	int length_enc = strlen(s_encodage(enc));
	int length = strlen(chaine) + 1;

	// Créer un nouvel espace mémoire qui peut contenir toutes les chaines
	char *s_new_encodage = (char *)malloc(length_enc + length);
	memcpy(s_new_encodage, s_encodage(enc), length_enc);
	memcpy(s_new_encodage + length_enc, chaine, length);

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

	printf("\n");
}

void create_code(Arbre a, int i, p_encodage enc)
{
	if (!est_feuille(a))
	{
		append_encodage("0", enc);
		create_code(fils_gauche(a), i + 1, enc);
		create_code(fils_droit(a), i + 1, enc);
	}
	else
	{
		append_encodage("1", enc);
		char c[ASCII_SIZE] = {0};
		code_ascii(racine(a), c);
		append_encodage(c, enc);
	}
}

void frequences(char *m, int tab_frequence[255])
{
	int length = strlen(m);
	for (int i = 0; i < length; i++)
	{
		tab_frequence[(unsigned int)m[i]]++;
	}
}

void binaire(int entier, char s[ASCII_SIZE])
{
	int pt = 0;
	int puissance;

	/*
	* On passe en revue chaque 2^i pour savoir si un le bit i
	* peut être égal à 0 ou 1. On commence par le bit de poid fort.
	*/
	for (int i = ASCII_SIZE - 1; i >= 0; i--)
	{
		puissance = pow(2, i);

		// Si le résultat de la puissance est >= 0 alors le bit correspondant est égal à 1
		// Car si la différence est positive ou nul alors le résultat de la puissance est comprise
		// dans le reste et donc le nombre à écrire est plus grand ou égal que celle-ci.
		if ((entier - puissance) >= 0)
		{
			s[pt++] = '1';
			entier -= puissance;
		}
		else
		{
			s[pt++] = '0';
		}
	}
}

void code_ascii(char c, char *c_tab)
{
	binaire((int)c, c_tab);
}

/*
// TESTS
int main()
{
	p_encodage p_enc = create_encodage();

	// Calculer la fréquence d'apparition des caractères d'un fichier :
	char *text = "void code_ascii(char c, char *c_tab){binaire((int)c, c_tab);}";
	int tab_frequence[255] = {0};
	frequences(text, tab_frequence);
	for (int i = 0; i < 255; i++)
	{
		if (tab_frequence[i] != 0)
		{
			printf("'%c' : %d\n", (char)i, tab_frequence[i]);
		}
	}

	// On imagine un début de suite telle que :
	append_encodage("00001", p_enc);

	// Le contenu dans encodage est le même :
	assert(strcmp(s_encodage(p_enc), "00001") == 0);

	// Le curseur est bien placé sur le '\0' :
	assert(cursor(p_enc) == 5);

	// On veut vérifier que l'on trouve bien le 1 à la position 4 :
	assert(charAt_encodage(4, p_enc));

	// On ajoute un A (01000001) dans le code, on veut vérifier l'ajout :
	char c[ASCII_SIZE + 1] = {0};
	c[ASCII_SIZE] = '\0';
	code_ascii('A', c);
	assert(strcmp(c, "01000001") == 0);
	append_encodage(c, p_enc);

	// On veut voir la chaine obtenue :
	print_encodage(p_enc);
	assert(strcmp(s_encodage(p_enc), "0000101000001") == 0);

	destruct_encodage(p_enc);

	return 0;
}
*/