#include <stdio.h>
#include <stdlib.h>

char *lire_caractere_fichier(FILE *file)
{
	int i = 0;
	while (fgetc(file) != EOF)
	{
		i++;
	}

	char *caracterelu = (char *)malloc(i * sizeof(char));
	printf("%d", i);
	rewind(file);
	int j = i;
	i = 0;
	// Boucle de lecture des caractères un à un
	while (i < j)
	{
		caracterelu[i] = (char)fgetc(file); // On lit le caractère

		i++;
	} // On continue tant que fgetc n'a pas retourné EOF (fin de file)

	caracterelu[i + 1] = '\0';
	fclose(file);

	return caracterelu;
}

char *char_to_byte(char char_to_convert)
{
	char *str = (char *)malloc(8 * sizeof(char));
	int a = 128;
	int i = 0;

	for (i = 0; i < 8; i++)
	{
		if (((int)char_to_convert & a) == 0)
		{
			str[i] = '0';
		}
		else
		{
			str[i] = '1';
		}

		a = a / 2;
	}

	return str;
}

int main()
{
	char c = 'A';
	/*FILE* fichier = NULL;
	fichier = fopen("test.txt", "r");
	if (fichier != NULL)
    {
	printf("%s",lire_caractere_fichier(fichier));
	}
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le file test.txt");
    }
	*/
	char *test = char_to_byte(c);
	printf("%s", test);
	return 0;
}