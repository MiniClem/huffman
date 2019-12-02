#include "file.h"

void creer_file_vide(File *file)
{
	file->premier = NULL;
	file->dernier = NULL;
}

int est_file_vide(File file)
{
	return (file.premier == NULL);
}

void enfiler(File *file, Elt x)
{
	Maillon *nouveau;
	nouveau = (Maillon *)malloc(sizeof(Maillon));
	nouveau->suiv = file->premier;

	if (est_file_vide(*file))
	{
		file->dernier = nouveau;
	}
}

Elt defiler(File *p_file)
{
	Elt x;
	Maillon *m;

	assert(!est_file_vide(*p_file));

	x = tete_liste(p_file->premier);
	m = queue_liste(p_file->premier);

	if (p_file->premier == p_file->dernier)
	{
		p_file->dernier = NULL;
	}

	free(p_file->premier);
	p_file->premier = m;
	return x;
}