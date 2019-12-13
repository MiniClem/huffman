#include <string.h>
#include "../include/decodage.h"
#include <assert.h>
#include "../include/encodage.h" 
#include "../include/file.h"


Arbre lire_dico(unsigned char* code , int * ind){
	Arbre a = NULL;
	Arbre fg , fd;
	char c = code[*ind];
	if(c == '0'){
		(*ind)+=1;
		fg = lire_dico(code,ind);
		(*ind)+=1;
		fd = lire_dico(code, ind);
		return creer_arbre('\0',0,fg,fd);
	}else if (c == '1'){
		(*ind)+=1;
		a = creer_arbre(lire_ascii((unsigned char*)code + (*ind)),0,NULL,NULL);
		(*ind)+=7;
		return a ;
	}else{
		return NULL;
	}

}


Elt lire_ascii(unsigned char* octet)
{
	
	int valeur =0;
	int i ; 
	for(i=7; i>=0;i--){
		if (octet[7-i]=='1'){
			valeur += pow(2,i);
		}
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
		printf("%c\n",c);
		if(c != 0){
			clair = unsigned_append_char(clair,c);
			free(sequence) ;
			sequence=malloc(sizeof(unsigned char *)) ;
			sequence[0]='\0' ;
		}
		code++;
	}
	printf("%s", clair);
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

unsigned char* unsigned_append_char(unsigned char* out_c, unsigned char app){
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



void decompressage( char* filename){
	
	unsigned char* fichier = byte_to_char(lire_caractere_fichier(filename));
	int ind = 0;
	Arbre a = lire_dico(fichier,&ind);
	
	unsigned char * clair = malloc(sizeof(unsigned char *));
	clair[0] = '\0' ;
	
	unsigned char* sequence = malloc(sizeof(unsigned char *)) ;
	sequence[0] = '\0'; 
	
	unsigned char* decompresse = decode(fichier,clair,a,sequence);
	
	free(clair);
	free(sequence);
	
	strcat(filename, ".txt") ;
	
	printf("filename : %s \n", decompresse) ;
	
	ecrire_caractere_fichier(filename, decompresse, strlen(decompresse)) ;
	

}

// TESTS
int main(){
	//unsigned char* code = (unsigned char *)"0010110000110110001001011000110101100100101100101"; //aaaabbbccde
	//int ind = 0;


	
	//Arbre a = creer_arbre('a',0,NULL,NULL);
	//Arbre b = creer_arbre('b',0,NULL,NULL);
	//Arbre ab = creer_arbre('0',0,a,b);
	//Arbre c = creer_arbre('c',0,NULL,NULL);
	//Arbre abc = creer_arbre('0',0,ab,c);
	//
	//unsigned char* code= (unsigned char *)"01101100"; // bcbca
	//unsigned char* clair = malloc(sizeof(unsigned char *));
	//clair[0] = '\0' ;
	//unsigned char* sequence = malloc(sizeof(unsigned char *)) ;
	//sequence[0] = '\0' ;
	
	//int i = 0 ;
	//parcours_arbre("1",abc,i) ;

	//decode(code,clair,abc,sequence);
	//free(sequence) ;		
	
	/*	
	Arbre a = lire_dico(code,&ind);
	unsigned char * clair = malloc(sizeof(unsigned char *));
	clair[0] = '\0' ;
	unsigned char* zgueg= (unsigned char*)"000000000101011010110111";
	unsigned char* sequence = malloc(sizeof(unsigned char *)) ;
	sequence[0] = '\0'; 
	
	decode(zgueg,clair,a,sequence);
	


	unsigned char* code2 = malloc(3 * sizeof(unsigned char)) ;
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