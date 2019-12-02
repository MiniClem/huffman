#include "liste.h"

typedef struct file
{
	Maillon *premier;
	Maillon *dernier;
} File;

void creer_file_vide(File *file);

int est_file_vide(File file);

void enfiler(File *file, Elt x);

Elt defiler(File *p_file);