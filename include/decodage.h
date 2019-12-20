#ifndef __decodage_h__
#define __decodage_h__
#include "./arbre.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "./encodage.h"
#include "./file.h"

/**
 * @brief  Retourne l'arbre permettant de décoder le texte Le pointeur sur la chaine de caractère aura avancé et 
 * indiquera désormais le début de la séquence à décoder
 * @param code : la chaine de caractère composée de 0 et de 1
 * @param arbre : représentation du dico créé
 * @param ind : pour parcourir la chaîne de caractères
 */
void lire_dico(unsigned char *code, int *ind, Arbre a);

/**
 * @brief  Renvoie le code ascii dans un int correspondant à une chaine de caractèreds de 8 octets correspondant à la traduction des 8 bits.
 * @param octet : caractère qu'on va traduire en ascii (composé de 8 bit).
 * @return élément en ascii
 */
Elt lire_ascii(unsigned char *octet);

/**
 * @brief  Renvoie le texte clair à partir du texte compressé et de l'arbre de décodage des caratères
 * on prend une chaine de caractères, on parcourt l'arbre
 * @param code : la chaine de caractère composée de 0 et de 1
 * @param clair : la chaine de caractères dans laquelle on va placer le message décodé.
 * @param decodage : l'arbre du dictionnaire.
 * @param sequence : chaine dans laquelle on stock au fur et à mesure pour parcourir l'arbre.
 * @return chaine de caractère décodée
 */
unsigned char *decode(unsigned char *code, unsigned char *clair, Arbre decodage, unsigned char *sequence);

/**
 * @brief  Parcourt l'arbre pendant le décodage de la chaine de caractères.
 * @param sequence : la chaine de caractère composée de 0 et de 1 qui représente un caractère en code huffman
 * @param decodage : l'arbre qu'on parcourt 
 * @param i : compteur
 * @return caractère correspondant à la séquence
 */
char parcours_arbre(unsigned char *sequence, Arbre decodage, int i);

/**
 * @brief  Ajout d'un caractère dans une chaine de caractère.
 * @param out_c : chaine dans laquelle on va ajouter un caractère (à la fin)
 * @param app : caractère non signé qu'on ajoute à la fin de la chaine out_c
 * @return la chaine dans laquelle un caractère a été ajouté
 */
unsigned char *unsigned_append_char(unsigned char *out_c, unsigned char app);

/**
 * @brief  Fonction de décompression de l'encodage
 * @param enc : encodage
 * @param size_file : taille du fichier
 * @return retourne le même fichier mais avec un char associé à chaque bit
 */
unsigned char *decompress_encodage(byte *enc, int size_file);

/**
 * @brief  Fonction de décompression du fichier qui fait appel à decompress_encodage
 * @param filename : fichier qu'on veut décompresser
 */
int decompression(char *filename);

#endif