//Exercício de Listas

#include <stdio.h>
#include <locale.h>//Biblioteca para fazer acentos aparecerem
#include <stdlib.h>
#include "listas.h"
#define SUCESSO 0
#define ERRO 1

int comparaLista(Lista* lista1, Lista* lista2) {

	setlocale(LC_ALL, "");

	Lista* posicao1, * posicao2;

	int tamanhoLista1, tamanhoLista2, comparacao;


	tamanhoLista1 = 0;
	tamanhoLista2 = 0;
	comparacao = 0;


	for (posicao1 = lista1; posicao1 != NULL; posicao1 = posicao1->prox) {

		tamanhoLista1++;

	}

	for (posicao2 = lista2; posicao2 != NULL; posicao2 = posicao2->prox) {

		tamanhoLista2++;

	}

	if (tamanhoLista1 != tamanhoLista2) {

		return ERRO;//Retorna que as listas não são iguais

	}
	else {

		posicao2 = lista2;

		for (posicao1 = lista1; posicao1 != NULL; posicao1 = posicao1->prox) {

			if (posicao1->info != posicao2->info) {

				return ERRO;//Retorna que as listas não são iguais

			}

			posicao2 = posicao2->prox;
			
		}

		return SUCESSO;//Retorna que as listas são iguais

	}

}

Lista* listaCircRemove(Lista* listaJosephus, int posicaoRemove){

	Lista* lista2;
	
	lista2 = listaJosephus;

	while((lista2->prox)->info != listaJosephus->info){

		lista2 = lista2->prox;

	}
	
	lista2->prox = NULL;

	
	lista2 = lst_retira(lista2, posicaoRemove);

	lista2 = lcirc_transforma(lista2);

	
	return lista2;

}

Lista* problemaJosephus(Lista* listaJosephus, int qtdNumPula){

	Lista* posicao;

	int posicaoRemove, comparador;

	comparador = 0;

	for (posicao = listaJosephus; posicao->prox != posicao; posicao = posicao->prox){

		comparador++;
		printf("\n%d\n", comparador);//TESTE

		if (comparador == qtdNumPula){
			
			posicaoRemove = posicao->info;
			
			printf("%d", posicao->info);//TESTE
	
			listaJosephus = listaCircRemove(listaJosephus, posicaoRemove);

			comparador = 0;


		}


	}

	return listaJosephus;
}

int main(int argc, char** argv) {


	setlocale(LC_ALL, "");
		
	Lista* lista1, *lista2, *listaJosephus; 
	int qtdLista1, qtdLista2, qtdJosephus, qtdNumPula, numeroUser, comparador, retornoCompListas, escolhaExercicio;

	printf("Digite qual exercício deseja escolher:\n\n1 - Comparação Listas\n2 - Problema de Josephus\n\nSelecionar: ");
	scanf(" %d", &escolhaExercicio);

	switch(escolhaExercicio){

	case 1:
	
		lista1 = lst_cria();
		lista2 = lst_cria();
	
		printf("Digite quantos números deseja em sua primeira lista: ");
		scanf(" %d", &qtdLista1);

		for (comparador = 0; comparador < qtdLista1; comparador++) {
	
			printf("Digite o valor do %dº número: ", comparador + 1);
			scanf(" %d", &numeroUser);
	
			lista1 = lst_insere(lista1, numeroUser);

		}	

		printf("Digite quantos números deseja em sua segunda lista: ");
		scanf(" %d", &qtdLista2);

		for (comparador = 0; comparador < qtdLista2; comparador++) {

			printf("Digite o valor do %dº número: ", comparador + 1);
			scanf(" %d", &numeroUser);

			lista2 = lst_insere(lista2, numeroUser);

		}
	
		retornoCompListas = comparaLista(lista1, lista2);

		if (retornoCompListas == SUCESSO) {
		
		printf("Ambas as listas digitadas são iguais!\n");

		}
		else if (retornoCompListas == ERRO) {

			printf("As listas digitadas são diferentes!\n");

		}


		lst_libera(lista1);
		lst_libera(lista2);
		break;
	

	case 2:
		
		listaJosephus = lst_cria();

		printf("Digite quantas a quantidade de pessoas de seu problema de Josephus: ");
		scanf(" %d", &qtdJosephus);

		for (comparador = qtdJosephus; comparador >= 1; comparador--){

			listaJosephus = lst_insere(listaJosephus, comparador);

			
		}

		
		printf("Digite a posição cuja pessoa morrerá (ex: a 3ª pessoa a partir do anterior morrerá): ");
		scanf(" %d", &qtdNumPula);


		listaJosephus = lcirc_transforma(listaJosephus);

		
		//for(listaJosephus = listaJosephus; listaJosephus->prox != NULL; listaJosephus = listaJosephus){

		listaJosephus = problemaJosephus(listaJosephus, qtdNumPula);

		 
	
		
		lcirc_libera(listaJosephus);
		break;


	default:
		printf("Houve um erro\n");
	}

	



	return SUCESSO;
}
