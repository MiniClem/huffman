#ifndef __encodage_h__
#define __encodage_h__
#include "arbre.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ASCII_SIZE 9

typedef struct encodage
{
	char *s_enc;
	Arbre dico;
	int *tab_frequences;
} encodage;
typedef encodage *p_encodage;

p_encodage create_encodage();

/**
 * @brief Crée une liste d'arbre à partir des fréquences contenues dans l'encodage
 * @param enc : L'encodage à utiliser
 * @param size : Un int donnée résultat pour stocker la taille de la liste créée
 * @return La liste d'Arbre créée
 */
Arbre *creer_liste_arbre(p_encodage enc, int *size);

int trouver_combiner(Arbre *l, int size);

Arbre huffman(p_encodage enc);

Arbre huffman_merge(Arbre *l, int size);

/**
 * @brief Récupère l'index de position dans la chaine de caractère stocké par enc
 * @return L'index de position, par exemple si la chaine vient d'être créée, la fonction renverra 
 * 1 car le caractère '0\' est présente.
 */
int cursor(p_encodage enc);

/** 
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
 * @brief Récupère la valeur des fréquences stockés dans la structure encodage
 * @param enc : l'encodage que l'on souhaite
 */
int *t_frequences(p_encodage enc);

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

void binaire(int entier, char s[ASCII_SIZE]);

void frequences(char *, p_encodage enc);

void print_encodage(p_encodage enc);

void create_code_arbre(Arbre a, p_encodage enc);

void create_code_texte(Arbre dico, p_encodage enc, char *m);

#endif