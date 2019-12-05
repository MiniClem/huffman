#include "../include/encodage.h"

Arbre *creer_liste_arbre(p_encodage enc, int *size)
{
	Arbre *t_noeud;
	Arbre n;
	int *tab_frequence = enc->tab_frequences;
	int j = 0;

	// On calcule le nombre de valeurs non nulle
	for (int i = 0; i < 255; i++)
	{
		if (tab_frequence[i] != 0)
		{
			*size += 1;
		}
	}

	// Allocation de la mémoire pour le tableau de noeud
	t_noeud = (Arbre *)calloc(*size, sizeof(Arbre));

	// On place les variables de fréquence dans un noeud
	for (int i = 0; i < 255; i++)
	{
		// On passe si la valeur est nulle
		if (tab_frequence[i] != 0)
		{
			n = creer_arbre((char)i, tab_frequence[i], NULL, NULL);
			t_noeud[j++] = n;
		}
	}

	return t_noeud;
}

int trouver_combiner(Arbre *l, int size)
{
	int pos_a = 0, pos_b = 0;
	Arbre a = NULL;
	Arbre b = NULL;

	// trouver minimum
	for (int i = 0; i < size; i++)
	{
		if (l[i] != NULL)
		{
			if (a == NULL || (b != NULL && l[i]->poid < (a)->poid))
			{
				if (b != NULL && (a)->poid < (b)->poid)
				{
					b = a;
					pos_b = pos_a;
				}

				a = l[i];
				pos_a = i;

				assert(a != b);
			}
			else if (b == NULL || l[i]->poid < (b)->poid)
			{
				b = l[i];
				pos_b = i;
			}
		}
	}

	if (a == NULL || b == NULL)
	{
		// Indique la fin du traitement de la liste
		return 0;
	}

	// Combiner les 2 arbres
	Arbre new_a = creer_arbre(a->elt, a->poid, a->fils_gauche, a->fils_droit);
	a->elt = '\0';
	a->fils_gauche = new_a;
	a->fils_droit = b;
	a->poid = a->poid + b->poid;
	// La liste exclue le deuxième élément, on réduit la liste
	l[pos_b] = NULL;

	return 1;
}

void huffman(p_encodage enc)
{
	int size = 0;
	Arbre *t_arbre = creer_liste_arbre(enc, &size);
	enc->dico = huffman_merge(t_arbre, size);
}

Arbre huffman_merge(Arbre *l, int size)
{
	int is_working = 1;

	do
	{
		is_working = trouver_combiner(l, size);
	} while (is_working);

	for (int i = 0; i < size; i++)
	{
		if (l[i] != NULL)
		{
			return l[i];
		}
	}

	return NULL;
}

p_encodage create_encodage()
{
	p_encodage enc = (p_encodage)malloc(sizeof(encodage));
	enc->s_enc = malloc(sizeof(char));
	enc->s_enc[0] = '\0';
	enc->dico = NULL;
	enc->tab_frequences = calloc(255, sizeof(int));
	return enc;
}

