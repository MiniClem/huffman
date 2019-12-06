#ifndef __decodage_h__
#define __decodage_h__
#include "./arbre.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>


/* 
 * Prend en argument la chaine de charactère comportant que des '0' et '1';
 * Retourne l'arbre permettant de décoder le texte;
 * Le pointeur sur la chaine de charactère aura avancé et indiqueras désormais 
 * le début de la séquence à décoder
*/
Arbre lire_dico(char* code);


/* 
 * Renvoie le code ascii dans un int corespondant à une chaine de charactères de 8 octets 
 * Correspondant à la traduction des 8bits
*/

Elt lire_ascii(char* octet );

#endif