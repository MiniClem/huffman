#include "../include/arbre.h"

Arbre creer_arbre(Elt x, Arbre fg, Arbre fd)
{
	Noeud *nouveau;

	nouveau = (Noeud *)malloc(sizeof(Noeud));
	nouveau->elt = x;
	nouveau->fils_gauche = fg;
	nouveau->fils_droit = fd;

	return nouveau;
}

Elt racine(Arbre a);
Arbre fils_gauche(Arbre a);
Arbre fils_droit(Arbre a);
int est_feuille(Arbre a);

int est_arbre_vide(Arbre a)
{
	return a == NULL ? 1 : 0;
}

Arbre detruire_arbre(Arbre a)
{
	if (!est_arbre_vide(a))
	{
		detruire_arbre(fils_gauche(a));
		detruire_arbre(fils_droit(a));
		free(a);
	}

	return NULL;
}

void print_racine(Arbre a)
{
	if (!est_arbre_vide(a))
	{
		printf("%d ", racine(a));
	}
}

void prof_prefixe(Arbre a, void action(Arbre))
{
	if (!est_arbre_vide(a))
	{
		action(a);
		prof_prefixe(fils_gauche(a), action);
		prof_prefixe(fils_droit(a), action);
	}
}

// void largeur(Arbre a, void action(Arbre))
// {
// 	Arbre aa;
// 	File f;
// 	assert(!est_arbre_vide(a));

// 	creer_file_vide(&f);
// 	enfiler(&f, a);
// 	while (!est_file_vide(f))
// 	{
// 		aa = defiler(&f);
// 		action(aa);
// 		if (aa->fils_gauche)
// 		{
// 			enfiler(&f, aa->fils_gauche);
// 		}
// 		if (aa->fils_droit)
// 		{
// 			enfiler(&f, aa->fils_droit);
// 		}
// 	}
// }

int hauteur(Arbre a)
{
	int hg, hd;
	if (est_arbre_vide(a))
	{
		return 0;
	}

	hg = hauteur(fils_gauche(a));
	hd = hauteur(fils_droit(a));

	return hg >= hd ? hg + 1 : hd + 1;
}

int nb_feuille(Arbre a)
{
	if (est_arbre_vide(a))
	{
		return 0;
	}

	if (est_feuille(a))
	{
		return 1;
	}

	return nb_feuille(fils_gauche(a)) + nb_feuille(fils_droit(a));
}

Noeud *rechercher(Arbre a, Elt e)
{
	Noeud *n;
	if (est_arbre_vide(a))
		return NULL;
	if (racine(a) == e)
		return a;

	n = rechercher(fils_gauche(a), e);
	if (!n)
	{
		n = rechercher(fils_droit(a), e);
	}

	return n;
}