void destruct_encodage(p_encodage enc)
{
	if (enc && enc->s_enc)
	{
		free(enc->s_enc);
		enc->s_enc = NULL;
	}

	if (enc && enc->dico)
	{
		detruire_arbre(enc->dico);
		enc->dico = NULL;
	}

	if (enc && enc->tab_frequences)
	{
		free(enc->tab_frequences);
		enc->tab_frequences = NULL;
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

int *t_frequences(p_encodage enc)
{
	return enc->tab_frequences;
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
	int length = strlen(chaine);

	// Créer un nouvel espace mémoire qui peut contenir toutes les chaines
	char *s_new_encodage = (char *)calloc(length_enc + length + 2, sizeof(char));

	// Copie les contenus
	strcpy(s_new_encodage, s_encodage(enc));
	strcpy(s_new_encodage + length_enc, chaine);

	// Désalloue l'ancien pointeur
	free(s_encodage(enc));
	enc->s_enc = s_new_encodage;
}

void print_encodage(p_encodage enc)
{
	int length = strlen(enc->s_enc);
	printf("Taille de l'encodage : %d\n", length);

	for (int i = 0; i < length; i++)
	{
		printf("%c", charAt_encodage(i, enc));
	}

	printf("\n");
}

void create_code_arbre(Arbre a, p_encodage enc)
{
	if (!est_feuille(a))
	{
		append_encodage("0", enc);
		create_code_arbre(fils_gauche(a), enc);
		create_code_arbre(fils_droit(a), enc);
	}
	else
	{
		append_encodage("1", enc);
		char c[ASCII_SIZE] = {'0'};
		code_ascii(racine(a), c);
		append_encodage(c, enc);
	}
}

void create_code_texte(p_encodage enc, char *m)
{
	Arbre dico = enc->dico;
	int length = strlen(m);
	char code[32] = {0};

	for (int i = 0; i < length; i++)
	{
		rechercher_encodage(dico, m[i], code, 0);
		append_encodage(code, enc);
	}
}

void frequences(char *m, p_encodage enc)
{
	int *tab_freq = t_frequences(enc);
	int length = strlen(m);
	for (int i = 0; i < length; i++)
	{
		tab_freq[(unsigned int)m[i]]++;
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
	for (int i = ASCII_SIZE - 2; i >= 0; i--)
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
	s[pt] = '\0';
}

void code_ascii(char c, char *c_tab)
{
	binaire((int)c, c_tab);
}

// TESTS
int main()
{
	// Test réel
	char *c = "aaaabbbccdaaaadddd";

	p_encodage p_enc = create_encodage();
	frequences(c, p_enc);

	huffman(p_enc);

	// Encodage dico
	create_code_arbre(p_enc->dico, p_enc);
	print_encodage(p_enc); // Affichage test

	// Encodage message
	create_code_texte(p_enc, c);
	print_encodage(p_enc); // Affichage test

	// Libération mémoire
	destruct_encodage(p_enc);
	// Test réel

	// p_encodage p_enc = create_encodage();

	// // Calculer la fréquence d'apparition des caractères d'un fichier :
	// char *text = "cagataagagaa";
	// int *p_frequence = t_frequences(p_enc); // Récupère l'adresse
	// frequences(text, p_frequence);
	// for (int i = 0; i < 255; i++)
	// {
	// 	if (p_frequence[i] != 0)
	// 	{
	// 		printf("'%c' : %d\n", (char)i, p_frequence[i]);
	// 	}
	// }

	// // On crée une liste de noeud qui plus tard sera un arbre
	// int size = 0;
	// Arbre *t_noeuds = creer_liste_arbre(p_enc, &size);
	// printf("Arbres : \n");
	// for (int i = 0; i < size; i++)
	// {
	// 	printf("'%c' : %d\n", t_noeuds[i]->elt, t_noeuds[i]->poid);
	// }

	// // On cherche les candidats pour le minimum et on réalise Huffman
	// Arbre final = huffman_merge(t_noeuds, size);
	// char code_c[56] = {0};
	// assert(final->poid == 10);
	// assert(final->fils_droit->poid == 6);
	// assert(final->fils_gauche->poid == 4);
	// // printf("valeur de 11 %c", final->fils_droit->fils_droit->elt);

	// Arbre a = creer_arbre('a', 1, NULL, NULL);
	// Arbre b01 = creer_arbre('b', 1, NULL, NULL);
	// Arbre b02 = creer_arbre('c', 1, NULL, NULL);
	// Arbre b = creer_arbre('\0', 1, b01, b02);
	// Arbre o = creer_arbre('\0', 2, a, b);
	// rechercher_encodage(o, 'b', code_c, 0);
	// printf("code pour 'b' : %s\n", code_c);

	// // On désalloue l'arbre, pas besoin de lui pour le moment
	// detruire_liste_arbre(t_noeuds, size);

	// // On imagine un début de suite telle que :
	// append_encodage("00001", p_enc);

	// // Le contenu dans encodage est le même :
	// assert(strcmp(s_encodage(p_enc), "00001") == 0);

	// // On veut vérifier que l'on trouve bien le 1 à la position 4 :
	// assert(charAt_encodage(4, p_enc));

	// // On ajoute un A (01000001) dans le code, on veut vérifier l'ajout :
	// char c[ASCII_SIZE + 1] = {0};
	// c[ASCII_SIZE] = '\0';
	// code_ascii('A', c);
	// assert(strcmp(c, "01000001") == 0);
	// append_encodage(c, p_enc);

	// // On veut voir la chaine obtenue :
	// print_encodage(p_enc);
	// assert(strcmp(s_encodage(p_enc), "0000101000001") == 0);

	// destruct_encodage(p_enc);

	return 0;
}
