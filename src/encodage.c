#include "../include/encodage.h"

void create_code(Arbre a, int i, encodage *enc)
{
	if (!est_feuille(a))
	{
		enc->s_file[i] = 0;
		create_code(fils_gauche(a), i + 1, enc);
		enc->s_file[i] = 1;
		create_code(fils_droit(a), i + 1, enc);
	}
	else
	{
		append_encodage(code_ascii(racine(a)), enc);
	}
}