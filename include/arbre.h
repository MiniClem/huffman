#ifndef __FILE_H_
#define __FILE_H_
#include <stdio.h>
#include "liste_ext.h"

typedef struct noeud
{
	Elt elt;
	int poid;
	struct noeud *fils_gauche;
	struct noeud *fils_droit;
} Noeud;

typedef struct noeud *Arbre;

Arbre creer_arbre_vide (void) ;
Arbre creer_arbre(Elt x, int poid, Arbre fg, Arbre fd);
Arbre detruire_arbre(Arbre a);

int est_arbre_vide(Arbre a);
int est_feuille(Arbre a);

Elt racine(Arbre a);
int poid(Arbre a);
Arbre fils_gauche(Arbre a);
Arbre fils_droit(Arbre a);

void print_racine(Arbre a);
void prof_prefixe(Arbre a);

// void largeur(Arbre a, void action(Arbre));
int hauteur(Arbre a);

int nb_feuille(Arbre a);
Noeud *rechercher(Arbre a, Elt e);
#endif