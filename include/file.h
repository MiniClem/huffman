#ifndef __file_h__
#define __file_h__
#include "arbre.h"
#include <string.h>
#include <math.h>

typedef unsigned char byte;

FILE *ouvrir_fichier(char *filename, char *mode);
void fermer_fichier(FILE *file);

unsigned char *lire_caractere_fichier(char *file);

void ecrire_caractere_fichier(char *filename, unsigned char *message, int size);
void ecrire_bytes_fichier(char *filename, byte *message, int size);

byte *char_to_byte(unsigned char *char_to_convert);
unsigned char *byte_to_char(byte byte_to_convert);

#endif