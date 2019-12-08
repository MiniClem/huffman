#include "../include/decodage.h"



Arbre lire_dico(char* code)
{
	static int compteur=0;
	Arbre Pere = (Arbre)malloc(sizeof(Noeud));
	Arbre filsgauche = (Arbre)malloc(sizeof(Noeud));
	Arbre filsdroit = (Arbre)malloc(sizeof(Noeud));
	if (*(code+compteur)=='0')
	{
		compteur ++;
		filsgauche = lire_dico(code+compteur);
		
		filsdroit = lire_dico(code+compteur);
		;

	}else{
		
		Pere = creer_arbre(lire_ascii(code+compteur),0,NULL,NULL);
		
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

void decode(char* code, char* clair, Arbre decodage)
{
	if(est_feuille(decodage){
		*clair = decodage->elt;
		clair++;
		return;

	}else if (*code == '\0'){
		return
	}
	
	
	if(*code=='0')
	{
		decode(++code , clair, fils_gauche(decodage));
		
	}else{
		decode(++code , clair, fils_droit(decodage));
	}
	return;
}


// TESTS
int main(){
	char* code = "00010100000110100001110110010100101101001101100111";
	//Arbre d = lire_dico(code);
	
	return  0;
}
