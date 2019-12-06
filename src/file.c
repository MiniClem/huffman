#include <stdio.h>
#include <stdlib.h>
#include "../include/file.h"

char *lire_caractere_fichier(FILE *file)
{
	long size;

	fseek(file, 0L, SEEK_END);
	size = ftell(file);

	char *caracterelu = (char *)malloc((size + 1) * sizeof(char));
	rewind(file);

	// Boucle de lecture des caractères un à un
	for (int i = 0; i < size; i++)
	{
		caracterelu[i] = (char)fgetc(file); // On lit le caractère
	}										// On continue tant que fgetc n'a pas retourné EOF (fin de file)
	caracterelu[size] = '\0';

	fclose(file);
	return caracterelu;
}

byte *char_to_byte(char *char_to_convert)
{
	byte *str = (byte *)calloc(1, sizeof(byte));
	int a = 128; // 0b10000000

	for (int i = 0; i < 8; i++)
	{
		if (char_to_convert[i] == '1')
		{
			*str |= a;
		}

		a /= 2;
	}

	return str;
}

char *byte_to_char(byte byte_to_convert)
{
	char *str = calloc(9, sizeof(char));
	int a = 128;

	for (int i = 0; i < 8; i++)
	{
		if (((int)byte_to_convert & a) > 0)
		{
			str[i] = '1';
		}
		else
		{
			str[i] = '0';
		}
		a /= 2;
	}
	return str;
}

int main()
{
	//char c = 'A';
	char c[] = {'0', '1', '0', '0', '0', '0', '0', '1'};
	byte b = (char)0b01000001;

	// byte b[] = {0b00000000, 0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000001};
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
	byte *test = char_to_byte(c);
	char *test_c = byte_to_char(b);
	printf("%c\n", test[0]);
	// printf("%s\n", test_c);
	return 0;
}