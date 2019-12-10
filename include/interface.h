#ifndef _INTERFACE_H_
#define _INTERFACE_H_

/**
 * @brief Lit un entier a la console et retourne sa valeur 
 * @return : L'entier choisi par l'utilisateur.
 */
int lire_entier();

/** 
 * @brief affiche a la console l'entier passe en parametre 
 */
void afficher_entier(int x);

/**
 * @brief affiche a la console la chaine passee en parametre 
 */
void afficher_chaine(char *s);
#endif