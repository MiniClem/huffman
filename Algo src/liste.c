#include "liste.h"

Liste cree_liste_vide()
{
	return NULL;
}

int est_liste_vide(Liste l)
{
	return (l == cree_liste_vide());
}

Liste ajout_liste(Liste l, Elt e)
{
	Maillon *nouveau;
	nouveau = (Maillon *)malloc(sizeof(Maillon));
	nouveau->elt = e;
	nouveau->suiv = l;
	return nouveau;
}

Elt tete_liste(Liste l)
{
	assert(!est_liste_vide(l));
	return l->elt;
}

Liste queue_liste(Liste l)
{
	assert(!est_liste_vide(l));
	return l->suiv;
}

Liste liberer_liste(Liste l)
{
	if (!est_liste_vide(l))
	{
		liberer_liste(queue_liste(l));
		free(l);
	}

	return NULL;
}

Liste liberer_maillon(Maillon *m)
{
	Liste l;
	l = queue_liste(m);
	free(m);
	return l;
}