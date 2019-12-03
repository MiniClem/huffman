#ifndef __LISTE_EXT_H_
#define __LISTE_EXT_H_
#include "liste.h"
// i
Liste rechercher_maillon(Liste l, Elt e);

// ii
Liste copie_liste(Liste l);
Liste inverse_liste(Liste l, Liste copie);
void copie_inverse_liste(Liste l);

// iii
Liste ajouter_fin(Liste l, Elt e);
void inserer(Liste l, Elt x, int i);
#endif