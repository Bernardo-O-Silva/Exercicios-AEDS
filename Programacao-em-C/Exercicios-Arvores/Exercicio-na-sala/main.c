#include <stdio.h>
#include "arvore.h"
#define SUCESSO 0

void arv_imprime_simetricaB(Arv* a){
	if(!arv_vazia(a)){
		arv_imprime_simetricaB(a->esq);
        printf("%c\t",a->info);
		arv_imprime_simetricaB(a->dir);
	}
}
void arv_imprime_posordemB(Arv* a){
	if(!arv_vazia(a)){
		arv_imprime_posordemB(a->esq);
		arv_imprime_posordemB(a->dir);
        printf("%c\t",a->info);
	}
}

int main(int argc, char** argv){


    printf("\nPROGRAMMING\n\n");


    return SUCESSO;
}