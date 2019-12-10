#include "../include/menu_action.h"

int choose_path(char *out_c)
{
	if (scanf("%s", out_c) < 0)
	{
		return -1;
	}
	return 0;
}
