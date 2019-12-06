#ifndef __file_h__
#define __file_h__
#include "arbre.h"
#include <string.h>
#include <math.h>

typedef char byte;

void ecrire_bit(FILE *file, char bit);
void lire_bit(FILE *file);

byte *char_to_byte(char *char_to_convert);
char *byte_to_char(byte char_to_convert);

#endif