#ifndef __encodage_h__
#define __encodage_h__
#include "arbre.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./file.h"

#define ASCII_SIZE 9
#define NB_ASCII 256

typedef struct encodage
{
	unsigned char *s_enc;
	byte *b_enc;
	int b_length;
	Arbre dico;
	int *tab_frequences;
} encodage;
typedef encodage *p_encodage;

/**
 * @brief Initialise une structure encodage qui sera uitilisée pour compresser un message.
 */
p_encodage create_encodage();

/**
 * @brief Script complet de compression
 * @param path_to_file : Chemin d'accès au fichier à compresser. Un chemin relatif par exemple "./test.txt"
 */
void compress(char *path_to_file);

/**
 * @brief Méthode interne qui réalise la création du message encodé
 */
void compress_encodage(p_encodage p_enc);

/**
 * @brief Crée une liste d'arbre à partir des fréquences contenues dans l'encodage
 * @param enc : L'encodage à utiliser
 * @param size : Un int donnée résultat pour stocker la taille de la liste créée
 * @return La liste d'Arbre créée
 */
Arbre *creer_liste_arbre(p_encodage enc, int *size);

/**
 * @brief D'après l'algorithme de Huffman, dans une liste d'arbre et combine les 2 arbres de poid les plus faibles
 * @param l : La liste d'arbre
 * @param size : La taille de la liste
 * @return : 1 si l'algorithme est terminé, 0 après une itération n.
 */
int trouver_combiner(Arbre *l, int size);

/**
 * @brief Méthode interne pour réaliser l'algorithme d'Huffman.
 * @param enc : La structure encodage contenant les données nécessaire à la réalisation d'Huffman.
 */
void huffman(p_encodage enc);

/**
 * @brief Méthode interne de Huffman qui permet de réaliser la combinaison des arbres puis de renvoyer 
 * l'arbre qui en résulte.
 * @return L'arbre créée, résultant de l'algorithme d'Huffman, il nous permettra de coder/décoder notre message, 
 * il sert aussi à faire le dictionnaire de caractères.
 */
Arbre huffman_merge(Arbre *l, int size);

/** 
 * Libere l'encodage
 */
void destruct_encodage(p_encodage enc);

/**
 * @brief Récupère la chaine de caractère actuellement déjà encodée de l'encodage donné
 * @param enc : L'encodage duquel récupérer la chaine déjà encodée
 * @return Une chaine de caractère contenant l'encodage 
 */
unsigned char *s_encodage(p_encodage enc);

/**
 * @brief Récupère la valeur des fréquences stockés dans la structure encodage
 * @param enc : l'encodage que l'on souhaite
 */
int *t_frequences(p_encodage enc);

/**
 * @return Renvoie le caractère à la position i de l'encodage 
 */
unsigned char charAt_encodage(int i, p_encodage enc);

/**
 * @brief Fonction d'append pour ajouter une chaine de caractère à l'encodage
 * @param chaine : La chaine à ajouter à l'encodage
 * @param enc : L'encodage qui se verra append
 */
void append_encodage(unsigned char *chaine, p_encodage enc);

/**
 * @brief Converti un char en son homologue binaire
 * @param carac : le caractère à convertir en binaire
 * @param tab_bin : le tableau qui contiendra les bits correspondant du caractère.
 */
void code_ascii(unsigned char carac, unsigned char tab_bin[ASCII_SIZE]);

/**
 * @brief Méthode interne pour transformer un entier en binaire dans une liste de caractères allouée
 * @param entier : L'entier à convertir
 * @param s : La chaine qui contiendra l'écriture binaire sur ASCII_SIZE bits.
 */
void binaire(int entier, unsigned char s[ASCII_SIZE]);

/**
 * @brief Méthode interne pour calculer les fréquences des caractères dans un message.
 * @param m : Le message à utiliser pour calculer les fréquences.
 * @param enc : La structure à utiliser pour stocker les fréquences calculés.
 */
void frequences(unsigned char *m, p_encodage enc);

/**
 * @brief Affiche dans la console l'encodage trouvé
 * @param enc : L'encodage à afficher
 */
void print_encodage(p_encodage enc);

/**
 * @brief Crée le code de l'arbre du dico, permettra de reconstruire l'arbre dans le décodage 
 * d'après la séquence de 0 et 1 créée.
 * @param dico : L'arbre créé pour le dictionnaire
 * @param enc : L'encodage contenant les données du message.
 */
void create_code_arbre(Arbre dico, p_encodage enc);

/**
 * @brief traduit le message selon le dictionnaire contruit au préalable dans l'encodage
 * @param enc : L'encodage à uttiliser contenant le dictionnaire
 * @param m : Le message à traduire
 */
void create_code_texte(p_encodage enc, unsigned char *m);

#endif