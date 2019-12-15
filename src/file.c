#include <stdio.h>
#include <stdlib.h>
#include "../include/file.h"

// mode écriture : "w"
// mode lecture : "r"
FILE *ouvrir_fichier(char *filename, char *mode)
{
	FILE *fichier = fopen(filename, mode);
	assert(fichier != NULL);
	return fichier;
}

void fermer_fichier(FILE *file)
{
	fclose(file);
	file = NULL;
}

unsigned char *lire_caractere_fichier(char *file)
{

	int size;
	unsigned char *caracterelu;
	FILE *fichier = ouvrir_fichier(file, "r");

	if (fichier)
	{
		// Calcule la taille d'un fichier
		fseek(fichier, 0L, SEEK_END);
		size = ftell(fichier);
		rewind(fichier);

		caracterelu = (unsigned char *)malloc((size + 1) * sizeof(unsigned char));

		// Boucle de lecture des caractères un à un
		for (int i = 0; i < size; i++)
		{
			caracterelu[i] = (unsigned char)fgetc(fichier); // On lit le caractère
		}													// On continue tant que fgetc n'a pas retourné EOF (fin de file)
		caracterelu[size] = '\0';

		fermer_fichier(fichier);
	}
	else
	{
		printf("ERREUR DE LECTURE DU FICHIER\n");
	}

	return caracterelu;
}

byte *char_to_byte(unsigned char *char_to_convert)
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

unsigned char *byte_to_char(byte byte_to_convert)
{
	unsigned char *str = calloc(9, sizeof(unsigned char));
	int a = 128;

	int i;
	for (i = 0; i < 8; i++)
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

	str[i] = '\0';
	return str;
}

void ecrire_caractere_fichier(char *filename, unsigned char *message, int size)
{ //ecrit dans le fichier de nom filename , le message compréser
	FILE *fichier = ouvrir_fichier(filename, "w");

	printf("Ecriture de %d octets dans %s\n", size, filename);
	fwrite(message, sizeof(unsigned char), size, fichier);
	//fputs(message,fichier);
	fermer_fichier(fichier);
}

void ecrire_bytes_fichier(char *filename, byte *message, int size)
{
	ecrire_caractere_fichier(filename, message, size);
}

/*
int main()
{
	// FICHIER
	//char *filename = "test.txt";
	char *file = "kak.txt";
	// FILE *file = ouvrir_fichier(filename);
	// char *m = lire_caractere_fichier(file);
	// FICHIER

	//char c = 'A';
	char c[] = "{'0', '1', '0', '0', '0', '0', '0', '1'}";
	// byte b = (char)0b01000001;

	// byte b[] = {0b00000000, 0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000001};
	// FILE* fichier = NULL;
	// fichier = fopen("test.txt", "r");
	// if (fichier != NULL)
	// {
	// printf("%s",lire_caractere_fichier(fichier));
	// }
	// else
	// {
	//     // On affiche un message d'erreur si on veut
	//     printf("Impossible d'ouvrir le file test.txt");
	// }

	// byte *test = char_to_byte(c);
	// char *test_c = byte_to_char(b);
	// printf("%c\n", test[0]);
	// printf("%s\n", test_c);

	ecrire_caractere_fichier(file, c, strlen(c));
	return 0;
}
*/