#include "../include/decodage.h"

/*

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
 */

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
	char* sequence;
	int i=0,j=0;
	while(*code != '\0'){
		
		*sequence = *code;
		i+=1;
		j+=1;
		printf("i= %d , j= %d *code=%c\n",i,j,*code) ;

		if(parcours_arbre(sequence,decodage) != 0){
			printf("if ok \n") ;	
			sequence -= i ;
			i = 0 ;  

			*clair = parcours_arbre(sequence,decodage);
			printf("%c",parcours_arbre(sequence,decodage));
			clair++;
				
		}
		code++;
	}
	*clair='\0';

	return;
}


char parcours_arbre(char* sequence, Arbre decodage)
{
	if (!est_arbre_vide(decodage))
	{
		if(est_feuille(decodage)) return decodage-> elt ;
		
		if(*(sequence+1)='\0') return 0 ;

		printf("parcours arbre chillin \n") ;
		
		sequence++ ;
		if(*(sequence)=='0') return (parcours_arbre(sequence,fils_gauche(decodage))) ;
		return(parcours_arbre(sequence, fils_droit(decodage))) ;
	}
}

// TESTS
int main(){
	//char* code = "00010100000110100001110110010100101101001101100111";
	Arbre a = creer_arbre('a',0,NULL,NULL);
	Arbre b = creer_arbre('b',0,NULL,NULL);
	Arbre ab = creer_arbre('0',0,a,b);
	Arbre c = creer_arbre('c',0,NULL,NULL);
	Arbre abc = creer_arbre('0',0,ab,c);
	
	char* code= "00101100";

	char* clair = NULL;


	decode(code,clair,abc);
	/*
	while (*clair = '\0')
	{
		printf("%c",*clair);
		clair++;
	}
	*/
	return  0;
}