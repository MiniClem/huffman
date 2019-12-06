#include "../include/decodage.h"



Arbre lire_dico(char* code)
{
	static int compteur=0;
	Arbre Pere;
	Arbre filsgauche;
	Arbre filsdroit;
	if (code[0]=='0')
	{
		filsgauche = lire_dico((&(code[compteur +1])));
		
		filsdroit = lire_dico(code[compteur +1]);
		Pere = creer_arbre('0',0,filsgauche,filsdroit);

	}else{
		
		
		Pere = creer_arbre(lire_ascii(code[compteur +1]),0,NULL,NULL);
	}
	return Pere;
}
 

Elt lire_ascii(char* octet)
{
	
	int valeur =0;
	int i ; 
	for(i=7; i>=0;i--){
		if (*octet=='1'){
			valeur += pow(2,i);
		}
		octet++;		
	}
	Elt ascii = (Elt)valeur;
	printf("%c \n",valeur);
	return ascii;
}


// TESTS
int main(){
	char* code = "01100000111000010";
	Arbre d = lire_dico(code);

	
	return  0;
}
