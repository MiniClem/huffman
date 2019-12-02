#include "liste_ext.h"

Liste rechercher_maillon(Liste l, Elt e)
{
    if (est_liste_vide(l))
        return NULL;

    if (tete_liste(l) == e)
        return l;

    return rechercher_maillon(queue_liste(l), e);
}

Liste copie_liste(Liste l)
{
    Liste copie;

    if (est_liste_vide(l))
        return cree_liste_vide();

    copie = copie_liste(queue_liste(l));

    return ajout_liste(copie, tete_liste(l));
}

Liste inverse_liste(Liste l, Liste copie)
{
    if (est_liste_vide(l))
        return copie;

    copie = ajout_liste(copie, tete_liste(l));
    return copie;
}

void copie_inverse_liste(Liste l)
{
    inverse_liste(l, cree_liste_vide());
}

Liste ajouter_fin(Liste fin, Elt x)
{
    // fin->suiv = ajout_liste(cree_liste_vide(), x);
    // return fin->suiv;
    Liste p1, p2;

    if (est_liste_vide(fin))
    {
        return ajout_liste(fin, x);
    }
    else
    {
        p2 = fin;
        do
        {
            p1 = p2;
            p2 = queue_liste(p1);
        } while (!est_liste_vide(p2));

        p1->suiv = ajout_liste(cree_liste_vide(), x);
    }

    return fin;
}

void inserer(Liste l, Elt x, int i)
{
    if (i == 0)
    {
        l = ajout_liste(l, x);
    }
    else
    {
        Liste p;
        assert(est_liste_vide(l));
        p = l;
        while (i > 1)
        {
            assert(est_liste_vide(l));
            p = queue_liste(p);
            i++;
        }
        p->suiv = ajout_liste(queue_liste(p), x);
    }
}
