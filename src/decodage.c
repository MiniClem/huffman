#include "../include/decodage.h"



Arbre lire_dico(char* code)
{
	static int compteur=0;
	Arbre Pere;
	Arbre filsgauche;
	Arbre filsdroit;
	if (code[0]='0')
	{
		compteur++;
		filsgauche = lire_dico(code + compteur);
		compteur++;
		filsdroit = lire_dico(code + compteur);
		Pere = creer_arbre(0,0,filsgauche,filsdroit);

	}else{
		
		compteur++;
		Pere = creer_arbre(lire_ascii(code+compteur),0,NULL,NULL);
	}
	return Pere;
}


Elt lire_ascii(char* octet)
{
	Elt valeur = 0;
	int i ; 
	for(i=7; i>=0;i--){
		if (*octet=='1'){
			valeur += pow(2,i);
		}
		octet++;		
	}
	printf("%c",valeur);
	return valeur;
}


// TESTS
int main(){
	char* code = "01100000111000010";
	Arbre d = lire_dico(code);

	
	return  0;
}
