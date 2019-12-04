#ifndef __encodage_h__
#define __encodage_h__
#include "arbre.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ASCII_SIZE 8

// TBD
typedef struct encodage
{
	char *s_enc;
} * p_encodage;

p_encodage create_encodage();

/**
 * @brief Récupère l'index de position dans la chaine de caractère stocké par enc
 * @return L'index de position, par exemple si la chaine vient d'être créée, la fonction renverra 
 * 1 car le caractère '0\' est présente.
 */
int cursor(p_encodage enc);

/* 
 * Libere l'encodage
 */
void destruct_encodage(p_encodage enc);

/**
 * @brief Récupère la chaine de caractère actuellement déjà encodée de l'encodage donné
 * @param enc : L'encodage duquel récupérer la chaine déjà encodée
 * @return Une chaine de caractère contenant l'encodage 
 */
char *s_encodage(p_encodage enc);

/**
 * @return Renvoie le caractère à la position i de l'encodage 
 */
char charAt_encodage(int i, p_encodage enc);

/**
 * @brief Fonction d'append pour ajouter une chaine de caractère à l'encodage
 * @param chaine : La chaine à ajouter à l'encodage
 * @param enc : L'encodage qui se verra append
 */
void append_encodage(char *chaine, p_encodage enc);

/**
 * @brief Converti un char en son homologue binaire
 * @param carac : le caractère à convertir en binaire
 * @param tab_bin : le tableau qui contiendra les bits correspondant du caractère.
 */
void code_ascii(char carac, char tab_bin[ASCII_SIZE]);

void frequences(char *, int tab_frequence[255]);

void print_encodage(p_encodage enc);

void create_code(Arbre a, int i, p_encodage enc);

#endif