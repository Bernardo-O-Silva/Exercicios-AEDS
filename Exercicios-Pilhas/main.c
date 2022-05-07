#include <stdio.h>
#include <locale.h>
#include "pilhas.h"
#define SUCESSO 0

int main(int argc, char** argv){
	
	setlocale(LC_ALL, "");

	Pilha_vet *pilhaParenteses;
	int qtdElementos, comparador, qtdEsquerdo, qtdDireito, qtdNenhum, errado;
	char parentese;

	qtdEsquerdo = 0;
	qtdDireito = 0;
	qtdNenhum = 0;
	errado = 0;

	pilhaParenteses = pilha_vet_cria();

	printf("Digite a quantidade de elementos que terão em sua pilha: ");
	scanf(" %d", &qtdElementos);
	
	for(comparador = 0; comparador < qtdElementos; comparador++){

		printf("Digite o %dº parêntese: ", comparador + 1);
		scanf(" %c", &parentese);

		pilha_vet_push(pilhaParenteses, parentese);

		if (comparador == 0 && parentese == ')'){
			
			errado++;

		}

		if (comparador == (qtdElementos - 1) && parentese == '('){

			errado++;

		}

	}
	
	if (qtdElementos % 2 != 0){

		printf("A sequência de parênteses não está bem formada!\n");

	}
	else if (errado != 0){

		printf("A sequência de parênteses não está bem formada!\n");
		
	}
	else {

		for(comparador = 0; comparador < qtdElementos; comparador++){

			parentese = pilha_vet_pop(pilhaParenteses);
			
			switch(parentese){
			case '(':
				qtdEsquerdo++;
				break;
			case ')':
				qtdDireito++;
				break;
			default:
				qtdNenhum++;
				break;

			}
		}
		
		if (qtdNenhum != 0){

			printf("ERRO: Há algum elemento que não é um parêntese, tente novamente.\n");

		}
		else if (qtdDireito == qtdEsquerdo){
			
			printf("A sequência de parênteses está bem formada!\n");

		}
		else if (qtdDireito != qtdEsquerdo){

			printf("A sequência de parênteses não está bem formada!\n");

		}
		

	}
	

	return SUCESSO;
}
