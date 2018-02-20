#include <stdio.h>
#include <stdlib.h>

#include "lista.h"


Lista * novi(int x){
	Lista * novi = malloc(sizeof(Lista));
	if(novi == NULL)
		yyerror("Malloc error");
	
	novi->element = x;
	novi->sledeci = NULL;
	
	return novi;
}

void Stampaj(Lista* l){
	for(; l!=NULL; l = l->sledeci){
		printf("%d",l->element);
		if(l->sledeci !=NULL)
			printf(", ");
	}
}

void Dodaj(Lista** lp, int b){
	Lista * tmp = novi(b);
	
	if(*lp == NULL || b<(*lp)->element){
		tmp->sledeci = *lp;
		*lp=tmp;
		return;
	}
	if( b == (*lp)->element)
		return;
	
	Dodaj(&((*lp)->sledeci),b);
}

void ObrisiListu(Lista** lp){
		if(*lp ==NULL)
		return;
	
	ObrisiListu(&(*lp)->sledeci);
	
	free(*lp);
}


Lista* KopijaListe(Lista*l){
	Lista * kopija =NULL;
	Lista* tmp =NULL;
	
	if(l!=NULL)
		kopija = novi(l->element);
	else return kopija;
	
	for(tmp = kopija, l= l->sledeci ; l!=NULL; l= l->sledeci, tmp= tmp->sledeci )
	 tmp->sledeci = novi(l->element);
	 
	return kopija;
}


Lista* Pronadji(Lista* l, int e){
	for(; l!=NULL; l= l->sledeci)
		if(l->element == e) 
			return l;
	
		return NULL;
}

void ObrisiElement(Lista** lp, int e){
	Lista* tekuci= *lp, *tmp;
	
	if(tekuci->element == e){
		tmp = *lp;
		*lp = tekuci->sledeci;
		free(tmp);
		return;
	}
	ObrisiElement(&(*lp)->sledeci,e);
	
}

int BrojElemenata(Lista* l){
	int count =0;
	
	for( ; l!=NULL; l=l->sledeci) count++;
	
	return count;
}