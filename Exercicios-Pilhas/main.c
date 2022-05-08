//Exercício de Pilhas

#include <stdio.h>
#include <locale.h>
#include "pilhas.h"
#define SUCESSO 0
#define ERRO 1
#define ABRE '('
#define FECHA ')'
#define FALSO 1
#define VALOR1 'a'
#define VALOR2 'b'

void pilhaPushInverso(Pilha_vet *pilha, char parentese){

	switch(parentese){
	case FECHA:
		
		parentese = ABRE;
		pilha_vet_push(pilha, parentese);
		break;

	case ABRE:
		
		parentese = FECHA;
		pilha_vet_push(pilha, parentese);
		break;

	} 

}

Pilha_vet* pilhaCopia(Pilha_vet *pilhaOrigem, Pilha_vet *pilhaDestino, int qtdElementos){

	Pilha_vet *pilhaIntermediaria;
	int comparador;
	char elemento, inimportante;

	pilhaIntermediaria = pilha_vet_cria();

	while (!pilha_vet_vazia(pilhaDestino)){

		inimportante = pilha_vet_pop(pilhaDestino);

	}

	for (comparador = 0; comparador < qtdElementos; comparador++){

		elemento = pilha_vet_pop(pilhaOrigem);
		pilha_vet_push(pilhaIntermediaria, elemento);
	
	}
	
	for (comparador = 0; comparador < qtdElementos; comparador++){

		elemento = pilha_vet_pop(pilhaIntermediaria);
		pilha_vet_push(pilhaDestino, elemento);
	
	}


	pilha_vet_libera(pilhaIntermediaria);
	return pilhaDestino;
}


int main(int argc, char** argv){
	
	setlocale(LC_ALL, "");

	Pilha_vet *pilhaParenteses, *pilhaParentesesCopia, *pilhaParentesesCompara;
	Pilha_vet *pilhaParentesesCompara2;
	int qtdElementos, comparador, jaFechou, qtdVezesTirado, comparador2, qtdElementosRemov, comparador3;
	char parentese, parentese2, parenteseComp1, parenteseComp2, parentese3;

	jaFechou = FALSO;
	parenteseComp1 = VALOR1;
	parenteseComp2= VALOR2;
	qtdVezesTirado = 0;
	qtdElementosRemov = 0;

	pilhaParenteses = pilha_vet_cria();
	pilhaParentesesCopia = pilha_vet_cria();

	printf("Digite a quantidade de elementos que terão em sua pilha: ");
	scanf(" %d", &qtdElementos);

	if (qtdElementos % 2 != 0){

		printf("Não é possível ter uma sequência de parênteses bem formada\n");

		pilha_vet_libera(pilhaParenteses);
		pilha_vet_libera(pilhaParentesesCopia);
		return SUCESSO;

	}
	
	for(comparador = 0; comparador < qtdElementos; comparador++){

		printf("Digite o %dº parêntese: ", comparador + 1);
		scanf(" %c", &parentese);

		if (comparador == 0 && parentese == FECHA){

			printf("A sequência de parênteses está mal formada!\n");

			pilha_vet_libera(pilhaParenteses);
			pilha_vet_libera(pilhaParentesesCopia);
			return SUCESSO;

		}
		else if (comparador == qtdElementos - 1 && parentese == ABRE){
			
			printf("A sequência de parênteses está mal formada!\n");

			pilha_vet_libera(pilhaParenteses);
			pilha_vet_libera(pilhaParentesesCopia);
			return SUCESSO;
			
		}



		if (parentese != ABRE && parentese != FECHA){

			fputs("\nERRO: O caractére digitado não é um parêntese.\n", stderr);
			
			pilha_vet_libera(pilhaParenteses);
			pilha_vet_libera(pilhaParentesesCopia);

			return ERRO;

		}

		pilha_vet_push(pilhaParenteses, parentese);
		pilha_vet_push(pilhaParentesesCopia, parentese);

	}

	
	pilhaParentesesCompara = pilha_vet_cria();
	pilhaParentesesCompara2 = pilha_vet_cria();


	for(comparador = 0; comparador < qtdElementos; comparador++){

		parentese2 = pilha_vet_pop(pilhaParentesesCopia);

		if (parentese2 == FECHA && jaFechou == FALSO){

			jaFechou != FALSO;

		}
		else if (parentese2 == ABRE && jaFechou == FALSO){

			pilha_vet_push(pilhaParentesesCompara, parentese2);
			qtdVezesTirado++;

		}
		else{

			pilhaPushInverso(pilhaParentesesCompara, parentese2);			

		}

	}




	for(comparador = 0; comparador < qtdElementos; comparador++){

		if (parenteseComp1 != parenteseComp2){

			if (pilha_vet_vazia(pilhaParenteses) || pilha_vet_vazia(pilhaParentesesCompara) || pilha_vet_vazia(pilhaParentesesCompara2)){

				printf("A sequência de parênteses está bem formada!\n");
				pilha_vet_libera(pilhaParenteses);
				pilha_vet_libera(pilhaParentesesCopia);
				pilha_vet_libera(pilhaParentesesCompara);
				pilha_vet_libera(pilhaParentesesCompara2);
				return SUCESSO;

			}

			parenteseComp1 = pilha_vet_pop(pilhaParenteses);
			parenteseComp2 = pilha_vet_pop(pilhaParentesesCompara);
			qtdElementosRemov++;

		}
		else if (parenteseComp1 == parenteseComp2 && qtdVezesTirado <= qtdElementos){

			pilha_vet_push(pilhaParentesesCompara2, parenteseComp2);
			qtdVezesTirado++;

			for (comparador2 = 0; comparador2 < (qtdElementos - qtdElementosRemov); comparador2++){

				parentese3 = pilha_vet_pop(pilhaParentesesCompara);
				pilhaPushInverso(pilhaParentesesCompara2, parentese3);

			}

			pilhaParentesesCompara = pilhaCopia(pilhaParentesesCompara2, pilhaParentesesCompara, (qtdElementos - qtdElementosRemov));

		}

	}
		
	
	printf("A sequência de parênteses está mal formada!\n");


	pilha_vet_libera(pilhaParenteses);
	pilha_vet_libera(pilhaParentesesCopia);
	pilha_vet_libera(pilhaParentesesCompara);
	return SUCESSO;
}