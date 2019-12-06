#ifndef __LISTE_H_
#define __LISTE_H_
#include <stdlib.h>
#include <assert.h>

// Poiteur sur quelque chose
typedef char Elt;

struct Maillon
{
    Elt elt;
    struct Maillon *suiv;
};

typedef struct Maillon Maillon;
typedef Maillon *Liste;

// Création
Liste cree_liste_vide();

// Observateur
int est_liste_vide(Liste l);

// Opération
Liste ajout_liste(Liste l, Elt e);

Elt tete_liste(Liste l);

Liste queue_liste(Liste l);

Liste liberer_liste(Liste l);

Liste liberer_maillon(Maillon *m);
#endif