#ifndef __encodage_h__
#define __encodage_h__
#include "arbre.h"

// TBD
extern char *code_ascii(char); // Donne la chaine de caractère des bits qui constituent le code ASCII du caractère donné en param

// TBD
typedef struct
{
	char *s_file;
} encodage;

// fonction d'append pour ajouter une chaine de caractère à l'encodage
// TBD
void append_encodage(char *, encodage *);

void create_code(Arbre *a, int i, encodage *enc);

#endif