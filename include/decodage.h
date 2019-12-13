#ifndef __decodage_h__
#define __decodage_h__
#include "./arbre.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>


/* 
 * Prend en argument la chaine de caractère comportant que des '0' et '1';
 * Retourne l'arbre permettant de décoder le texte;
 * Le pointeur sur la chaine de caractère aura avancé et indiqueras désormais 
 * le début de la séquence à décoder
*/
Arbre lire_dico(unsigned char* code , int * ind);


/* 
 * Renvoie le code ascii dans un int corespondant à une chaine de caractères de 8 octets 
 * Correspondant à la traduction des 8bits
*/

Elt lire_ascii(unsigned char* octet);


/* 
 * Renvoie le texte clair à partir du texte compressé et de l'arbre de décodage des caratères

 * on prend une chaine de caractères, on parcourt l'arbre
 * Tant qu'on n'est pas arrivé au bout de la chaine, 
 * on ajoute dans sequence la valeur de *code.
 * on teste si on arrive sur une feuille. si on est sur une feuille
 * on met le caractère dans clair. Si on n'arrive pas à une feuille,
 * on relance la boucle
 */
unsigned char * decode(unsigned char* code, unsigned char* clair, Arbre decodage, unsigned char* sequence);

/*
 * Parcourt l'arbre pendant le décodage de la chaine de caractères 
	si on rencontre un 0, appel récursif sur le fils gauche
	si on rencontre un 1, appel récursif sur le fils droit
	si c'est une feuille, on affiche le caractère
 */
char parcours_arbre(unsigned char* sequence, Arbre decodage, int i);

char* append_char(char* out_c, char app);
unsigned char* unsigned_append_char(unsigned char* out_c, unsigned char app);

int decompressage(char* filename);


#endif