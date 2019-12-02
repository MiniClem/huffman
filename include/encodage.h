#ifndef __encodage_h__
#define __encodage_h__

// TBD
typedef struct arbre
{
	struct arbre *fils_gauche;
	struct arbre *fils_droit;
	char c;
} arbre;

// TBD
extern int est_feuille(arbre *); // TDA
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

void create_code(arbre *a, int i, encodage *enc);

#endif