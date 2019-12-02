#include "../include/encodage.h"

void create_code(arbre *a, int i, encodage *enc)
{
	if (!est_feuille(a))
	{
		enc->s_file[i] = 0;
		create_code(a->fils_gauche, i + 1, enc);
		enc->s_file[i] = 1;
		create_code(a->fils_droit, i + 1, enc);
	}
	else
	{
		append_encodage(code_ascii(a->c), enc);
	}
}