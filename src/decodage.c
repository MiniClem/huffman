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

void decode(char* code, char* clair, Arbre decodage, char* sequence)
{
	int i=0,j=0;
	while(*code != '\0'){
		sequence = append_char(sequence, *code);
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
	assert(!est_arbre_vide(decodage)) ;
	if(est_feuille(decodage)) { 
		printf("on est sur une feuille \n") ;
		printf("%c",decodage->elt) ;
		return decodage->elt ;
	}
	if(*sequence == '\0'){
		printf("la séquence est terminée") ;
		return 0 ;
	}
	if(*sequence == '0'){
		printf("carac : %c\n", *sequence) ;
		printf("on passe par le 0 \n\n") ;
		sequence++ ;
		return parcours_arbre(sequence, fils_gauche(decodage)) ;
	}
	else if(*sequence == '1'){
		printf("carac : %c\n", *sequence) ;
		printf("on passe par le 1 \n\n") ;
		sequence++ ;
		return parcours_arbre(sequence, fils_droit(decodage)) ;
	}

	return 0 ;
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
	
	/*char* code= "00101100";
	char* clair = NULL; */
	
	parcours_arbre("11",abc) ;

	//decode(code,clair,abc, );
	
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