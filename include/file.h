#ifndef __file_h__
#define __file_h__
#include "arbre.h"
#include <string.h>
#include <math.h>

typedef unsigned char byte;
/**
 * @brief ouvre le fichier de nom filename avec le mode "mode" 
 * @param filename : nom du fichier a ouvrir
 * @param mode : mode d'ouverture
 * @return Le fichier ouvert
 */
FILE *ouvrir_fichier(char *filename, char *mode);

/**
 * @brief ferme le fichier de nom filename
 * @param filename : nom du fichier a fermer
 */
void fermer_fichier(FILE *file);

/**
 * @brief creer une liste de caractères contenant les caractère du fichier lu
 * @param file : nom du fichier
 * @return La liste de caractère créer
 */
unsigned char *lire_caractere_fichier(char *file);

/**
 * @brief creer une liste de byte contenant les byte du fichier lu
 * @param file : nom du fichier
 * @return La liste de byte créer
 */
byte *lire_byte_fichier(char *file, int *size);

/**
 * @brief ecrit une liste de char dans le fichier de nom filename avec une taille d'ecriture size pour le nombre d'octets ecrit dans filename
 * @param file : nom du fichier
 * @param message : liste de caractère a ecrire
 * @param size : taille de l'écriture
 */
void ecrire_caractere_fichier(char *filename, unsigned char *message, int size);

/**
 * @brief ecrit une liste de byte dans le fichier de nom filename avec une taille d'ecriture size pour le nombre d'octets ecrit dans filename
 * @param file : nom du fichier
 * @param byte : liste de byte a ecrire
 * @param size : taille de l'écriture
 */
void ecrire_bytes_fichier(char *filename, byte *message, int size);

/**
 * @brief convertit un cractère en byte
 * @param char_to_convert : caractère a convertir
 */
byte *char_to_byte(unsigned char *char_to_convert);

/**
 * @brief convertit un byte en caractère
 * @param char_to_convert : byte a convertir
 */
unsigned char *byte_to_char(byte byte_to_convert);

#endif