#ifndef __MENU_ACTION_H__
#define __MENU_ACTION_H__
#include "stdio.h"
#include "../include/encodage.h"
#include "../include/decodage.h"

/**
 * @brief Permet à l'utilisateur de sélectionner un chemin de fichier
 * @param out_c : La variable qui stockera le résultat, doit être assez grande pour contenir un chemin.
 * @return : 0 si aucune erreur, -1 sinon
 */
int choose_path(char *out_c);

void compress_selected(char *path_to_file);

void decompress_selected(char *path_to_file);

void help();

#endif