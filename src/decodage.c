#include <string.h>
#include "../include/decodage.h"
#include <assert.h>

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

		filsgauche = lire_dico(code,++compteur);
		filsdroit = lire_dico(code,++compteur);

		Pere=creer_arbre(' ', 0 , filsgauche, filsdroit) ;

	}else{
		
		Pere = creer_arbre(lire_ascii(code+compteur),0,NULL,NULL);
		
	}
	return Pere;
}
 */

Elt lire_ascii(char* octet,int compteur)
{
	
	int valeur =0;
	int i ; 
	for(i=7; i>=0;i--){
		if (*octet=='1'){
			valeur += pow(2,i);
		}
		compteur++;		
	}
	Elt ascii = (Elt)valeur;
	printf("%c \n",valeur);
	return ascii;
}


/* 
on prend une chaine de caractères, on parcourt l'arbre
Tant qu'on n'est pas arrivé au bout de la chaine, 
on ajoute dans sequence la valeur de *code.
on teste si on arrive sur une feuille. si on est sur une feuille
on met le caractère dans clair. Si on n'arrive pas à une feuille,
on relance la boucle


*/

void decode(char* code, char* clair, Arbre decodage, char* sequence)
{
	int j=0;
	int i=0;
	while(*code != '\0'){
		printf("on ajoute %c dans sequence\n",*code) ;
		
		sequence = append_char(sequence, *code);
		j+=1;
		i+=1;
		
		printf("i= %d  j= %d *code=%c\n\n",i,j,*code) ;
		printf("sequence : %s\n",sequence) ;
		printf("parcours arbre retourne = %d \n",parcours_arbre(sequence,decodage,i)) ;
		if(parcours_arbre(sequence,decodage,i) != 0){
			printf("if ok \n") ;	
			clair = append_char(clair,parcours_arbre(sequence,decodage,i));
			printf("%c",parcours_arbre(sequence,decodage,i));
			sequence= "" ;
			i=0 ;
		}
		code++;
	}

	clair[j] = '\0';
	
	return;
} 



char parcours_arbre(char* sequence, Arbre decodage, int i) 
{
	assert(!est_arbre_vide(decodage)) ;
	if(est_feuille(decodage)) { 
		printf("on est sur une feuille \n") ;
		printf("ON RETOURNE %c\n",decodage->elt) ;
		return decodage->elt ;
	}
	if(sequence[i+1] == '\0'){
		printf("la sequence est terminee ON RETOURNE ZERO \n") ;
		return 0 ;
	}


	if(sequence[i-1] == '0'){
		printf("carac : %c\n", sequence[i-1]) ;
		printf("on passe par le 0 \n\n") ;
		return parcours_arbre(sequence, fils_gauche(decodage),++i) ;
	}
	else{
		printf("carac : %c\n", sequence[i-1]) ;
		printf("on passe par le 1 \n\n") ;
		return parcours_arbre(sequence, fils_droit(decodage),++i) ;
	}


}

static char* append_char(char* out_c, char app){
	int size = strlen(out_c) + 2;
	char* new_c = malloc(size); // Nouvelle allocation mémoire

	strcpy(new_c, out_c); 	// Copie première s
	new_c[size -2] = app;		// Copie seconde s
	new_c[size - 1] = '\0';
	free(out_c);
	return new_c;
}

// TESTS
int main(){
	//char* code = "00010100000110100001110110010100101101001101100111";
	
	Arbre a = creer_arbre('a',0,NULL,NULL);
	Arbre b = creer_arbre('b',0,NULL,NULL);
	Arbre ab = creer_arbre('0',0,a,b);
	Arbre c = creer_arbre('c',0,NULL,NULL);
	Arbre abc = creer_arbre('0',0,ab,c);
	
	char* code= "01101100";
	char* clair = NULL; 

	int i = 0 ;
	
	//parcours_arbre("01",abc,i) ;

	decode(code,clair,abc,"");
	printf("clair: %s \n",clair) ;
	
	/*
	while (*clair = '\0')
	{
		printf("%c",*clair);
		clair++;
	}
	
	char* code = malloc(3 * sizeof(char)) ;
	code[0] = '1';
	code[1] = '0';
	code[2] = '\0';

	char app = '1';
	code = append_char(code, app);

	printf("%s\n", code);
	free(code);
	return  0; */
}