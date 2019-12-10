#ifndef __MENU_ACTION_H__
#define __MENU_ACTION_H__
#include "stdio.h"

/**
 * @brief Permet à l'utilisateur de sélectionner un chemin de fichier
 * @param out_c : La variable qui stockera le résultat, doit être assez grande pour contenir un chemin.
 * @return : 0 si aucune erreur, -1 sinon
 */
int choose_path(char *out_c);

// int compress(char * path_to_file);
// int uncompress(char * path_to_file);

#endif