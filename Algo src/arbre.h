#include "file.h"

typedef struct noeud
{
	Elt elt;
	struct noeud *fils_gauche;
	struct noeud *fils_droit;
} Noeud;

typedef struct noeud *Arbre;

Arbre creer_arbre(Elt x, Arbre fg, Arbre fd);
Arbre detruire_arbre(Arbre a);

void print_racine(Arbre a);
void prof_prefixe(Arbre a, void action(Arbre));

void largeur(Arbre a, void action(Arbre));
int hauteur(Arbre a);

int nb_feuille(Arbre a);
Noeud *rechercher(Arbre a, Elt e);