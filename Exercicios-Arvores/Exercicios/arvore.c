#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define NUM_FILHO 0
#define NUM_NO_UM 1
#define NUM_NO_DOIS 2

Arv* arv_criavazia(){return NULL;}

Arv* arv_cria(char valor,Arv* esq,Arv* dir){
	Arv *raiz = (Arv*) malloc(sizeof(Arv));
	raiz->info =valor;
	raiz->esq = esq;
	raiz->dir = dir;	
	return raiz;
}

int arv_vazia(Arv* a){
	return (a == NULL);	
}

//Função para inserir mostrada no slide;
Arv* arv_insere (Arv *a, char c) {
	if (a == NULL) {
		a = (Arv *) malloc(sizeof(Arv));
		a->info = c;
		a->esq = a->dir = NULL;
	}
	else if (a->esq == NULL){
		a->esq = arv_insere (a->esq, c);
	}
	else if (a->dir == NULL){
		a->dir = arv_insere (a->dir, c);
	}
	return a;
}

//Função para inserir mostrada no slide;
Arv* arv_insere_maior_menor (Arv *a, char c) {
	if (a == NULL) {
		a = (Arv *) malloc(sizeof(Arv));
		a->info = c;
		a->esq = a->dir = NULL;
	}
	else if (c >= a->info){
		a->dir = arv_insere_maior_menor (a->dir, c);
	}
	else {
		a->esq = arv_insere_maior_menor (a->esq, c);
	}
	return a;
}

void arv_imprime_preordem(Arv* a){
	if(!arv_vazia(a)){
		printf("%c\t",a->info);
		arv_imprime_preordem(a->esq);
		arv_imprime_preordem(a->dir);
	}
}

void arv_imprime_simetrica(Arv* a){
	if(!arv_vazia(a)){
		arv_imprime_simetrica(a->esq);
		printf("%c\t",a->info);
		arv_imprime_simetrica(a->dir);
	}
}

void arv_imprime_posordem(Arv *a){
	if(!arv_vazia(a)){
		arv_imprime_posordem(a->esq);
		arv_imprime_posordem(a->dir);
		printf("%c\t",a->info);
	}
}

Arv* arv_libera(Arv* a){
	if(!arv_vazia(a)){
		arv_libera(a->esq);
		arv_libera(a->dir);
		free(a);
	}
	return NULL;
}

void arv_conta(Arv* a, int* contagemTotal){
	
	if(!arv_vazia(a)){
		if (a->esq == NULL && a->dir == NULL){

			contagemTotal[NUM_FILHO]++;

		}
		else if (a->esq != NULL && a->dir != NULL){

			contagemTotal[NUM_NO_DOIS]++;

		}
		else if (a->esq != NULL || a->dir != NULL){

			contagemTotal[NUM_NO_UM]++;

		}
		arv_conta(a->esq, contagemTotal);
		arv_conta(a->dir, contagemTotal);
	}
}

/*
void arv_pega_char(Arv* a, char* letraSaida, int comparador){
	
	if(!arv_vazia(a)){
		
		letraSaida[comparador] = a->info;

		comparador++;

		arv_pega_char(a->esq, letraSaida, comparador);
		arv_pega_char(a->dir, letraSaida, comparador);
	}
}

void elementosContaImprime(char* letraSaida, int qtdTotal){

	int comparador;

	for (comparador = 0; comparador < qtdTotal; comparador++){

		if 



	}





}
*/


int arv_pertence(Arv* a,char v){
	if(arv_vazia(a))	return 0;
	else return a->info == v || arv_pertence(a->esq,v) || arv_pertence(a->dir,v);
}

static int max2(int a,int b){
	return (a>b) ? a : b ;
}

int arv_altura(Arv *a){
	if(arv_vazia(a))
		return -1; 
	else 
		return 1 + max2 (arv_altura(a->esq),arv_altura(a->dir));
}

//ARVORE COM FILHOS VARIAVEIS

ArvVar *arvv_cria(int v){
	ArvVar *a = (ArvVar*) malloc (sizeof(ArvVar));
	a->info = v;
	a->filho = NULL;
	a->irmao = NULL;
	return a;
}

void arvv_insere(ArvVar *r,ArvVar *inserido){
	inserido->irmao = r->filho;
	r->filho = inserido;
}

void arvv_imprime(ArvVar *a){
	ArvVar *p;
	printf("%i\t",a->info);
	for(p=a->filho;p!=NULL;p=p->irmao)
		arvv_imprime(p);
}

int arvv_pertence(ArvVar *a,int v){
	ArvVar *p;
	if(a->info ==v)
		return 1;
	else{
		for(p=a->filho;p!=NULL;p=p->irmao){
			if(arvv_pertence(p,v))
			return 1;
		}
		return 0;
	}
}

void arvv_libera(ArvVar *a){
	ArvVar *p = a->filho;
	while(p!=NULL){
		ArvVar *t = p->irmao;
		arvv_libera(p);
		p=t;
	}
	free(a);
}

int arvv_altura(ArvVar *a){
	int hmax = -1;
	ArvVar *p;

	for(p=a->filho;p!=NULL;p=p->irmao){
		int h = arvv_altura(p);
		if(h>hmax) hmax = h;
	}
	return hmax +1;
}

