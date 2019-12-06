#include "../include/decodage.h"



Arbre lire_dico(char* code)
{
	//utiliser fonction créer_arbre_vide
	//utiliser fonction association fils_gauche et fils_droit
	static int compteur=0;
	Arbre Pere = (Noeud *) malloc(sizeof(Noeud));
	Arbre filsgauche = (Noeud *) malloc(sizeof(Noeud)) ;
	Arbre filsdroit = (Noeud *) malloc(sizeof(Noeud)) ;
	if (*(code+compteur)=='0')
	{
		filsgauche = lire_dico(code+(++compteur));
		
		filsdroit = lire_dico(code+(++compteur));
		Pere = creer_arbre('0',0,filsgauche,filsdroit);

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


// TESTS
int main(){
	char* code = "0010100000110100001110110010100101101001101100111";
	//char* ascii = "01000001" ;
	Arbre d = lire_dico(code);
	
	return  0;
}
