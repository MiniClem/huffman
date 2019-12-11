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

Elt lire_ascii(unsigned char* octet,int compteur)
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

unsigned char* decode(unsigned char* code, unsigned char* clair, Arbre decodage, unsigned char* sequence)
{
	while(*code != '\0'){
			
		sequence = unsigned_append_char(sequence, *code);
		char c = parcours_arbre(sequence,decodage,0);

		if(c != 0){
			clair = unsigned_append_char(clair,c);
			free(sequence) ;
			sequence=malloc(sizeof(unsigned char *)) ;
			sequence[0]='\0' ;
		}
		code++;
	}
	return clair ;
} 



char parcours_arbre(unsigned char* sequence, Arbre decodage, int i) 
{
	assert(!est_arbre_vide(decodage)) ;
	if(est_feuille(decodage)) { 
		return decodage->elt ;
	}
	if(sequence[i] == '\0'){
		return 0 ;
	}


	if(sequence[i] == '0'){
		return parcours_arbre(sequence, fils_gauche(decodage),++i) ;
	}
	else{
		return parcours_arbre(sequence, fils_droit(decodage),++i) ;
	}


}

unsigned char* unsigned_append_char(unsigned char* out_c, char app){
	int size = strlen((char *)out_c) + 2;
	unsigned char* new_c = malloc(size); // Nouvelle allocation mémoire

	strcpy((char *)new_c, (char *)out_c); 	// Copie première s
	new_c[size -2] = app;		// Copie seconde s
	new_c[size - 1] = '\0';
	free(out_c);
	return new_c;
}


char* append_char(char* out_c, char app){
	int size = strlen(out_c) + 2;
	char* new_c = malloc(size); // Nouvelle allocation mémoire

	strcpy((char *)new_c, (char *)out_c); 	// Copie première s
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
	
	unsigned char* code= (unsigned char *)"01101100";
	unsigned char* clair = (unsigned char *)"";
	unsigned char* sequence = malloc(sizeof(unsigned char *)) ;
	sequence[0] = '\0' ;

	
	//int i = 0 ;
	//parcours_arbre("1",abc,i) ;

	decode(code,clair,abc,sequence);
	free(sequence) ;		
	

	//printf("%s",clair);
	


	/*unsigned char* code2 = malloc(3 * sizeof(unsigned char)) ;
	code2[0] = '1';
	code2[1] = '0';
	code2[2] = '\0'; 

	char app = '1'; 
	code2 = unsigned_append_char(code2, app);
	printf("code = %s ",code2) ;
	
	printf("%s\n", code);
	free(code); */

	return  0;
}